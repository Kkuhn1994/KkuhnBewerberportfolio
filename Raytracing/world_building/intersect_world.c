/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:20:42 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 17:12:58 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "../miniRT.h"

void	find_nearest_intersection(t_intersec *intersections,
		int nr_intersections, t_intersec **intersec_to_use, int *shape_to_use)
{
	int	i;

	i = 0;
	while (i < nr_intersections)
	{
		if (intersections[i].times[0] > 0)
		{
			if (!*intersec_to_use)
			{
				*intersec_to_use = &intersections[i];
				*shape_to_use = intersections[i].object_id;
			}
			else if (intersections[i].times[0] < (*intersec_to_use)->times[0])
			{
				*intersec_to_use = &intersections[i];
				*shape_to_use = intersections[i].object_id;
			}
		}
		i++;
	}
}

t_xyzvektor	color_at(t_world *world, t_ray ray)
{
	t_comp		comp;
	t_intersec	*intersec_to_use;
	int			shape_to_use;

	if (world->canvas->all_intersections.intersections)
	{
		world->canvas->all_intersections.intersections = NULL;
		world->canvas->all_intersections.nr_intersections = 0;
	}
	world->canvas->all_intersections.nr_intersection_entries = 0;
	intersec_to_use = NULL;
	shape_to_use = 0;
	intersect_world(world, ray);
	if (world->canvas->all_intersections.nr_intersections == 0)
		return (set_black());
	find_nearest_intersection(world->canvas->all_intersections.intersections,
		world->canvas->all_intersections.nr_intersection_entries,
		&intersec_to_use, &shape_to_use);
	if (!intersec_to_use)
		return (set_black());
	comp = prepare_computations(intersec_to_use, ray,
			(world->shapes[shape_to_use]), world);
	empty_intersections(world->canvas);
	return (shade_hit(world, comp, *(world->shapes[shape_to_use])));
}

static void	save_intersections(t_c *canvas, t_intersec *new_intersection,
		t_world *world)
{
	int		i;
	double	*new_times;

	i = 0;
	if (canvas->all_intersections.nr_intersections == 0)
	{
		canvas->all_intersections.intersections = MALLOC(sizeof(t_intersec));
		if (!canvas->all_intersections.intersections)
			exit(1);
	}
	else
	{
		canvas->all_intersections.intersections = rt_realloc(canvas->all_intersections.intersections,
				sizeof(t_intersec)
				* (canvas->all_intersections.nr_intersection_entries + 1));
		if (!canvas->all_intersections.intersections)
			exit(1);
	}
	canvas->all_intersections.intersections[canvas->all_intersections.nr_intersection_entries] = *new_intersection;
	new_times = MALLOC(2 * sizeof(double));
	if (!new_times)
		exit(1);
	new_times[0] = new_intersection->times[0];
	new_times[1] = new_intersection->times[1];
	FREE(new_intersection->times);
	canvas->all_intersections.intersections[canvas->all_intersections.nr_intersection_entries].times = new_times;
	canvas->all_intersections.nr_intersection_entries++;
	while (i != 2)
	{
		if (canvas->all_intersections.nr_intersections % 100 >= 90)
		{
			world->all_sorted = realloc(world->all_sorted, sizeof(double *)
					* (world->canvas->all_intersections.nr_intersections
						+ 110));
			if (!world->all_sorted)
				exit(1);
		}
		world->all_sorted[world->canvas->all_intersections.nr_intersections
			+ i] = new_times[i];
		i++;
	}
	canvas->all_intersections.nr_intersections += i;
	FREE(new_intersection);
}

static void	sort_intersections(double *all_sorted)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (all_sorted[i] != 0)
	{
		j = i + 1;
		while (all_sorted[j] != 0)
		{
			if (all_sorted[i] > all_sorted[j])
			{
				temp = all_sorted[i];
				all_sorted[i] = all_sorted[j];
				all_sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	uv_of_sphere(t_intersec *intersect, t_comp *comps, t_shape *shape, t_world world)
{
	t_xyzvektor	relative_point;
	double		theta;
	double		phi;
	int width = world.canvas->bumpmapcolor->width;
	int height = world.canvas->bumpmapcolor->height;

	relative_point = substraction(comps->point, shape->origin);
    theta = atan2(relative_point.z, relative_point.x);  // Azimutalwinkel (von x und z)
    phi = asin(relative_point.y / shape->radius);  
    // Normalisiere den Azimutalwinkel auf [0, 1]
    intersect->u = (theta + M_PI) / (2 * M_PI);  // Normalisiere theta von [-π, π] auf [0, 1]
    intersect->v = 0.5 - phi / M_PI;             // Normalisiere phi von [-π/2, π/2] auf [0, 1]

    intersect->u = (int)(intersect->u * 4096) % 4096;
    intersect->v = (int)(intersect->v * 4096) % 4096;
	comps->u = intersect->u;
	comps->v = intersect->v;
}

void orthogonale_vektoren(t_xyzvektor x, t_xyzvektor *y, t_xyzvektor *z) {
    // Überprüfen, ob x der Nullvektor ist
    if (x.x == 0 && x.y == 0 && x.z == 0) {
        printf("Fehler: Der Vektor x darf nicht der Nullvektor sein.\n");
        return;
    }
    
    // Berechnung des ersten orthogonalen Vektors y
    if (x.x != 0 || x.y != 0) {
        y->x = -x.y;
        y->y = x.x;
        y->z = 0;
    } else {
        // Wenn x = [0, 0, z] ist, dann setze y = [0, z, -y]
        y->x = 0;
        y->y = x.z;
        y->z = -x.y;
    }

    // Berechnung des zweiten orthogonalen Vektors z
    // Wir können z einfach als Kreuzprodukt von x und y berechnen.
    z->x = x.y * y->z - x.z * y->y;
    z->y = x.z * y->x - x.x * y->z;
    z->z = x.x * y->y - x.y * y->x;
}

void change_normal_for_bump(t_comp *comp, t_intersec *intersection, t_ray ray, t_world *world)
{
	t_xyzvektor a;
	t_xyzvektor b;

	orthogonale_vektoren(comp->normalv, &a, &b);
	int x = (int)((intersection->u) * world->canvas->bumpmap->width) % world->canvas->bumpmap->width;
    int y = (int)(intersection->v * world->canvas->bumpmap->height) % world->canvas->bumpmap->height;

	float center = get_bumpmap_grayscale(world->canvas->bumpmap, x, y) / 255.0f;
    float left = get_bumpmap_grayscale(world->canvas->bumpmap, (x-1+world->canvas->bumpmap->width) % world->canvas->bumpmap->width, y) / 255.0f;
    float right = get_bumpmap_grayscale(world->canvas->bumpmap, (x+1) % world->canvas->bumpmap->width, y) / 255.0f;
    float top = get_bumpmap_grayscale(world->canvas->bumpmap, x, (y-1+world->canvas->bumpmap->height) % world->canvas->bumpmap->height) / 255.0f;
    float bottom = get_bumpmap_grayscale(world->canvas->bumpmap, x, (y+1) % world->canvas->bumpmap->height) / 255.0f;
	
	float strength = 1;
    float dx = (right - left) * strength;
    float dy = (bottom - top) * strength;
    t_xyzvektor tangent_x = cross_product(a, comp->normalv);
    if (magnitude(tangent_x) < 0.01f)
        tangent_x = cross_product(b, comp->normalv);
    tangent_x = normalize(tangent_x);
    t_xyzvektor tangent_y = cross_product(comp->normalv, tangent_x);
    tangent_y = normalize(tangent_y);
    t_xyzvektor bump_normal = substraction(comp->normalv, addition(scalar_multiplication(tangent_x, dx),
	scalar_multiplication(tangent_y, dy)));
    comp->normalv = normalize(bump_normal);
}

void uv_of_plane(t_intersec *intersect, t_comp comps, t_shape *plane) {
    // Tangentenvektor (Richtung der u-Koordinate)
    t_xyzvektor tangent = {1, 0, 0}; // Standard: X-Achse
    // Bitangent (Richtung der v-Koordinate)
    t_xyzvektor bitangent = {0, 0, 1}; // Standard: Z-Achse

    // Falls die Ebene rotiert ist: Transformiere tangent/bitangent mit der Rotationsmatrix
    // (Hier müsste plane->rotation_matrix oder ähnliches verwendet werden)

    // Berechne u und v als Projektion auf tangent/bitangent
    t_xyzvektor relative_point = substraction(comps.point, plane->origin);
    double u = dot_product(relative_point, tangent);
    double v = dot_product(relative_point, bitangent);

    // Skalierung und Wrapping (optional)
    double scale = 1.0;
    u = fmod(u * scale, 1.0);
    v = fmod(v * scale, 1.0);
    if (u < 0) u += 1.0;
    if (v < 0) v += 1.0;

    intersect->u = u;
    intersect->v = v;
}

t_comp	prepare_computations(t_intersec *intersection, t_ray ray,
	t_shape *shape, t_world *world)
{
t_comp	comps;

comps.t = intersection->times[0];
comps.object = shape;
comps.point = point_of_intersection(intersection, ray);

comps.eyev = negate_tuple(ray.direction);
if(world->canvas->bumpmapcolor)
	uv_of_sphere(intersection, &comps, shape, *world);
// uv_of_plane(intersection, comps, shape);
comps.normalv = calculate_normale(*shape, comps.point);

if(world->canvas->bumpmap != 0)
	change_normal_for_bump(&comps, intersection, ray, world);
comps.over_point = set_vector(comps.point.x + comps.normalv.x * EPSILON,
		comps.point.y + comps.normalv.y * EPSILON, comps.point.z
		+ comps.normalv.z * EPSILON, 1);
if (dot_product(comps.normalv, comps.eyev) < 0)
{
	comps.inside = true;
	comps.normalv = negate_tuple(comps.normalv);
}
else
	comps.inside = false;
return (comps);
}

int	intersect_world(t_world *world, t_ray ray)
{
	t_intersec	*new_intersection;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (world->nr_shapes > i)
	{
		new_intersection = intersect(world->shapes[i], ray);
		if (new_intersection)
			save_intersections(world->canvas, new_intersection, world);
		i++;
	}
	sort_intersections(world->all_sorted);
	return (0);
}
