/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:23:11 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 15:32:29 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "structs.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

void		clean_memory(void);
// intersection
int			save_intersection(t_c *canvas, t_intersec *new_intersection, int i,
				int j);
t_intersec	*intersect(t_shape *shape, t_ray ray);
t_intersec	*cylinder_intersect(t_intersec *result, t_ray ray,
				t_shape cylinder);
t_xyzvektor	ray_position(t_ray ray, double time);
double		get_smallest_positive_value(t_intersec *intersection1);
t_xyzvektor	identify_hit(t_all_intersec all_intersections);
t_ray		transform(t_ray ray, double **transformation);
t_intersec	*cone_intersect(t_intersec *result, t_ray ray, t_shape cylinder);
void		cap_bottom(t_intersec *result, t_ray ray, t_shape shape);
void		cap_top(t_intersec *result, t_ray ray, t_shape shape);
// trasnformation
double		**translation(double x, double y, double z);
double		**scaling(double x, double y, double z);
double		**rotation_x(double degree);
double		**rotation_y(double degree);
double		**rotation_z(double degree);
double		**shearing(double *proportions);

// vector operations
t_xyzvektor	cross_product(t_xyzvektor a, t_xyzvektor b);
double		dot_product(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	substraction(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	addition(t_xyzvektor a, t_xyzvektor b);
double		magnitude(t_xyzvektor a);
t_xyzvektor	normalize(t_xyzvektor a);
t_xyzvektor	negate_tuple(t_xyzvektor a);
t_xyzvektor	scalar_multiplication(t_xyzvektor a, double b);
t_xyzvektor	scalar_division(t_xyzvektor a, double b);
t_xyzvektor	hadamard_product(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	set_vector(double x, double y, double z, double w);

// matrix operations
double		**multiply_matrix(double **a, double **b);
t_xyzvektor	multiply_vector_and_matrix(t_xyzvektor a, double **b);
double		**get_identity_matrix(void);
int			compare_matrix(double **a, double **b, int size);
double		**transpose_matrix(double **a, int size);
double		get_minor(double **a, int i, int j, int size);
double		get_determinante_of_2(double **a);
double		*extract_submatrix_row(double *a, int ii, int size);
double		**get_submatrix(double **a, int ii, int jj, int size);
double		**invert_matrix(double **a, int size);
double		get_cofactor(double **a, int i, int j, int size);
double		get_determinant_of_bigger_matrix(double **a, int size);
double		get_determinante_of_3x3(double **a);
void		create_rotation_matrix(t_xyzvektor normal, double **rotation);
void		transform_ray(t_ray *ray, double **rotation);

// color operations
uint32_t	get_color_from_tuple(t_xyzvektor color);
void		init_canvas(t_c *canvas);
t_ray		init_ray(void);

// utils
t_light		default_light(void);
t_material	default_material(void);
void		free_double_ptr(double **a, int size);
void		show_matrix(double **a, int size);
void		*ft_malloc(int size);
void		ft_free(void *data);
void		bail(char *str, int code, t_world *world);

// sphere
void		set_transform(t_shape *shape, double **translation);
t_material	default_material(void);
void		uv_of_sphere(t_intersec *intersect, t_comp *comps, t_shape *shape,
				t_world world);
void		change_normal_for_bump(t_comp *comp, t_intersec *intersection,
				t_world *world);
int			get_bumpmap_grayscale(mlx_texture_t *texture, int x, int y);
void		orthogonale_vektoren(t_xyzvektor x, t_xyzvektor *y, t_xyzvektor *z,
				t_world *world);

// ray
t_xyzvektor	calculate_reflection(t_xyzvektor in, t_xyzvektor normale);
t_xyzvektor	calculate_normale(t_shape shape, t_xyzvektor point);

void		visualize(void *input);
int			min_of(int a, int b);
uint32_t	get_color_from_tuple(t_xyzvektor color);
t_xyzvektor	get_color_from_uint(uint32_t color);
t_xyzvektor	point_of_intersection(t_intersec *intersec, t_ray ray);

t_xyzvektor	set_black(void);
t_light		default_light(void);
t_material	default_material(void);

t_xyzvektor	lightning(t_comp comp, t_c canvas, bool *in_shadow, t_world *world);
t_xyzvektor	calculate_reflection(t_xyzvektor in, t_xyzvektor normale);
t_shape		*new_shape(int type);
t_xyzvektor	calculate_wall_coordinate(int x, int y, double pixel_size,
				double half);
t_xyzvektor	pattern_at(t_shape shape, t_xyzvektor point);
t_xyzvektor	get_color(t_c canvas, t_shape shape, long double x, long double y);
void		cut_cylinder(t_intersec *result, t_ray ray, t_shape shape);

#endif