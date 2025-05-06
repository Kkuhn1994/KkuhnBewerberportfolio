/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:24:05 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/18 10:51:33 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	transform(t_ray ray, double **transformation)
{
	t_ray	new_ray;

	new_ray.origin = multiply_vector_and_matrix(ray.origin, transformation);
	new_ray.direction.x = transformation[0][0] * ray.direction.x
		+ transformation[0][1] * ray.direction.y + transformation[0][2]
		* ray.direction.z;
	new_ray.direction.y = transformation[1][0] * ray.direction.x
		+ transformation[1][1] * ray.direction.y + transformation[1][2]
		* ray.direction.z;
	new_ray.direction.z = transformation[2][0] * ray.direction.x
		+ transformation[2][1] * ray.direction.y + transformation[2][2]
		* ray.direction.z;
	new_ray.direction.w = 0.0;
	return (new_ray);
}

void	set_transform(t_shape *shape, double **translation)
{
	shape->default_transformation = translation;
}
