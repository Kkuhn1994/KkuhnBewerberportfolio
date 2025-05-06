/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:14:50 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:59:02 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static void	check_shade_hit(t_all_intersec intersections, bool *shadow_flag,
		double distance, t_shape shape)
{
	t_xyzvektor	hit_intersection;

	hit_intersection = set_vector(0, 0, 0, 0);
	if (intersections.intersections != NULL)
		hit_intersection = hit(intersections, shape, -1, -1);
	else
		hit_intersection.w = INFINITY;
	hit_intersection = hit(intersections, shape, -1, -1);
	if (hit_intersection.w > EPSILON && hit_intersection.w < distance)
		*shadow_flag = true;
	else
		*shadow_flag = false;
}

bool	*is_shadowed(t_world *world, t_xyzvektor point, t_shape shape)
{
	t_ray		ray;
	t_xyzvektor	v;
	double		distance;
	int			i;
	bool		*shadows;

	i = -1;
	shadows = ft_malloc(world->canvas->num_lights * sizeof(bool));
	ray = init_ray();
	ray.origin = point;
	v = set_vector(0, 0, 0, 0);
	while (++i < world->canvas->num_lights)
	{
		v = substraction(world->canvas->lightsource[i].position, point);
		distance = magnitude(v);
		ray.direction = normalize(v);
		empty_intersections(world->canvas);
		intersect_world(world, ray);
		check_shade_hit(world->canvas->all_intersections, &shadows[i],
			distance, shape);
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
	retvalue = lightning(comp, local_canvas, in_shadow, world);
	return (retvalue);
}
