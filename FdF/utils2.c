/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:34:46 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 19:06:10 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_programm(void *input)
{
	t_basic	*mlb;

	mlb = input;
	mlx_delete_image(mlb->mlx_ptr, mlb->menu);
	mlx_delete_image(mlb->mlx_ptr, mlb->img);
	free_map(mlb->map, mlb->nr_line);
	free_map2(mlb->xyzmap, mlb->nr_line);
	free(mlb->int_per_line);
	exit(0);
}

void	translate_map(t_basic *mlb, float factor)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			mlb->map[i][j] *= factor;
			j ++;
		}
		j = 0;
		i ++;
	}
	mlb->xyzmap = convert_to_matrix(mlb->map, *mlb->int_per_line, mlb->nr_line);
	rotate_x(mlb, mlb->xrotate);
	rotate_y(mlb, mlb->yrotate);
	rotate_z(mlb, mlb->zrotate);
}

void	print_menu(t_basic *mlb)
{
	void	*mlx;
	int		x;
	int		y;

	x = 5;
	y = 10;
	mlb->menu = mlx_put_string(mlb->mlx_ptr, "How to use :", x, y);
	mlb->menu = mlx_put_string(mlb->mlx_ptr, "Rotate : z, x, c ", x, y += 20);
	mlb->menu = mlx_put_string(mlb->mlx_ptr, "Move: w, a,s ,d", x, y += 20);
	mlb->menu = mlx_put_string(mlb->mlx_ptr,
			"Move rotation point: arrows", x, y += 20);
	mlb->menu = mlx_put_string(mlb->mlx_ptr, "Translate : r, f", x, y += 20);
	mlb->menu = mlx_put_string(mlb->mlx_ptr,
			"Change projection mode : t, g", x, y += 20);
}
