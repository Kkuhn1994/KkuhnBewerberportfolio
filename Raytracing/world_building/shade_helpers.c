/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:43:26 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/04 16:13:55 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	empty_intersections(t_c *canvas)
{
	int	i;

	i = 0;
	if (canvas->all_intersections.intersections)
	{
		while (i < canvas->all_intersections.nr_intersection_entries)
			FREE(canvas->all_intersections.intersections[i++].times);
		FREE(canvas->all_intersections.intersections);
		canvas->all_intersections.nr_intersection_entries = 0;
		canvas->all_intersections.nr_intersections = 0;
	}
	canvas->all_intersections.intersections = NULL;
}

static t_xyzvektor	calculate_hit_point(t_intersec intersection, double time)
{
	t_xyzvektor	result;

	result = addition(intersection.ray.origin,
			scalar_multiplication(intersection.ray.direction, time));
	result.w = time;
	return (result);
}

t_xyzvektor	hit(t_all_intersec all_intersections, t_shape *shape)
{
	t_xyzvektor	hit_intersection;
	double		t0;
	double		t1;
	int			i;

	i = -1;
	hit_intersection = set_vector(0, 0, 0, 0);
	while (++ i <= all_intersections.nr_intersections / 2 - 1)
	{
		if(all_intersections.intersections[i].object_id == shape->id)
			continue;
		t0 = all_intersections.intersections[i].times[0];
		t1 = all_intersections.intersections[i].times[1];
		if (t0 > 0 && t0 < t1)
		{
			hit_intersection = calculate_hit_point(all_intersections.intersections[i],
					t0);
			if (t0 < 0 || t0 > t1)
			{
				hit_intersection = calculate_hit_point(all_intersections.intersections[i],
						t1);
			}
			return (hit_intersection);
		}
	}
	return (hit_intersection);
}

void	sphere_ray_transform(t_shape shape, t_ray ray)
{
	double	**inverse_transform;

	if (shape.type != 0)
	{
		inverse_transform = invert_matrix(shape.default_transformation, 4);
		transform_ray(&ray, inverse_transform);
	}
}
