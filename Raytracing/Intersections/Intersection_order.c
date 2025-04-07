/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersection_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:10:24 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:19:49 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_smallest_positive_value(t_intersec *intersection1)
{
	if (intersection1->times[0] < 0 && intersection1->times[1] < 0)
		return (INT_MAX);
	if (intersection1->times[0] < 0)
		return (intersection1->times[1]);
	if (intersection1->times[1] < 0)
		return (intersection1->times[0]);
	if (intersection1->times[0] < intersection1->times[1])
		return (intersection1->times[0]);
	else
		return (intersection1->times[1]);
}

bool	intersection_comparison_1_bigger_2(t_intersec *intersection1,
		t_intersec *intersection2)
{
	double	smallest_time_of_1;
	double	smallest_time_of_2;

	if (intersection1->times == NULL && intersection2->times == NULL)
		return (false);
	if (intersection1->times == NULL)
		return (true);
	if (intersection2->times == NULL)
		return (false);
	smallest_time_of_1 = get_smallest_positive_value(intersection1);
	smallest_time_of_2 = get_smallest_positive_value(intersection2);
	if (smallest_time_of_1 < smallest_time_of_2)
		return (false);
	else
		return (true);
}

int	setup_new_intersect(t_c *canvas, t_intersec *new_intersection,
		int nr_intersec, t_intersec *intersections_sorted)
{
	canvas->all_intersections.nr_intersections = nr_intersec;
	intersections_sorted = MALLOC(nr_intersec * sizeof(t_intersec));
	if (!intersections_sorted)
		return (-1);
	if (nr_intersec == 1)
		return (canvas->all_intersections.intersections = new_intersection,
			canvas->all_intersections.nr_intersections += 1, 0);
	return (1);
}

int	save_intersection(t_c *canvas, t_intersec *new_intersection, int i, int j)
{
	int			nr_intersec;
	t_intersec	*old_intersections;
	t_intersec	*intersections_sorted;
	bool		new_intersection_sorted;

	new_intersection_sorted = false;
	old_intersections = canvas->all_intersections.intersections;
	nr_intersec = canvas->all_intersections.nr_intersections + 1;
	if (!setup_new_intersect(canvas, new_intersection, nr_intersec,
			intersections_sorted))
		return (-1);
	while (++i < nr_intersec)
	{
		if ((intersection_comparison_1_bigger_2(&old_intersections[j],
					new_intersection) && !new_intersection_sorted)
			|| (i == nr_intersec - 1 && !new_intersection_sorted))
		{
			intersections_sorted[i] = *new_intersection;
			new_intersection_sorted = true;
		}
		else
			intersections_sorted[i] = old_intersections[j++];
	}
	canvas->all_intersections.intersections = intersections_sorted;
	return (0);
}
