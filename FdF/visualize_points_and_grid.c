/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_points_and_grid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:12:14 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 18:34:40 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*coord_calc(t_matrix a, t_basic *mlb)
{
	int	*xy;

	xy = malloc (2 * sizeof(int));
	if (mlb->projection == 1)
		return (conic_projection(a, mlb));
	xy[0] = (int)(a.x * mlb->factor * mlb->zoom);
	xy[1] = (int)(a.y * mlb->factor * mlb->zoom);
	xy[0] += mlb->null_punkt[0];
	xy[1] += mlb->null_punkt[1];
	return (xy);
}

void	init(t_matrix a, t_matrix b, t_basic *mlb)
{
	mlb->p1 = coord_calc(a, mlb);
	if (mlb->p1[0] < 0 || mlb->p1[0] > 800
		|| mlb->p1[1] < 0 || mlb->p1[1] > 800)
	{
		mlb->p2 = mlb->p1;
		mlb->p1 = coord_calc(b, mlb);
	}
	else
		mlb->p2 = coord_calc(b, mlb);
	mlb->delta[0] = abs(mlb->p1[0] - mlb->p2[0]);
	mlb->delta[1] = abs(mlb->p1[1] - mlb->p2[1]);
	mlb->error[0] = mlb->delta[0] - mlb->delta[1];
	if (mlb->p1[0] < mlb->p2[0])
		mlb->sign[0] = 1;
	else
		mlb->sign[0] = -1;
	if (mlb->p1[1] < mlb->p2[1])
		mlb->sign[1] = 1;
	else
		mlb->sign[1] = -1;
}

int	draw_line(t_matrix a, t_matrix b, t_basic *mlb)
{
	init(a, b, mlb);
	while (mlb->p1[0] != mlb->p2[0] || mlb->p1[1] != mlb->p2[1])
	{
		if (mlb->p1[0] <= 0 || mlb->p1[0] >= 1500
			|| mlb->p1[1] <= 0 || mlb->p1[1] >= 1500)
			return (free(mlb->p1), free(mlb->p2), 0);
		mlx_put_pixel(mlb->img, mlb->p1[0], mlb->p1[1], 0xFFFFFF);
		mlb->error[1] = mlb->error[0] * 2;
		if (mlb->error[1] > -mlb->delta[1])
		{
			mlb->error[0] -= mlb->delta[1];
			mlb->p1[0] += mlb->sign[0];
		}
		if (mlb->error[1] < mlb->delta[0])
		{
			mlb->error[0] += mlb->delta[0];
			mlb->p1[1] += mlb->sign[1];
		}
	}
	free(mlb->p1);
	free(mlb->p2);
	return (0);
}

void	visualize(void *ml)
{
	t_basic	*mlb;
	char	*imgdata;
	int		j;
	int		i;

	mlb = (t_basic *)ml;
	i = 0;
	j = 0;
	mlx_delete_image(mlb->mlx_ptr, mlb->img);
	mlb->img = mlx_new_image(mlb->mlx_ptr, 1500, 1500);
	while (i < mlb->nr_line - 1)
	{
		while (j < mlb->nr_p_line)
		{
			if (j != mlb->nr_p_line - 1)
				draw_line(mlb->xyzmap[i][j], mlb->xyzmap[i][j + 1], mlb);
			if (i != mlb->nr_line - 2)
				draw_line(mlb->xyzmap[i][j], mlb->xyzmap[i + 1][j], mlb);
			j ++;
		}
		j = 0;
		i ++;
	}
	mlx_image_to_window(mlb->mlx_ptr, mlb->img, 0, 0);
	return ;
}
