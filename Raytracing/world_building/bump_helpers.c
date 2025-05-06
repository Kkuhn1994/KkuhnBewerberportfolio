/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:26:47 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:42:59 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	uv_of_sphere(t_intersec *intersect, t_comp *comps, t_shape *shape,
		t_world world)
{
	t_xyzvektor	relative_point;
	double		theta;
	double		phi;
	double		length;

	relative_point = substraction(comps->point, shape->origin);
	length = pow(relative_point.x, 2) + pow(relative_point.y, 2);
	length += pow(relative_point.z, 2);
	length = sqrt(length);
	relative_point = scalar_division(relative_point, length);
	theta = atan2(relative_point.z, relative_point.x);
	phi = asin(relative_point.y);
	length = ((theta + PI) / (2 * PI));
	intersect->u = fmod(length * world.canvas->bumpmap->width,
			world.canvas->bumpmap->width);
	intersect->v = fmod((0.5 - phi / PI) * world.canvas->bumpmap->height,
			world.canvas->bumpmap->height);
	comps->u = intersect->u;
	comps->v = intersect->v;
}

void	orthogonale_vektoren(t_xyzvektor x, t_xyzvektor *y, t_xyzvektor *z,
		t_world *world)
{
	if (x.x == 0 && x.y == 0 && x.z == 0)
		bail("x cant be 0 :)", 1, world);
	if (x.x != 0 || x.y != 0)
	{
		y->x = -x.y;
		y->y = x.x;
		y->z = 0;
	}
	else
	{
		y->x = 0;
		y->y = x.z;
		y->z = -x.y;
	}
	z->x = x.y * y->z - x.z * y->y;
	z->y = x.z * y->x - x.x * y->z;
	z->z = x.x * y->y - x.y * y->x;
}

void	uv_of_plane(t_intersec *intersect, t_comp comps, t_shape *plane)
{
	t_xyzvektor	relative_point;
	double		uv[2];
	double		scale;
	t_xyzvektor	tangent;
	t_xyzvektor	bitangent;

	tangent = set_vector(1, 0, 0, 0);
	bitangent = set_vector(0, 0, 1, 0);
	relative_point = substraction(comps.point, plane->origin);
	uv[0] = dot_product(relative_point, tangent);
	uv[1] = dot_product(relative_point, bitangent);
	scale = 1.0;
	uv[0] = fmod(uv[0] * scale, 1.0);
	uv[1] = fmod(uv[1] * scale, 1.0);
	if (uv[0] < 0)
		uv[0] += 1.0;
	if (uv[1] < 0)
		uv[1] += 1.0;
	intersect->u = uv[0];
	intersect->v = uv[1];
}
