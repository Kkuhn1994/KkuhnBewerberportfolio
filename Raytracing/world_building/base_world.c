/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:33:02 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/03 17:52:14 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_shape	*new_shape(int type)
{
	t_shape	*shape;

	shape = (t_shape *)MALLOC(sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->type = type;
	shape->origin = set_vector(0, 0, 0, 1);
	shape->default_transformation = get_identity_matrix();
	shape->material = default_material();
	shape->id = g_globalid++;
	shape->minimum = -INFINITY;
	shape->maximum = INFINITY;
	shape->closed = false;
	if (type == 0)
		shape->radius = 1;
	else if (type == 1)
		shape->normal = set_vector(0, 1, 0, 0);
	else if (type == 2)
		shape->radius = 1;
	return (shape);
}

t_world	*get_world(int shapes)
{
	t_world	*world;

	world = (t_world *)MALLOC(sizeof(t_world));
	if (!world)
		return (NULL);
	world->canvas = (t_c *)calloc(sizeof(t_c), 1);
	if (!world->canvas)
		return (FREE(world), NULL);
	world->env = (t_env *)MALLOC(sizeof(t_env));
	if (!world->env)
		return (FREE(world->canvas), FREE(world), NULL);
	world->shapes = (t_shape **)MALLOC(sizeof(t_shape *) * shapes);
	if (!world->shapes)
		return (FREE(world->env), FREE(world->canvas), FREE(world), NULL);
	world->ambient = MALLOC(sizeof(t_xyzvektor));
	if (!world->ambient)
		return (FREE(world->shapes), FREE(world->env), FREE(world->canvas),
			FREE(world), NULL);
	*(world->ambient) = set_vector(0, 0, 0, 0);
	world->ambient_intensity = 0;
	world->nr_shapes = 0;
	world->all_sorted = NULL;
	return (world);
}

void	collect_garbage(void)
{
	t_list	*lst;
	void	*next;
	void	*to_free;

	lst = get_adress_of_list();
	while (lst)
	{
		next = lst->next;
		if (lst->content)
		{
			free(lst->content);
			lst->content = NULL;
		}
		to_free = lst;
		free(to_free);
		lst = next;
	}
}

void	free_world(t_world *world)
{
	if (!world)
		return ;
	if (world->canvas)
		FREE(world->canvas->img);
	if (world->env)
		FREE(world->env);
	if (world->ambient)
		FREE(world->ambient);
	if (world->camera)
	{
		free_double_ptr(world->camera->transform, 4);
		FREE(world->camera);
	}
	while (world->nr_shapes--)
	{
		free_double_ptr(world->shapes[world->nr_shapes]->default_transformation,
			4);
		FREE(world->shapes[world->nr_shapes]);
	}
	FREE(world->shapes);
	FREE(world->canvas);
	FREE(world->all_sorted);
	FREE(world);
	free_list();
}
