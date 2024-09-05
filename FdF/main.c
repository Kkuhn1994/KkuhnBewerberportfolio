/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:30 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 18:52:05 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*conic_projection(t_matrix point, t_basic *mlb)
{
	int		*xy;
	double	rho;
	double	rho0;

	xy = malloc(2 * sizeof(int));
	mlb->lat_rad = point.y * M_PI / 180.0;
	mlb->lon_rad = point.x * M_PI / 180.0;
	mlb->cld = 0.0 * M_PI / 180.0;
	mlb->sp1_rad = 30.0 * M_PI / 180.0;
	mlb->sp2_rad = 60.0 * M_PI / 180.0;
	mlb->n = (log(cos(mlb->sp1_rad)) - log(cos(mlb->sp2_rad)))
		/ (log(tan(M_PI / 4 + mlb->sp2_rad / 2))
			- log(tan(M_PI / 4 + mlb->sp1_rad / 2)));
	mlb->f = (cos(mlb->sp1_rad)
			* pow(tan(M_PI / 4 + mlb->sp1_rad / 2), mlb->n)) / mlb->n;
	rho = mlb->f * pow(tan(M_PI / 4 + mlb->lat_rad / 2), -mlb->n);
	rho0 = mlb->f * pow(tan(M_PI / 4 + mlb->sp1_rad / 2), -mlb->n);
	xy[0] = (int)(rho * sin(mlb->n * (mlb->lon_rad - mlb->cld))
			* mlb->factor * mlb->zoom * 50);
	xy[1] = (int)((rho0 - rho * cos(mlb->n * (mlb->lon_rad - mlb->cld)))
			* mlb->factor * mlb->zoom * 50);
	xy[0] += mlb->null_punkt[0];
	xy[1] += mlb->null_punkt[1] + 900;
	return (xy);
}

void	mlx_part(t_basic minilib)
{
	minilib.null_punkt[0] = 750;
	minilib.null_punkt[1] = 750;
	minilib.xrotate = 0;
	minilib.yrotate = 0;
	minilib.zrotate = 0;
	minilib.mlx_ptr = mlx_init(1500, 1500, "FDf", false);
	if (minilib.nr_line > minilib.nr_p_line)
		minilib.factor = 1300 / minilib.nr_line;
	else
		minilib.factor = 1300 / minilib.nr_p_line;
	print_menu(&minilib);
	mlx_loop_hook(minilib.mlx_ptr, &visualize, (void *)&minilib);
	mlx_key_hook(minilib.mlx_ptr, &key_callback, (void *)&minilib);
	mlx_close_hook(minilib.mlx_ptr, &exit_programm, &minilib);
	mlx_scroll_hook(minilib.mlx_ptr, &scroll_callback, &minilib);
	mlx_loop(minilib.mlx_ptr);
	mlx_delete_image(minilib.mlx_ptr, minilib.menu);
	mlx_delete_image(minilib.mlx_ptr, minilib.img);
}

int	main(int argc, char *argv[])
{
	long double	**map;
	t_matrix	**xyzmap;
	t_basic		mlb;

	mlb.zoom = 1;
	mlb.menu = 0;
	if (argc < 2)
		return (0);
	mlb.xyzmap = loadmap(argv[1], &mlb);
	mlx_part(mlb);
	exit_programm(&mlb);
	return (0);
}
