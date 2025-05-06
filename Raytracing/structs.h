/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:27 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 14:12:32 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159265358979323846
# define EPSILON 0.00001

typedef struct s_koord
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_xyzvektor;

typedef struct s_point_data
{
	t_xyzvektor		position;
	t_xyzvektor		velocity;
}					t_point;

typedef struct s_environment
{
	t_xyzvektor		wind;
	t_xyzvektor		gravity;
}					t_env;

typedef struct s_ray
{
	t_xyzvektor		origin;
	t_xyzvektor		direction;

}					t_ray;

typedef struct s_material
{
	uint32_t		color;
	double			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	bool			checker_enable;
	t_xyzvektor		color2;
}					t_material;

typedef struct s_shape
{
	int				id;
	t_xyzvektor		origin;
	double			**default_transformation;
	double			**inverse;
	t_material		material;
	int				type;
	double			radius;
	t_xyzvektor		normal;
	double			minimum;
	double			maximum;
	bool			closed;
}					t_shape;

typedef struct s_intersect
{
	t_ray			ray;
	double			*times;
	long double		u;
	long double		v;
	int				object_id;
}					t_intersec;

typedef struct s_intersections
{
	t_intersec		*intersections;
	size_t			nr_intersections;
	size_t			nr_intersection_entries;
	size_t			allocated_intersections;
}					t_all_intersec;

typedef struct s_pointlight
{
	t_xyzvektor		color;
	double			brightness;
	t_xyzvektor		position;
}					t_light;

typedef struct s_reflection_data_store
{
	t_xyzvektor		effective_color;
	t_xyzvektor		materialcolor;
	t_xyzvektor		lightsourcecolor;
	t_xyzvektor		light_vector;
	t_xyzvektor		ambient;
	t_xyzvektor		diffuse;
	t_xyzvektor		specular;
	double			reflect_dot_eye;
	double			factor;
	double			shadow_factor;
	double			light_dot_normale;
	t_xyzvektor		reflectv;
}					t_store;

typedef struct s_canvas
{
	int				width;
	int				height;
	int				num_lights;
	double			pixel_size;
	double			half_size;
	double			worldheight;
	mlx_image_t		*img;
	mlx_t			*mlx_ptr;
	t_all_intersec	all_intersections;
	t_light			*lightsource;
	t_xyzvektor		normale;
	t_xyzvektor		eyevector;
	mlx_texture_t	*bumpmap;
	mlx_image_t		*bumpmapcolor;
	mlx_image_t		*image_to_free;
}					t_c;

typedef struct s_camera
{
	int				hsize;
	int				vsize;
	double			pixel_size;
	double			field_of_view;
	double			**transform;
	double			half_width;
	double			half_height;
}					t_camera;

typedef struct s_world
{
	t_shape			**shapes;
	long			nr_shapes;
	t_c				*canvas;
	double			*all_sorted;
	t_env			*env;
	t_xyzvektor		*ambient;
	double			ambient_intensity;
	t_camera		*camera;

}					t_world;

typedef struct s_comp
{
	double			t;
	t_shape			*object;
	t_xyzvektor		point;
	t_xyzvektor		over_point;
	t_xyzvektor		eyev;
	t_xyzvektor		normalv;
	t_xyzvektor		reflectv;
	bool			inside;
	long double		u;
	long double		v;
}					t_comp;

typedef struct s_bump_map_normal
{
	t_xyzvektor	a;
	t_xyzvektor	b;
	int			x;
	int			y;
	float		center;
	float		left;
	float		right;
	float		top;
	float		bottom;
	float		strength;
	float		dx;
	float		dy;
	t_xyzvektor	tangent_x;
	t_xyzvektor	tangent_y;
	t_xyzvektor	bump_normal;
}	t_bump_norm;

#endif