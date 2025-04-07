/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_vector_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:33:27 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/04 16:27:30 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_xyzvektor	addition(t_xyzvektor a, t_xyzvektor b)
{
	t_xyzvektor	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

t_xyzvektor	substraction(t_xyzvektor a, t_xyzvektor b)
{
	t_xyzvektor	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

double	dot_product(t_xyzvektor a, t_xyzvektor b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (result);
}

t_xyzvektor	cross_product(t_xyzvektor a, t_xyzvektor b)
{
	t_xyzvektor	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	if (a.w == 1 || b.w == 1)
		result.w = 1;
	else
		result.w = 0;
	return (result);
}

t_xyzvektor	hadamard_product(t_xyzvektor a, t_xyzvektor b)
{
	t_xyzvektor	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	if (a.w == 1 || b.w == 1)
		result.w = 1;
	else
		result.w = 0;
	return (result);
}
