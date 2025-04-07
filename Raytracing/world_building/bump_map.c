/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:16:03 by kkuhn             #+#    #+#             */
/*   Updated: 2025/04/04 17:56:11 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int get_bumpmap_grayscale(mlx_texture_t *texture, int x, int y)
{
    // Überprüfe, ob die Koordinaten gültig sind
    if (!texture || x < 0 || y < 0 || x >= texture->width || y >= texture->height)
        return -1;
    uint32_t *pixels = (uint32_t *)texture->pixels;
    uint32_t color = pixels[y * texture->width + x];
    uint8_t r = (color >> 0) & 0xFF;   // Rot
    uint8_t g = (color >> 8) & 0xFF;   // Grün
    uint8_t b = (color >> 16) & 0xFF;  // Blau
    int gray = (int)(0.299 * r + 0.587 * g + 0.114 * b);
    if (gray < 0) gray = 0;
    if (gray > 255) gray = 255;
    
    return gray;
}

void load_bumpmap(char *path, t_world *world)
{
	mlx_texture_t *texture = mlx_load_png(path);
    if (!texture) {
        printf("Fehler beim Laden der Bumpmap: %s\n", path);
        return;
    }
	world->canvas->bumpmapcolor = mlx_texture_to_image(world->canvas->mlx_ptr, texture);
	world->canvas->bumpmap = texture;;
}