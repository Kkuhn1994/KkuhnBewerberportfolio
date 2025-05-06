/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:20:53 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 21:22:24 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_xyzvektor	calc_cone_normal(t_shape cone, t_xyzvektor point)
{
	t_xyzvektor	normal;
	double		ratio;
	double		dist;

	ratio = cone.radius / (cone.maximum - cone.minimum);
	dist = point.x * point.x + point.z * point.z;
	if (dist < 1.0 + EPSILON && point.y >= cone.maximum - EPSILON)
		return (set_vector(0, 1, 0, 0));
	normal.x = point.x;
	normal.z = point.z;
	normal.y = -sqrt(point.x * point.x + point.z * point.z) * ratio;
	normal.w = 0.0;
	normal = normalize(normal);
	return (normal);
}

t_xyzvektor	cone_normal(t_shape shape, t_xyzvektor point)
{
	double		**inverse_transform;
	t_xyzvektor	world_normal;
	t_xyzvektor	local_normal;
	t_xyzvektor	local_point;
	double		**transpose_inverse;

	inverse_transform = invert_matrix(shape.default_transformation, 4);
	local_point = multiply_vector_and_matrix(point, inverse_transform);
	local_normal = calc_cone_normal(shape, local_point);
	transpose_inverse = transpose_matrix(inverse_transform, 4);
	world_normal = multiply_vector_and_matrix(local_normal, transpose_inverse);
	free_double_ptr(transpose_inverse, 4);
	return (normalize(world_normal));
}
