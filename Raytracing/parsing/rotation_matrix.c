/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:33:03 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/18 19:37:39 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	compute_rotation_parameters(t_xyzvektor normal, double u[3],
		double *sin_theta, double *cos_theta)
{
	double	c[3];

	c[0] = -normal.z;
	c[1] = 0.0;
	c[2] = normal.x;
	*sin_theta = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
	*cos_theta = normal.y;
	if (*sin_theta > EPSILON)
	{
		u[0] = c[0] / *sin_theta;
		u[1] = c[1] / *sin_theta;
		u[2] = c[2] / *sin_theta;
	}
	else
	{
		u[0] = 0.0;
		u[1] = 0.0;
		u[2] = 0.0;
	}
}

void	build_rotation_matrix(double u[3], double sin_theta, double cos_theta,
		double **rotation)
{
	rotation[0][0] = cos_theta + u[0] * u[0] * (1 - cos_theta);
	rotation[0][1] = u[0] * u[1] * (1 - cos_theta) - u[2] * sin_theta;
	rotation[0][2] = u[0] * u[2] * (1 - cos_theta) + u[1] * sin_theta;
	rotation[1][0] = u[1] * u[0] * (1 - cos_theta) + u[2] * sin_theta;
	rotation[1][1] = cos_theta + u[1] * u[1] * (1 - cos_theta);
	rotation[1][2] = u[1] * u[2] * (1 - cos_theta) - u[0] * sin_theta;
	rotation[2][0] = u[2] * u[0] * (1 - cos_theta) - u[1] * sin_theta;
	rotation[2][1] = u[2] * u[1] * (1 - cos_theta) + u[0] * sin_theta;
	rotation[2][2] = cos_theta + u[2] * u[2] * (1 - cos_theta);
	rotation[3][3] = 1.0;
}

void	create_rotation_matrix(t_xyzvektor normal, double **rotation)
{
	double	u[3];
	double	sin_theta;
	double	cos_theta;

	compute_rotation_parameters(normal, u, &sin_theta, &cos_theta);
	build_rotation_matrix(u, sin_theta, cos_theta, rotation);
}
