/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:35:43 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 18:35:43 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_basic *mlb, int angl)
{
	int			i;
	int			j;
	long double	angle;
	long double	new_x;
	long double	new_y;

	i = 0;
	j = 0;
	angle = angl * M_PI / 180.0;
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			new_x = cos(angle) * mlb->xyzmap[i][j].x
				- sin(angle) * mlb->xyzmap[i][j].y;
			new_y = sin(angle) * mlb->xyzmap[i][j].x
				+ cos(angle) * mlb->xyzmap[i][j].y;
			mlb->xyzmap[i][j].x = new_x;
			mlb->xyzmap[i][j].y = new_y;
			j++;
		}
		j = 0;
		i++;
	}
}

void	rotate_y(t_basic *mlb, int angl)
{
	int			i;
	int			j;
	long double	angle;
	long double	new_x;
	long double	new_z;

	i = 0;
	j = 0;
	angle = angl * M_PI / 180.0;
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			new_x = cos(angle) * mlb->xyzmap[i][j].x
				+ sin(angle) * mlb->xyzmap[i][j].z;
			new_z = -sin(angle) * mlb->xyzmap[i][j].x
				+ cos(angle) * mlb->xyzmap[i][j].z;
			mlb->xyzmap[i][j].x = new_x;
			mlb->xyzmap[i][j].z = new_z;
			j++;
		}
		j = 0;
		i++;
	}
}

void	rotate_x(t_basic *mlb, int angl)
{
	int			i;
	int			j;
	long double	angle;
	long double	new_y;
	long double	new_z;

	i = 0;
	j = 0;
	angle = angl * M_PI / 180.0;
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			new_y = cos(angle) * mlb->xyzmap[i][j].y
				- sin(angle) * mlb->xyzmap[i][j].z;
			new_z = sin(angle) * mlb->xyzmap[i][j].y
				+ cos(angle) * mlb->xyzmap[i][j].z;
			mlb->xyzmap[i][j].y = new_y;
			mlb->xyzmap[i][j].z = new_z;
			j++;
		}
		j = 0;
		i++;
	}
}

t_matrix	**convert_to_matrix(long double **map, int x, int y)
{
	t_matrix	**map_matrix;
	int			i;
	int			j;

	i = 0;
	j = 0;
	map_matrix = malloc(y * sizeof(t_matrix *));
	while (i < y - 1)
	{
		map_matrix[i] = malloc(x * sizeof(t_matrix));
		while (j < x)
		{
			map_matrix[i][j].x = (long double)(-(x + 1) / 2 + j + 1);
			map_matrix[i][j].y = (long double)(y / 2 - i - 1);
			map_matrix[i][j].z = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	map_matrix[i] = 0;
	return (map_matrix);
}
