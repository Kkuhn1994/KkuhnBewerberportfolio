/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:12:29 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/04 14:35:16 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	create_rotation_matrix(t_xyzvektor normal, double **rotation)
{
	double	axis[3];
	double	dot;
	double	c[3];
	double	sin_theta;
	double	cos_theta;

	axis[0] = 0.0;
	axis[1] = 1.0;
	axis[2] = 0.0;
	dot = normal.x * axis[0] + normal.y * axis[1] + normal.z * axis[2];
	c[0] = normal.y * axis[2] - normal.z * axis[1];
	c[1] = normal.z * axis[0] - normal.x * axis[2];
	c[2] = normal.x * axis[1] - normal.y * axis[0];
	sin_theta = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
	cos_theta = dot;
	rotation[0][0] = cos_theta + c[0] * c[0] * (1 - cos_theta);
	rotation[0][1] = c[0] * c[1] * (1 - cos_theta) - c[2] * sin_theta;
	rotation[0][2] = c[0] * c[2] * (1 - cos_theta) + c[1] * sin_theta;
	rotation[1][0] = c[1] * c[0] * (1 - cos_theta) + c[2] * sin_theta;
	rotation[1][1] = cos_theta + c[1] * c[1] * (1 - cos_theta);
	rotation[1][2] = c[1] * c[2] * (1 - cos_theta) - c[0] * sin_theta;
	rotation[2][0] = c[2] * c[0] * (1 - cos_theta) - c[1] * sin_theta;
	rotation[2][1] = c[2] * c[1] * (1 - cos_theta) + c[0] * sin_theta;
	rotation[2][2] = cos_theta + c[2] * c[2] * (1 - cos_theta);
}

void	transform_ray(t_ray *ray, double **rotation)
{
	double	origin[3];
	double	direction[3];

	origin[0] = ray->origin.x;
	origin[1] = ray->origin.y;
	origin[2] = ray->origin.z;
	direction[0] = ray->direction.x;
	direction[1] = ray->direction.y;
	direction[2] = ray->direction.z;
	ray->origin.x = rotation[0][0] * origin[0] + rotation[0][1] * origin[1]
		+ rotation[0][2] * origin[2];
	ray->origin.y = rotation[1][0] * origin[0] + rotation[1][1] * origin[1]
		+ rotation[1][2] * origin[2];
	ray->origin.z = rotation[2][0] * origin[0] + rotation[2][1] * origin[1]
		+ rotation[2][2] * origin[2];
	ray->direction.x = rotation[0][0] * direction[0] + rotation[0][1]
		* direction[1] + rotation[0][2] * direction[2];
	ray->direction.y = rotation[1][0] * direction[0] + rotation[1][1]
		* direction[1] + rotation[1][2] * direction[2];
	ray->direction.z = rotation[2][0] * direction[0] + rotation[2][1]
		* direction[1] + rotation[2][2] * direction[2];
}

void	cut_cylinder(t_intersec *result, t_ray ray, t_shape shape)
{
	double	tmp;

	if (result->times[0] > result->times[1])
	{
		tmp = result->times[0];
		result->times[0] = result->times[1];
		result->times[1] = tmp;
	}
	tmp = ray.origin.y + result->times[0] * ray.direction.y;
	if (shape.minimum > tmp || shape.maximum < tmp)
		result->times[0] = -1;
	tmp = ray.origin.y + result->times[1] * ray.direction.y;
	if ((shape.minimum > tmp || shape.maximum < tmp))
		result->times[1] = -1;
	return ;
}

double	get_discriminant(double *discriminant_values, t_ray ray,
		t_shape cylinder, t_intersec *result)
{
	double	discriminant;

	discriminant_values[0] = ray.direction.x * ray.direction.x + ray.direction.z
		* ray.direction.z;
	if (discriminant_values[0] > -EPSILON && discriminant_values[0] < EPSILON)
		return (FREE(discriminant_values), -1);
	discriminant_values[1] = 2 * ray.origin.x * ray.direction.x + 2
		* ray.origin.z * ray.direction.z;
	discriminant_values[2] = ray.origin.x * ray.origin.x + ray.origin.z
		* ray.origin.z - 1;
	discriminant = discriminant_values[1] * discriminant_values[1] - 4
		* discriminant_values[0] * discriminant_values[2];
	if (discriminant < 0)
		return (FREE(discriminant_values), -1);
	result->times[0] = (-discriminant_values[1] - sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->times[1] = (-discriminant_values[1] + sqrt(discriminant)) / (2
			* discriminant_values[0]);
	result->object_id = cylinder.id;
	return (discriminant);
}

t_intersec	*cylinder_intersect(t_intersec *result, t_ray ray, t_shape cylinder)
{
	double	*discriminant_values;
	double	discriminant;
	double	**rotation;

	rotation = MALLOC(sizeof(double *) * 3);
	rotation[0] = MALLOC(sizeof(double) * 3);
	rotation[1] = MALLOC(sizeof(double) * 3);
	rotation[2] = MALLOC(sizeof(double) * 3);
	create_rotation_matrix(cylinder.normal, rotation);
	transform_ray(&ray, rotation);
	discriminant_values = MALLOC(3 * sizeof(double));
	result->times = MALLOC(2 * sizeof(double));
	discriminant = get_discriminant(discriminant_values, ray, cylinder, result);
	if (discriminant == -1)
		return (NULL);
	cut_cylinder(result, ray, cylinder);
	if (result->times[0] == -1)
		cap_top(result, ray, cylinder);
	if (result->times[1] == -1)
		cap_bottom(result, ray, cylinder);
	FREE(discriminant_values);
	return (result);
}
