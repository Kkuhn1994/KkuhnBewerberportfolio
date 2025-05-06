/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:16:03 by kkuhn             #+#    #+#             */
/*   Updated: 2025/04/19 20:37:27 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_bumpmap_grayscale(mlx_texture_t *texture, int x, int y)
{
	uint32_t	*pixels;
	uint32_t	color;
	uint32_t	gray;
	uint32_t	xy[2];
	uint8_t		rgb[3];

	xy[0] = (uint32_t)x;
	xy[1] = (uint32_t)y;
	if (!texture || xy[0] >= texture->width
		|| xy[1] >= texture->height)
		return (-1);
	pixels = (uint32_t *)texture->pixels;
	color = pixels[xy[1] * texture->width + xy[0]];
	rgb[0] = (color >> 0) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 16) & 0xFF;
	gray = (int)(0.299 * rgb[0] + 0.587 * rgb[1] + 0.114 * rgb[2]);
	if (gray > 255)
		gray = 255;
	return (gray);
}

void	load_bumpmap(char *path, t_world *world)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		printf("Fehler beim Laden der Bumpmap: %s\n", path);
		return ;
	}
	world->canvas->bumpmapcolor = mlx_texture_to_image(world->canvas->mlx_ptr,
			texture);
	world->canvas->bumpmap = texture;
}

t_xyzvektor	get_color(t_c canvas, t_shape shape, long double x, long double y)
{
	t_xyzvektor	color;
	int			ix;
	int			iy;
	int			pixel_offset;
	uint32_t	pixel;

	ix = (int)x;
	iy = (int)y;
	if (canvas.bumpmapcolor && shape.type == 0)
	{
		pixel_offset = iy * (canvas.bumpmapcolor->width * 4 / sizeof(int)) + ix;
		pixel = ((uint32_t *)canvas.bumpmapcolor->pixels)[pixel_offset];
		color.w = ((pixel >> 24) & 0xFF) / 255.0;
		color.z = ((pixel >> 16) & 0xFF) / 255.0;
		color.y = ((pixel >> 8) & 0xFF) / 255.0;
		color.x = (pixel & 0xFF) / 255.0;
		return (color);
	}
	else
		return (get_color_from_uint(shape.material.color));
}
