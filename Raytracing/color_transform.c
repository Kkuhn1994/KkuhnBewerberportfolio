/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:21:55 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/24 17:45:31 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// RGB vertauscht x = b

int	min_of(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

uint32_t	get_color_from_tuple(t_xyzvektor color)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = 255;
	r = min_of(color.x * 255, 255);
	g = min_of(color.y * 255, 255);
	b = min_of(color.z * 255, 255);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

t_xyzvektor	get_color_from_uint(uint32_t color)
{
	t_xyzvektor	result;
	uint8_t		a;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	a = color & 0xFF;
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	result.x = (double)r / 255;
	result.y = (double)g / 255;
	result.z = (double)b / 255;
	result.w = (double)a / 255;
	return (result);
}
