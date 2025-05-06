/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:20:56 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 17:58:18 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_building/world.h"

#define PI 3.14159265358979323846

void	esc_handler(mlx_key_data_t keydata, void *param)
{
	t_world	*world;

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		world = (t_world *)param;
		if (world->canvas->image_to_free)
			mlx_delete_image(world->canvas->mlx_ptr,
				world->canvas->image_to_free);
		if (world->canvas->bumpmapcolor)
			mlx_delete_image(world->canvas->mlx_ptr,
				world->canvas->bumpmapcolor);
		if (world->canvas->img)
			mlx_delete_image(world->canvas->mlx_ptr, world->canvas->img);
		if (world->canvas->bumpmap)
			mlx_delete_texture(world->canvas->bumpmap);
		mlx_terminate(world->canvas->mlx_ptr);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_world		*world;
	mlx_image_t	*image;

	world = get_world(100);
	if (!world || argc != 2)
		bail("usage: ./miniRT [name].rt", 1, world);
	init_canvas(world->canvas);
	mlx_key_hook(world->canvas->mlx_ptr, esc_handler, world);
	if (parse_input(argv[1], world))
		return (1);
	image = render_image(world->camera, world);
	if (!image)
		bail("rendering failed", 1, world);
	world->canvas->image_to_free = image;
	mlx_image_to_window(world->canvas->mlx_ptr, image, 0, 0);
	mlx_loop(world->canvas->mlx_ptr);
	mlx_delete_image(world->canvas->mlx_ptr, image);
	mlx_terminate(world->canvas->mlx_ptr);
	return (0);
}
