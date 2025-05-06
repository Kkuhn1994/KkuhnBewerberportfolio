/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:43:31 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 23:07:50 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

	shadow_factor = 0.2;
	i = -1;
	while (++i < canvas.num_lights)
	{
		if (in_shadow[i])
			shadow_factor += 0.4;
	}
	if (shadow_factor > 1)
		shadow_factor = 1;
	return (shadow_factor);
}

void	add_light(t_store *store, t_shape shape, t_xyzvektor *result,
		t_c canvas)
{
	t_xyzvektor	scaled_spec;

	store->diffuse = scalar_multiplication(store->materialcolor,
			shape.material.diffuse * store->light_dot_normale);
	*result = addition(*result, scalar_multiplication(store->diffuse, 1.0
				- store->shadow_factor));
	store->reflectv = calculate_reflection(store->light_vector, canvas.normale);
	store->reflect_dot_eye = dot_product(store->reflectv,
			negate_tuple(canvas.eyevector));
	if (store->reflect_dot_eye > 0)
	{
		store->factor = pow(store->reflect_dot_eye, shape.material.shininess);
		scaled_spec = scalar_multiplication(store->lightsourcecolor,
				shape.material.specular * store->factor * (1.0
					- store->shadow_factor));
		store->specular = addition(store->specular, scaled_spec);
	}
}

t_xyzvektor	each_light(t_store *store, t_shape shape, t_c canvas,
		t_xyzvektor point)
{
	t_xyzvektor	result;
	int			i;

	i = -1;
	result = set_black();
	while (++i < canvas.num_lights)
	{
		if (store->shadow_factor > 0.2)
			break ;
		store->lightsourcecolor = canvas.lightsource[i].color;
		store->effective_color = hadamard_product(store->materialcolor,
				store->lightsourcecolor);
		store->light_vector = normalize(substraction
				(canvas.lightsource[i].position, point));
		store->light_dot_normale = dot_product(store->light_vector,
				canvas.normale);
		if (store->light_dot_normale >= 0)
			add_light(store, shape, &result, canvas);
	}
	return (result);
}

t_xyzvektor	lightning(t_comp comp, t_c canvas, bool *in_shadow, t_world *world)
{
	t_store		store;
	t_xyzvektor	result;
	t_xyzvektor	final;
	t_shape		shape;

	shape = *(comp.object);
	shape = *(comp.object);
	store.diffuse = set_black();
	store.specular = set_black();
	store.ambient = set_black();
	store.materialcolor = pattern_at(shape, comp.over_point);
	store.materialcolor = get_color(canvas, shape, comp.u, comp.v);
	store.shadow_factor = get_shadow_factor(in_shadow, canvas);
	store.ambient = scalar_multiplication(store.materialcolor,
			shape.material.ambient);
	store.ambient = hadamard_product(scalar_multiplication(*world->ambient,
				world->ambient_intensity), store.ambient);
	if (*in_shadow == true)
		result = set_black();
	else
		result = each_light(&store, shape, canvas, comp.over_point);
	return (final = addition(store.ambient, result), final.x = fmax(0.0,
			fmin(1.0, final.x)), final.y = fmax(0.0, fmin(1.0, final.y)),
		final.z = fmax(0.0, fmin(1.0, final.z)), final);
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
