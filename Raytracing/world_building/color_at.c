/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:36:31 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 21:36:47 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

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
