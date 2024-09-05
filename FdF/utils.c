/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:13:27 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 18:35:23 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_rot_point(t_basic *mlb, int shift, int xy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			if (xy == 1)
				mlb->xyzmap[i][j].x += shift;
			else
				mlb->xyzmap[i][j].y += shift;
			j ++;
		}
		j = 0;
		i ++;
	}
}

void	key2(mlx_key_data_t keydata, t_basic *mlb)
{
	if (keydata.key == 71)
		mlb->projection = 1;
	if (keydata.key == 84)
		mlb->projection = 0;
	if (keydata.key == 82)
		translate_map(mlb, 0.7);
	if (keydata.key == 70)
		translate_map(mlb, 1.5);
	if (keydata.key == 88)
	{
		rotate_x(mlb, 10);
		mlb->xrotate += 10;
	}
	if (keydata.key == 90)
	{
		rotate_y(mlb, 10);
		mlb->yrotate += 10;
	}
	if (keydata.key == 67)
	{
		rotate_z(mlb, 10);
		mlb->zrotate += 10;
	}
}

void	key_callback(mlx_key_data_t keydata, void *ml)
{
	t_basic	*mlb;

	mlb = ml;
	key2(keydata, mlb);
	if (keydata.key == 256)
		exit_programm(mlb);
	if (keydata.key == 265)
		change_rot_point(mlb, 10, 0);
	if (keydata.key == 264)
		change_rot_point(mlb, -10, 0);
	if (keydata.key == 263)
		change_rot_point(mlb, -10, 1);
	if (keydata.key == 262)
		change_rot_point(mlb, 10, 1);
	if (keydata.key == 87)
		mlb->null_punkt[1] = mlb->null_punkt[1] - 50;
	if (keydata.key == 83)
		mlb->null_punkt[1] = mlb->null_punkt[1] + 50;
	if (keydata.key == 65)
		mlb->null_punkt[0] = mlb->null_punkt[0] - 50;
	if (keydata.key == 68)
		mlb->null_punkt[0] = mlb->null_punkt[0] + 50;
	if (keydata.key == 83)
		mlb->null_punkt[1] = mlb->null_punkt[1] + 50;
}

void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_basic	*mlb;
	int		x;
	int		y;

	mlb = param;
	mlx_get_mouse_pos(mlb->mlx_ptr, &x, &y);
	if (ydelta > 0)
	{
		mlb->zoom *= 1.5;
		mlb->null_punkt[0] = x + (mlb->null_punkt[0] - x) * 1.5;
		mlb->null_punkt[1] = y + (mlb->null_punkt[1] - y) * 1.5;
	}
	else if (ydelta < 0)
	{
		mlb->zoom /= 1.5;
		mlb->null_punkt[0] = x + (mlb->null_punkt[0] - x) / 1.5;
		mlb->null_punkt[1] = y + (mlb->null_punkt[1] - y) / 1.5;
	}
}

int	nextpixel(int *x, int *y, int xmax, int ymax)
{
	if (*x == xmax && *y == ymax)
		return (0);
	if (*x != xmax)
		*x = *x + 1;
	else if (*x == xmax)
	{
		*x = 0;
		*y = *y + 1;
	}
	else
		*y = *y + 1;
	return (1);
}
