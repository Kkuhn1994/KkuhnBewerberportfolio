/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:33:24 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 12:31:02 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../miniRT.h"
# include "../structs.h"

double		**multiply_matrix(double **a, double **b);
t_xyzvektor	calculate_normale(t_shape shape, t_xyzvektor point);
t_xyzvektor	negate_tuple(t_xyzvektor a);
t_xyzvektor	point_of_intersection(t_intersec *intersec, t_ray ray);
t_xyzvektor	set_black(void);
t_xyzvektor	cross_product(t_xyzvektor a, t_xyzvektor b);
double		**get_identity_matrix(void);
t_xyzvektor	substraction(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	normalize(t_xyzvektor a);
t_xyzvektor	multiply_vector_and_matrix(t_xyzvektor a, double **b);
double		**invert_matrix(double **a, int size);
t_xyzvektor	set_vector(double x, double y, double z, double w);
double		**translation(double x, double y, double z);
t_material	default_material(void);
void		init_canvas(t_c *canvas);
double		**scaling(double x, double y, double z);
double		**rotation_x(double degree);
double		**rotation_y(double degree);
double		**rotation_z(double degree);
uint32_t	get_color_from_tuple(t_xyzvektor color);

t_world		*get_world(int shapes);
void		free_world(t_world *world);
int			intersect_world(t_world *world, t_ray ray);
t_intersec	*intersect(t_shape *shape, t_ray ray);
t_comp	prepare_computations(t_intersec *intersection, t_ray ray,
	t_shape *shape, t_world *world);
t_xyzvektor	shade_hit(t_world *world, t_comp comp, t_shape shape);
t_xyzvektor	color_at(t_world *world, t_ray ray);
double		**view_transform(t_xyzvektor from, t_xyzvektor to, t_xyzvektor up);
t_camera	*camera(int hsize, int vsize, double field_of_view);
t_ray		ray_for_pixel(t_camera *cam, int px, int py);
mlx_image_t	*render_image(t_camera *cam, t_world *world);
void		find_nearest_intersection(t_intersec *intersections,
				int nr_intersections, t_intersec **intersec_to_use,
				int *shape_to_use);
t_shape		*new_shape(int type);
double		dotProduct(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	addition(t_xyzvektor a, t_xyzvektor b);
t_xyzvektor	scalarMultiplication(t_xyzvektor a, double b);
t_xyzvektor	lightning(t_comp comp, t_c canvas,
	bool *in_shadow);
t_ray		init_ray(void);
double		magnitude(t_xyzvektor a);
int			parse_input(char *file_name, t_world *world);
void		free_double_ptr(double **a, int size);
void		empty_intersections(t_c *canvas);
double		**matrix(t_xyzvektor left, t_xyzvektor true_up, t_xyzvektor forward,
				t_xyzvektor t);
t_xyzvektor	calculate_normale(t_shape shape, t_xyzvektor point);
t_xyzvektor	hit(t_all_intersec all_intersections, t_shape *shade);
void		empty_intersections(t_c *canvas);
// test
bool		*is_shadowed(t_world *world, t_xyzvektor point, t_shape shape);
void	sphere_ray_transform(t_shape shape, t_ray ray);
int get_bumpmap_grayscale(mlx_texture_t *texture, int x, int y);
void load_bumpmap(char *path, t_world *world);

#endif