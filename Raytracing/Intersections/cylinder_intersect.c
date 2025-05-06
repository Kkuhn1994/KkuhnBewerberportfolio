/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:12:29 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:58:47 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	handle_no_nw(double nw, t_xyzvektor *new_orig)
{
	if (nw != 0.0)
	{
		(*new_orig).x /= nw;
		(*new_orig).y /= nw;
		(*new_orig).z /= nw;
	}
}

void	transform_ray(t_ray *ray, double **matrix)
{
	t_xyzvektor	orig;
	t_xyzvektor	dir;
	t_xyzvektor	new_orig;
	t_xyzvektor	new_dir;
	double		nw;

	orig = ray->origin;
	new_orig.x = matrix[0][0] * orig.x + matrix[0][1] * orig.y + matrix[0][2]
		* orig.z + matrix[0][3] * 1.0;
	new_orig.y = matrix[1][0] * orig.x + matrix[1][1] * orig.y + matrix[1][2]
		* orig.z + matrix[1][3] * 1.0;
	new_orig.z = matrix[2][0] * orig.x + matrix[2][1] * orig.y + matrix[2][2]
		* orig.z + matrix[2][3] * 1.0;
	nw = matrix[3][0] * orig.x + matrix[3][1] * orig.y + matrix[3][2] * orig.z
		+ matrix[3][3] * 1.0;
	handle_no_nw(nw, &new_orig);
	ray->origin = new_orig;
	dir = ray->direction;
	new_dir.x = matrix[0][0] * dir.x + matrix[0][1] * dir.y + matrix[0][2]
		* dir.z;
	new_dir.y = matrix[1][0] * dir.x + matrix[1][1] * dir.y + matrix[1][2]
		* dir.z;
	new_dir.z = matrix[2][0] * dir.x + matrix[2][1] * dir.y + matrix[2][2]
		* dir.z;
	ray->direction = new_dir;
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
		return (ft_free(discriminant_values), -1);
	discriminant_values[1] = 2 * ray.origin.x * ray.direction.x + 2
		* ray.origin.z * ray.direction.z;
	discriminant_values[2] = ray.origin.x * ray.origin.x + ray.origin.z
		* ray.origin.z - 1;
	discriminant = discriminant_values[1] * discriminant_values[1] - 4
		* discriminant_values[0] * discriminant_values[2];
	if (discriminant < 0)
		return (ft_free(discriminant_values), -1);
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

	discriminant_values = ft_calloc(3, sizeof(double));
	result->times = ft_calloc(2, sizeof(double));
	discriminant = get_discriminant(discriminant_values, ray, cylinder, result);
	if (discriminant == -1)
		return (NULL);
	cut_cylinder(result, ray, cylinder);
	if (cylinder.closed)
		cap_top(result, ray, cylinder);
	if (cylinder.closed)
		cap_bottom(result, ray, cylinder);
	ft_free(discriminant_values);
	return (result);
}
