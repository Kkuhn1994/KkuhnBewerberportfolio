/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:10:06 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 00:30:48 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static double	get_discriminant_smol(double *discriminant_values)
{
	return (discriminant_values[1] * discriminant_values[1] - 4
		* discriminant_values[0] * discriminant_values[2]);
}

t_intersec	*intersect_sphere(t_intersec *result, t_ray ray, t_shape sphere)
{
	double		*discriminant_values;
	double		discriminant;
	t_xyzvektor	sphere_to_ray;

	discriminant_values = ft_calloc(3, sizeof(double));
	sphere_to_ray = ray.origin;
	discriminant_values[0] = dot_product(ray.direction, ray.direction);
	discriminant_values[1] = 2 * dot_product(ray.direction, sphere_to_ray);
	discriminant_values[2] = dot_product(sphere_to_ray, sphere_to_ray)
		- sphere.radius * sphere.radius;
	discriminant = get_discriminant_smol(discriminant_values);
	if (sphere.radius <= 1)
		discriminant += 1;
	if (discriminant < 0)
		return (ft_free(discriminant_values), NULL);
	result->times = ft_calloc(2, sizeof(double));
	result->times[0] = (-discriminant_values[1] - sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->times[1] = (-discriminant_values[1] + sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->object_id = sphere.id;
	ft_free(discriminant_values);
	return (result);
}

t_intersec	*intersect_plane(t_intersec *result, t_ray ray, t_shape plane)
{
	double	discriminant_values[2];

	result->times = ft_calloc(2, sizeof(double));
	discriminant_values[0] = 0;
	discriminant_values[1] = 0;
	discriminant_values[0] = dot_product(ray.direction, set_vector(0, 1, 0, 0));
	if (discriminant_values[0] == 0)
	{
		return (NULL);
	}
	discriminant_values[1] = -dot_product(ray.origin, set_vector(0, 1, 0, 0));
	if (discriminant_values[1] / discriminant_values[0] <= EPSILON)
	{
		result->times[0] = -1;
		result->times[1] = -1;
		return (result);
	}
	result->times[0] = discriminant_values[1] / discriminant_values[0];
	result->times[1] = discriminant_values[1] / discriminant_values[0];
	result->object_id = plane.id;
	return (result);
}

t_intersec	*local_intersect(t_intersec *result, t_ray ray, t_shape *shape)
{
	if (shape->type == 0)
	{
		return (intersect_sphere(result, ray, *shape));
	}
	else if (shape->type == 1)
	{
		return (intersect_plane(result, ray, *shape));
	}
	else if (shape->type == 2)
	{
		return (cylinder_intersect(result, ray, *shape));
	}
	else if (shape->type == 3)
	{
		return (cone_intersect(result, ray, *shape));
	}
	return (NULL);
}

t_intersec	*intersect(t_shape *shape, t_ray ray)
{
	t_intersec	*result;
	double		**inverse;

	result = ft_calloc(sizeof(t_intersec), 1);
	inverse = invert_matrix(shape->default_transformation, 4);
	ray = transform(ray, inverse);
	result->ray = ray;
	return (local_intersect(result, ray, shape));
}
