/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_hits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:10:17 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/17 23:25:51 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_xyzvektor	ray_position(t_ray ray, double time)
{
	t_xyzvektor	result;

	result = addition(ray.origin, scalar_multiplication(ray.direction, time));
	return (result);
}

t_xyzvektor	identify_hit(t_all_intersec all_intersections)
{
	t_intersec	hit_intersection;
	t_ray		ray;
	double		time_of_hit;

	hit_intersection = all_intersections.intersections[0];
	ray = all_intersections.intersections[0].ray;
	time_of_hit = get_smallest_positive_value(&hit_intersection);
	return (ray_position(ray, time_of_hit));
}

t_xyzvektor	point_of_intersection(t_intersec *intersec, t_ray ray)
{
	double		time_of_intersection;
	t_xyzvektor	way;
	t_xyzvektor	point_of_intersection;

	time_of_intersection = get_smallest_positive_value(intersec);
	way = scalar_multiplication(ray.direction, time_of_intersection);
	point_of_intersection = addition(ray.origin, way);
	return (point_of_intersection);
}
