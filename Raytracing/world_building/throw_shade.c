/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:14:50 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 12:30:47 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	check_shade_hit(t_world *world, bool *shadows, double distance, int i, t_shape *shape)
{
	t_xyzvektor	hit_intersection;

	if (world->canvas->all_intersections.intersections != NULL)
		hit_intersection = hit(world->canvas->all_intersections, shape);
	else
		hit_intersection.w = INFINITY;
	if (hit_intersection.w > EPSILON && hit_intersection.w < distance)
		shadows[i] = true;
	else
		shadows[i] = false;
}

bool	*is_shadowed(t_world *world, t_xyzvektor point, t_shape shape)
{
	t_ray		ray;
	t_xyzvektor	v;
	double		distance;
	int			i;
	bool		*shadows;

	i = -1;
	shadows = MALLOC(world->canvas->num_lights * sizeof(bool));
	ray = init_ray();
	ray.origin = point;
	while (++i < world->canvas->num_lights)
	{
		v = substraction(world->canvas->lightsource[i].position, point);
		distance = magnitude(v);
		ray.direction = normalize(v);
		sphere_ray_transform(shape, ray);
		empty_intersections(world->canvas);
		intersect_world(world, ray);
		check_shade_hit(world, shadows, distance, i, &shape);
	}
	empty_intersections(world->canvas);
	return (shadows);
}

t_xyzvektor	shade_hit(t_world *world, t_comp comp, t_shape shape)
{
	t_xyzvektor	retvalue;
	t_c			local_canvas;
	bool		*in_shadow;

	local_canvas = *(world->canvas);
	local_canvas.normale = comp.normalv;
	local_canvas.eyevector = comp.eyev;
	in_shadow = is_shadowed(world, comp.over_point, shape);
	empty_intersections(world->canvas);
	retvalue = lightning(comp, local_canvas,
			in_shadow);
	return (retvalue);
}
