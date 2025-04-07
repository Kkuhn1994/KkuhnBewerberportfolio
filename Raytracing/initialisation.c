/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:29:16 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 16:04:48 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_canvas(t_c *canvas)
{
	canvas->worldheight = 8;
	canvas->height = 500;
	canvas->width = 500;
	canvas->mlx_ptr = mlx_init(canvas->width, canvas->height, "miniRT", false);
	canvas->pixel_size = canvas->height / canvas->worldheight;
	canvas->half_size = canvas->worldheight / 2;
	canvas->all_intersections.nr_intersections = 0;
	canvas->all_intersections.intersections = NULL;
	canvas->num_lights = 0;
}

t_ray	init_ray(void)
{
	t_ray		ray;
	t_xyzvektor	origin;
	t_xyzvektor	direction;

	origin.x = 0;
	origin.y = 0;
	origin.z = -5;
	origin.w = 1;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;
	direction.w = 0;
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
