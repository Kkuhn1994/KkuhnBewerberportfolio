/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:24:22 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 17:30:48 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	magnitude(t_xyzvektor a)
{
	double	result;

	result = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	return (result);
}

t_xyzvektor	normalize(t_xyzvektor a)
{
	t_xyzvektor	result;

	if (magnitude(a) == 0)
		return (a);
	result.x = a.x / magnitude(a);
	result.y = a.y / magnitude(a);
	result.z = a.z / magnitude(a);
	result.w = a.w / magnitude(a);
	return (result);
}

t_xyzvektor	negate_tuple(t_xyzvektor a)
{
	t_xyzvektor	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}

t_xyzvektor	set_vector(double x, double y, double z, double w)
{
	t_xyzvektor	return_vector;

	return_vector.x = x;
	return_vector.y = y;
	return_vector.z = z;
	return_vector.w = w;
	return (return_vector);
}
