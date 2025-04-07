/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:32:04 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/04 13:34:34 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_xyzvektor	sphere_normal(t_shape shape, t_xyzvektor point)
{
	t_xyzvektor	local_point;
	t_xyzvektor	local_normal;
	t_xyzvektor	world_normal;
	double		**inverse_transform;
	double		**transpose_inverse_transform;

	inverse_transform = invert_matrix(shape.default_transformation, 4);
	local_point = multiply_vector_and_matrix(point, inverse_transform);
	local_normal = local_point;
	transpose_inverse_transform = transpose_matrix(inverse_transform, 4);
	world_normal = multiply_vector_and_matrix(local_normal,
			transpose_inverse_transform);
	world_normal.w = 0;
	free_double_ptr(transpose_inverse_transform, 4);
	free_double_ptr(inverse_transform, 4);
	return (normalize(world_normal));
}

t_xyzvektor	calc_cone_normal(t_shape cone, t_xyzvektor point)
{
	t_xyzvektor	normal;
	double		tangens_theta;

	tangens_theta = cone.radius / (cone.maximum - cone.minimum);
	normal.x = -point.x * tangens_theta * tangens_theta;
	normal.y = point.y;
	normal.z = point.z;
	normal = normalize(normal);
	return (normal);
}

t_xyzvektor	calc_cylinder_normal(t_shape shape, t_xyzvektor point)
{
	double	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= shape.maximum - EPSILON)
		return (set_vector(0, 1, 0, 0));
	else if (dist < 1 && point.y <= shape.minimum + EPSILON)
		return (set_vector(0, -1, 0, 0));
	else
		return (set_vector(point.x, 0, point.z, 0));
}

t_xyzvektor	calculate_normale(t_shape shape, t_xyzvektor point)
{
	t_xyzvektor	ret;
	double		**inverse_transform;
	double		**transpose_inverse_transform;
	t_xyzvektor	local_normal;

	if (shape.type == 0)
		return (sphere_normal(shape, point));
	else if (shape.type == 1)
	{
		inverse_transform = invert_matrix(shape.default_transformation, 4);
		local_normal = shape.normal;
		transpose_inverse_transform = transpose_matrix(inverse_transform, 4);
		free_double_ptr(inverse_transform, 4);
		ret = multiply_vector_and_matrix(local_normal,
				transpose_inverse_transform);
		free_double_ptr(transpose_inverse_transform, 4);
		return (ret);
	}
	else if (shape.type == 2)
		return (calc_cylinder_normal(shape, point));
	else if (shape.type == 3)
		return (calc_cone_normal(shape, point));
	return (set_vector(0, 0, 0, 0));
}
