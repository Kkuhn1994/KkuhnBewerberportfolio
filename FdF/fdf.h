/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:37:32 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 19:06:06 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/fcntl.h>
# include <math.h>

typedef struct xyz
{
	long double	x;
	long double	y;
	long double	z;
	char		*color;
}	t_matrix;

typedef struct bas
{
	float	l;
	float	r;
	float	b;
	float	t;
	float	n;
	float	f;	
}	t_boundaries;

typedef struct basic
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
	mlx_image_t	*menu;
	int			*int_per_line;
	int			nr_line;
	int			*p1;
	int			*p2;
	int			delta[2];
	int			sign[2];
	int			error[2];
	int			xrotate;
	int			yrotate;
	int			zrotate;
	double		lat_rad;
	double		lon_rad;
	double		cld;
	double		sp1_rad;
	double		sp2_rad;
	double		n;
	double		f;
	int			endian;
	int			bpp;
	int			size_line;
	long double	factor;
	float		null_punkt[2];
	int			nr_p_line;
	long double	xy[2];
	long double	**map;
	float		zoom;
	t_matrix	**xyzmap;
	int			projection;

}	t_basic;

void		free_map(long double **map, int nr_line);
void		free_map2(t_matrix **map, int nr_line);
char		*ft_strjoin3(char *s1, char *s2);
t_matrix	**loadmap(char *file, t_basic *mlb);
void		rotate_z(t_basic *mlb, int angl);
void		rotate_x(t_basic *mlb, int angl);
void		rotate_y(t_basic *mlb, int angl);
t_matrix	**convert_to_matrix(long double **map, int x, int y);
void		key_callback(mlx_key_data_t keydata, void *ml);
void		scroll_callback(double xdelta, double ydelta, void *param);
int			nextpixel(int *x, int *y, int xmax, int ymax);
void		exit_programm(void *input);
void		change_mode(t_basic *mlb);
int			*coord_calc(t_matrix a, t_basic *mlb);
int			*conic_projection(t_matrix point, t_basic *mlb);
void		visualize(void *ml);
char		*readfile(char *file, t_basic mlb);
void		print_menu(t_basic *mlb);
void		translate_map(t_basic *mlb, float factor);
void		free_map3(char **map);

#endif