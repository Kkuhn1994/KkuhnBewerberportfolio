/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:57:51 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:46:28 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_common_shape(char **split, double pos[3], double rgb[3],
		t_world *world)
{
	char	**pos_split;
	char	**rgb_split;

	pos_split = ft_split(split[1], ',');
	if (!pos_split)
		return (1);
	rgb_split = ft_split(split[3], ',');
	if (!rgb_split)
		return (ft_free_split(pos_split), 1);
	if (split[0][0] == 'c')
	{
		ft_free_split(rgb_split);
		rgb_split = ft_split(split[5], ',');
	}
	if (!parse_xyz(pos_split, pos, 0, world))
		return (ft_free_split(pos_split), ft_free_split(rgb_split), 1);
	if (!parse_xyz(rgb_split, rgb, 0, world))
		return (ft_free_split(pos_split), ft_free_split(rgb_split), 1);
	rgb[0] /= 255;
	rgb[1] /= 255;
	rgb[2] /= 255;
	if (rgb[0] < 0 || rgb[0] > 1 || rgb[1] < 0 || rgb[1] > 1 || rgb[2] < 0
		|| rgb[2] > 1)
		return (ft_free_split(pos_split), ft_free_split(rgb_split), 1);
	return (ft_free_split(pos_split), ft_free_split(rgb_split), 0);
}

char	**checker_parsing(char **split, int type)
{
	int		i;
	char	**split_split;

	i = 0;
	while (split[i++])
		;
	if ((i != 6 && (type == 0 || type == 1)) || (i != 8 && (type == 2
				|| type == 3)))
		return (NULL);
	if (type == 0 || type == 1)
		i = 4;
	else
		i = 6;
	split_split = ft_split(split[i], ',');
	i = 0;
	while (split_split[i++])
		;
	if (i != 4)
		return (NULL);
	return (split_split);
}

void	add_checker(t_world *world, char **split, int type)
{
	char	**split_split;

	split_split = checker_parsing(split, type);
	if (!split_split || !(*split_split))
		return ;
	world->shapes[world->nr_shapes
		- 1]->material.color2 = set_vector(budget_ft_atof(split_split[0]) / 255,
			budget_ft_atof(split_split[1]) / 255, budget_ft_atof(split_split[2])
			/ 255, 0);
	world->shapes[world->nr_shapes - 1]->material.checker_enable = true;
}

int	parse_normal_vector(char **split, double normal[3], t_world *world)
{
	char	**normal_split;
	int		result;

	normal_split = ft_split(split[2], ',');
	if (!normal_split)
		return (1);
	result = parse_xyz(normal_split, normal, 1, world) && normal[0] >= -1
		&& normal[0] <= 1 && normal[1] >= -1 && normal[1] <= 1
		&& normal[2] >= -1 && normal[2] <= 1;
	ft_free_split(normal_split);
	return (!result);
}

void	check_sphere_line(char *line, t_world *world)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 4 && split_count != 5)
		bail("sphere line in wrong form", 1, world);
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[3], ',')) != 3)
	{
		bail("sphere line in wrong form", 1, world);
	}
	if (split_count == 5 && count_split(ft_split(split_on_space[4], ',')) == 1)
		load_bumpmap(split_on_space[4], world);
}
