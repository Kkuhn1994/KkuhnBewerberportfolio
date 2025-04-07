/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:43:31 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 17:12:45 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <inttypes.h>

t_xyzvektor	calculate_reflection(t_xyzvektor in, t_xyzvektor normale)
{
	double		dot;
	t_xyzvektor	n;

	dot = 2 * dot_product(in, normale);
	n = scalar_multiplication(normale, dot);
	return (normalize(substraction(in, n)));
}

static double	get_shadow_factor(bool *in_shadow, t_c canvas)
{
	int		i;
	double	shadow_factor;

	shadow_factor = 0.1;
	i = -1;
	while (++i < canvas.num_lights)
	{
		if (in_shadow[i])
			shadow_factor += 0.5;
	}
	if (shadow_factor > 1)
		shadow_factor = 1;
	return (shadow_factor);
}

static t_xyzvektor	clamp_color(t_xyzvektor color)
{
	return ((t_xyzvektor){fmax(0, fmin(1, color.x)), fmax(0, fmin(1, color.y)),
		fmax(0, fmin(1, color.z))});
}

t_xyzvektor	get_color(t_c canvas, t_shape shape, long double x, long double y)
{
    t_xyzvektor	color;
	int ix = (int)x;
	int iy = (int)y;

	// if (x < 0)
	// 	x = 0;
	// else if (x >= canvas.bumpmapcolor->width)
	// 	x = canvas.bumpmapcolor->width - 1;
	// if (y < 0)
	// 	y = 0;
	// else if (y >= canvas.bumpmapcolor->height)
	// 	y = canvas.bumpmapcolor->height - 1;
    if(canvas.bumpmapcolor && shape.type == 0)
    {
        int pixel_offset = iy * (canvas.bumpmapcolor->width * 4 / sizeof(int)) + ix;
        uint32_t pixel = ((uint32_t *)canvas.bumpmapcolor->pixels)[pixel_offset];
		color.w = ((pixel >> 24) & 0xFF) / 255.0;
		color.z = ((pixel >> 16) & 0xFF) / 255.0;
		color.y = ((pixel >> 8)  & 0xFF) / 255.0;
		color.x = (pixel & 0xFF) / 255.0;
        return color;
    }
    else
        return get_color_from_uint(shape.material.color);
}

t_xyzvektor	lightning(t_comp comp, t_c canvas,
		bool *in_shadow)
{
	t_store		store;
	double		light_dot_normale;
	double		shadow_factor;
	int			i;
	t_xyzvektor	result;
	t_xyzvektor	scaled_spec;
	t_xyzvektor	final;
	t_shape shape = *(comp.object);
	t_xyzvektor point = comp.over_point;
	

	i = -1;
	store.diffuse = set_black();
	store.specular = set_black();
	store.ambient = set_black();
	result = set_black();
	if (shape.material.checker_enable)
		store.materialcolor = pattern_at(shape, point);
	else
		store.materialcolor = get_color(canvas, shape, comp.u, comp.v);
	shadow_factor = get_shadow_factor(in_shadow, canvas);
	store.ambient = scalar_multiplication(store.materialcolor,
			shape.material.ambient);
	while (++i < canvas.num_lights)
	{
		store.lightsourcecolor = canvas.lightsource[i].color;
		store.effective_color = hadamard_product(store.materialcolor,
				store.lightsourcecolor);
		store.light_vector = normalize(substraction(canvas.lightsource[i].position,
					point));
		light_dot_normale = dot_product(store.light_vector, canvas.normale);
		if (light_dot_normale >= 0)
		{
			store.diffuse = scalar_multiplication(store.materialcolor,
					shape.material.diffuse * light_dot_normale);
			result = addition(result, scalar_multiplication(store.diffuse, 1.0
						- shadow_factor));
			store.reflectv = calculate_reflection(store.light_vector,
					canvas.normale);
			store.reflect_dot_eye = dot_product(store.reflectv,
					negate_tuple(canvas.eyevector));
			if (store.reflect_dot_eye > 0)
			{
				store.factor = pow(store.reflect_dot_eye,
						shape.material.shininess);
				scaled_spec = scalar_multiplication(store.lightsourcecolor,
						shape.material.specular * store.factor * (1.0
							- shadow_factor));
				store.specular = addition(store.specular, scaled_spec);
			}
		}
	}
	final = addition(store.ambient, addition(result, store.specular));
	final.x = fmax(0.0, fmin(1.0, final.x));
	final.y = fmax(0.0, fmin(1.0, final.y));
	final.z = fmax(0.0, fmin(1.0, final.z));
	FREE(in_shadow);
	return (clamp_color(final));
}

// reflection_test
// int main(void)
// {
// 	t_sphere sphere = new_sphere();
// 	t_c canvas;
// 	t_xyzvektor point;
// 	t_xyzvektor eye;
// 	uint32_t colors;
// 	t_xyzvektor color;
// 	t_xyzvektor normale;

// 	init_canvas(&canvas);
// 	point.x = 0;
// 	point.y = 0;
// 	point.z = 0;
// 	point.w = 0;

// 	eye.x = 0;
// 	eye.y = 0;
// 	eye.z = - 1;

// 	normale.x = 0;
// 	normale.y = 0;
// 	normale.z = -1;

// 	canvas.eyevector = substraction(eye, point);
// 	canvas.normale = normale;

// 	printf("%f %f %f\n", canvas.eyevector.x, canvas.eyevector.y,
//		canvas.eyevector.z);
// 	color = lightning(sphere.material, point, canvas);

// 	printf("%f %f %f\n" , color.x, color.y, color.z);
// }
