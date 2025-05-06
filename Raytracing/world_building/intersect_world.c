/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:20:42 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 21:36:39 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "world.h"

static void	update_closest(t_intersec **current, int *shape_id,
		t_intersec *candidate)
{
	if (!*current || candidate->times[0] < (*current)->times[0]
		|| (candidate->times[0] == (*current)->times[0]
			&& candidate->object_id < (*current)->object_id))
	{
		*current = candidate;
		*shape_id = candidate->object_id;
	}
}

void	find_nearest_intersection(t_intersec *intersections,
		int nr_intersections, t_intersec **intersec_to_use, int *shape_to_use)
{
	int	i;

	i = -1;
	while (++i < nr_intersections)
		if (intersections[i].times && (intersections[i].times[0] > 0
				|| intersections[i].times[1] > 0))
			update_closest(intersec_to_use, shape_to_use, &intersections[i]);
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
			if (all_sorted[i] > all_sorted[j] && all_sorted[j] > 0)
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

t_comp	prepare_computations(t_intersec *intersection, t_ray ray,
		t_shape *shape, t_world *world)
{
	t_comp	comps;

	comps.t = intersection->times[0];
	comps.object = shape;
	comps.point = point_of_intersection(intersection, ray);
	comps.eyev = negate_tuple(ray.direction);
	if (world->canvas->bumpmapcolor)
		uv_of_sphere(intersection, &comps, shape, *world);
	comps.normalv = calculate_normale(*shape, comps.point);
	if (world->canvas->bumpmap != 0)
		change_normal_for_bump(&comps, intersection, world);
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
	double		temp;

	i = 0;
	while (world->nr_shapes > i)
	{
		new_intersection = intersect(world->shapes[i], ray);
		if (new_intersection)
		{
			if (new_intersection->times[0] < 0
				&& new_intersection->times[1] > 0)
			{
				temp = new_intersection->times[0];
				new_intersection->times[0] = new_intersection->times[1];
				new_intersection->times[1] = temp;
			}
			save_intersections(world->canvas, new_intersection, world);
		}
		i++;
	}
	sort_intersections(world->all_sorted);
	return (0);
}
