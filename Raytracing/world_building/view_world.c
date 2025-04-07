/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:08:08 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/26 16:16:01 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_xyzvektor	prepare_pixel(t_camera *cam, int px, int py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = (px + 0.5) * cam->pixel_size;
	yoffset = (py + 0.5) * cam->pixel_size;
	world_x = cam->half_width - xoffset;
	world_y = cam->half_height - yoffset;
	return (set_vector(world_x, world_y, -1, 1));
}

t_ray	ray_for_pixel(t_camera *cam, int px, int py)
{
	t_ray		ray;
	t_xyzvektor	pixel;
	t_xyzvektor	origin;
	double		**inv;

	pixel = prepare_pixel(cam, px, py);
	origin = set_vector(0, 0, 0, 1);
	inv = invert_matrix(cam->transform, 4);
	pixel = multiply_vector_and_matrix(pixel, inv);
	origin = multiply_vector_and_matrix(origin, inv);
	ray.origin = origin;
	if (inv)
		free_double_ptr(inv, 4);
	ray.direction = normalize(substraction(pixel, origin));
	return (ray);
}

t_camera	*camera(int hsize, int vsize, double field_of_view)
{
	t_camera	*cam;
	double		half_view;
	double		aspect;

	cam = MALLOC(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->hsize = hsize;
	cam->vsize = vsize;
	cam->field_of_view = field_of_view;
	half_view = tan(cam->field_of_view / 2);
	aspect = (double)cam->hsize / (double)cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
	return (cam);
}

double	**view_transform(t_xyzvektor from, t_xyzvektor to, t_xyzvektor up)
{
	t_xyzvektor	forward;
	t_xyzvektor	left;
	t_xyzvektor	true_up;
	double		**orientation;
	double		**translation_mat;

	forward = normalize(substraction(to, from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	orientation = matrix(left, true_up, forward, set_vector(0, 0, 0, 1));
	translation_mat = translation(-from.x, -from.y, -from.z);
	if (!orientation || !translation_mat)
		return (NULL);
	return (multiply_matrix(orientation, translation_mat));
}

mlx_image_t	*render_image(t_camera *cam, t_world *world)
{
	mlx_image_t	*image;
	int			x;
	int			y;
	t_ray		ray;
	t_xyzvektor	color;

	image = mlx_new_image(world->canvas->mlx_ptr, cam->hsize, cam->vsize);
	y = 0;
	while (y < cam->vsize)
	{
		x = 0;
		while (x < cam->hsize)
		{
			ray = ray_for_pixel(cam, x, y);
			color = color_at(world, ray);
			mlx_put_pixel(image, x, y, get_color_from_tuple(color));
			x++;
		}
		y++;
	}
	printf("image done cooking\n");
	return (image);
}
