/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:43:26 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 12:47:55 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	sphere_ray_transform(t_shape shape, t_ray ray)
{
	double	**inverse_transform;

	if (shape.type != 0)
	{
		inverse_transform = invert_matrix(shape.default_transformation, 4);
		transform_ray(&ray, inverse_transform);
	}
}

void	empty_intersections(t_c *canvas)
{
	size_t	i;

	i = 0;
	if (canvas->all_intersections.intersections)
	{
		while (i < canvas->all_intersections.nr_intersection_entries)
			ft_free(canvas->all_intersections.intersections[i++].times);
		ft_free(canvas->all_intersections.intersections);
		canvas->all_intersections.nr_intersection_entries = 0;
		canvas->all_intersections.nr_intersections = 0;
	}
	canvas->all_intersections.intersections = NULL;
	canvas->all_intersections.allocated_intersections = 0;
}

static t_xyzvektor	calc_hit_point(t_intersec intersection, double time)
{
	t_xyzvektor	result;

	result = addition(intersection.ray.origin,
			scalar_multiplication(intersection.ray.direction, time));
	result.w = time;
	return (result);
}

t_xyzvektor	hit(t_all_intersec all_intersections, t_shape shape, size_t i,
		double closest_t)
{
	t_xyzvektor	hit_intersection;
	double		t[3];

	hit_intersection = set_vector(0, 0, 0, 0);
	while (++i < all_intersections.nr_intersections / 2)
	{
		if (!all_intersections.intersections[i].times
			|| all_intersections.intersections[i].object_id == shape.id)
			continue ;
		t[1] = all_intersections.intersections[i].times[0];
		t[2] = all_intersections.intersections[i].times[1];
		if (t[1] > EPSILON && (t[2] < EPSILON || t[1] < t[2]))
			t[0] = t[1];
		else if (t[2] > EPSILON)
			t[0] = t[2];
		else
			continue ;
		if (closest_t < 0 || t[0] < closest_t)
		{
			closest_t = t[0];
			hit_intersection = calc_hit_point
				(all_intersections.intersections[i], t[0]);
		}
	}
	return (hit_intersection);
}
