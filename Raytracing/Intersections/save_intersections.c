/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:19 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/03 17:18:09 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../world_building/world.h"

static void	resize_intersections_array(t_c *canvas)
{
	size_t	new_size;
	void	*temp;

	if (canvas->all_intersections.nr_intersections == 0)
	{
		new_size = 1;
		temp = MALLOC(sizeof(t_intersec));
	}
	else
	{
		new_size = canvas->all_intersections.nr_intersection_entries + 1;
		temp = rt_realloc(canvas->all_intersections.intersections,
				sizeof(t_intersec) * new_size);
	}
	if (!temp)
		exit(1);
	canvas->all_intersections.intersections = temp;
}

static double	*clone_times(double *src_times)
{
	double	*new_times;

	new_times = MALLOC(2 * sizeof(double));
	if (!new_times)
		exit(1);
	new_times[0] = src_times[0];
	new_times[1] = src_times[1];
	return (new_times);
}

static void	update_sorted_storage(t_world *world, t_c *canvas, double *times)
{
	double	*new_sorted;
	int		i;

	i = 0;
	while (i < 2)
	{
		if (canvas->all_intersections.nr_intersections % 100 >= 90)
		{
			new_sorted = rt_realloc(world->all_sorted, sizeof(double)
					* (canvas->all_intersections.nr_intersections + 110));
			if (!new_sorted)
				exit(1);
			world->all_sorted = new_sorted;
		}
		world->all_sorted[canvas->all_intersections.nr_intersections]
			= times[i];
		canvas->all_intersections.nr_intersections++;
		i++;
	}
}

void	save_intersections(t_c *canvas, t_intersec *new_intersection,
		t_world *world)
{
	double	*times_copy;

	resize_intersections_array(canvas);
	canvas->all_intersections.intersections
	[canvas->all_intersections.nr_intersection_entries] = *new_intersection;
	times_copy = clone_times(new_intersection->times);
	FREE(new_intersection->times);
	canvas->all_intersections.intersections
	[canvas->all_intersections.nr_intersection_entries].times = times_copy;
	update_sorted_storage(world, canvas, times_copy);
	canvas->all_intersections.nr_intersection_entries++;
	FREE(new_intersection);
}
