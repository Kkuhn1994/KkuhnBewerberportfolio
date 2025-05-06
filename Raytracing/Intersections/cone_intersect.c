/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:15:01 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 21:13:29 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	cut_cone(t_intersec *result, t_ray ray, t_shape shape)
{
	double	tmp;

	if (result->times[0] > result->times[1])
	{
		tmp = result->times[0];
		result->times[0] = result->times[1];
		result->times[1] = tmp;
	}
	tmp = ray.origin.y + result->times[0] * ray.direction.y;
	if (0 > tmp || (shape.maximum) < tmp)
	{
		result->times[0] = -1;
		result->times[1] = -1;
	}
	return ;
}

void	cap_top(t_intersec *result, t_ray ray, t_shape shape)
{
	double	t_top;
	double	x_top;
	double	z_top;

	if (fabs(ray.direction.y) > EPSILON)
	{
		t_top = (shape.maximum - ray.origin.y) / ray.direction.y;
		x_top = ray.origin.x + t_top * ray.direction.x;
		z_top = ray.origin.z + t_top * ray.direction.z;
		if (x_top * x_top + z_top * z_top <= 1.0)
		{
			if (result->times[0] == -1 || t_top < result->times[0])
			{
				result->times[1] = result->times[0];
				result->times[0] = t_top;
			}
			else if (result->times[1] == -1 || t_top < result->times[1])
			{
				result->times[1] = t_top;
			}
		}
	}
}

void	cap_bottom(t_intersec *result, t_ray ray, t_shape shape)
{
	double	t_bottom;
	double	x_bottom;
	double	z_bottom;

	t_bottom = (shape.minimum - ray.origin.y) / ray.direction.y;
	x_bottom = ray.origin.x + t_bottom * ray.direction.x;
	z_bottom = ray.origin.z + t_bottom * ray.direction.z;
	if (x_bottom * x_bottom + z_bottom * z_bottom <= 1.0)
	{
		if (result->times[0] == -1 || t_bottom < result->times[0])
		{
			result->times[1] = result->times[0];
			result->times[0] = t_bottom;
		}
		else if (result->times[1] == -1 || t_bottom < result->times[1])
		{
			result->times[1] = t_bottom;
		}
	}
}

int	cone_discrimination(double *discriminant_values, t_ray ray, t_shape cone,
		t_intersec *result)
{
	double	discriminant;
	double	tan_theta;

	tan_theta = cone.radius / (cone.maximum - cone.minimum);
	discriminant_values[0] = ray.direction.x * ray.direction.x + ray.direction.z
		* ray.direction.z - ray.direction.y * ray.direction.y * tan_theta
		* tan_theta;
	if (discriminant_values[0] > -EPSILON && discriminant_values[0] < EPSILON)
		return (ft_free(discriminant_values), 1);
	discriminant_values[1] = 2 * ray.origin.x * ray.direction.x + 2
		* ray.origin.z * ray.direction.z - 2 * ray.origin.y * ray.direction.y
		* tan_theta * tan_theta;
	discriminant_values[2] = ray.origin.x * ray.origin.x + ray.origin.z
		* ray.origin.z - ray.origin.y * ray.origin.y * tan_theta * tan_theta;
	discriminant = discriminant_values[1] * discriminant_values[1] - 4
		* discriminant_values[0] * discriminant_values[2];
	if (discriminant < 0)
		return (ft_free(discriminant_values), 1);
	result->times[0] = (-discriminant_values[1] - sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->times[1] = (-discriminant_values[1] + sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->object_id = cone.id;
	return (0);
}

t_intersec	*cone_intersect(t_intersec *result, t_ray ray, t_shape cone)
{
	double	*discriminant_values;

	discriminant_values = ft_calloc(3, sizeof(double));
	result->times = ft_calloc(2, sizeof(double));
	if (cone_discrimination(discriminant_values, ray, cone, result))
		return (NULL);
	cut_cone(result, ray, cone);
	if (result->times[0] == -1)
		cap_top(result, ray, cone);
	ft_free(discriminant_values);
	return (result);
}

// cut_cylinder(result, ray, cone);
