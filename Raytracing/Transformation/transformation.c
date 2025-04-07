/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:24:05 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 17:24:10 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	transform(t_ray ray, double **transformation)
{
	t_ray	new_ray;

	new_ray.origin = multiply_vector_and_matrix(ray.origin, transformation);
	new_ray.direction = multiply_vector_and_matrix(ray.direction,
			transformation);
	return (new_ray);
}

void	set_transform(t_shape *shape, double **translation)
{
	shape->default_transformation = translation;
}
