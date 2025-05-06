/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_bumping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:39:09 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:33:00 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	initialize_bump_norm(t_comp *comp, t_intersec *intersection,
		t_world *world, t_bump_norm *bn)
{
	orthogonale_vektoren(comp->normalv, &bn->a, &bn->b, world);
	bn->x = (int)(intersection->u * world->canvas->bumpmap->width)
		% world->canvas->bumpmap->width;
	bn->y = (int)(intersection->v * world->canvas->bumpmap->height)
		% world->canvas->bumpmap->height;
}

static void	compute_bump_gradients(t_world *world, t_bump_norm *bn)
{
	bn->center = get_bumpmap_grayscale(world->canvas->bumpmap, bn->x, bn->y)
		/ 255.0f;
	bn->left = get_bumpmap_grayscale(world->canvas->bumpmap, (bn->x - 1
				+ world->canvas->bumpmap->width)
			% world->canvas->bumpmap->width, bn->y) / 255.0f;
	bn->right = get_bumpmap_grayscale(world->canvas->bumpmap, (bn->x + 1)
			% world->canvas->bumpmap->width, bn->y) / 255.0f;
	bn->top = get_bumpmap_grayscale(world->canvas->bumpmap, bn->x, (bn->y - 1
				+ world->canvas->bumpmap->height)
			% world->canvas->bumpmap->height) / 255.0f;
	bn->bottom = get_bumpmap_grayscale(world->canvas->bumpmap, bn->x, (bn->y
				+ 1) % world->canvas->bumpmap->height) / 255.0f;
	bn->dx = (bn->right - bn->left) * bn->strength;
	bn->dy = (bn->bottom - bn->top) * bn->strength;
}

static void	compute_tangent_vectors(t_comp *comp, t_bump_norm *bn)
{
	bn->tangent_x = cross_product(bn->a, comp->normalv);
	if (magnitude(bn->tangent_x) < 0.01f)
		bn->tangent_x = cross_product(bn->b, comp->normalv);
	bn->tangent_x = normalize(bn->tangent_x);
	bn->tangent_y = cross_product(comp->normalv, bn->tangent_x);
	bn->tangent_y = normalize(bn->tangent_y);
}

static void	adjust_normal_with_bump(t_comp *comp, t_bump_norm *bn)
{
	t_xyzvektor	scaled_x;
	t_xyzvektor	scaled_y;

	scaled_x = scalar_multiplication(bn->tangent_x, bn->dx);
	scaled_y = scalar_multiplication(bn->tangent_y, bn->dy);
	bn->bump_normal = substraction(comp->normalv, addition(scaled_x, scaled_y));
	comp->normalv = normalize(bn->bump_normal);
}

void	change_normal_for_bump(t_comp *comp, t_intersec *intersection,
		t_world *world)
{
	t_bump_norm	bn;

	bn.strength = 1;
	initialize_bump_norm(comp, intersection, world, &bn);
	compute_bump_gradients(world, &bn);
	compute_tangent_vectors(comp, &bn);
	adjust_normal_with_bump(comp, &bn);
}
