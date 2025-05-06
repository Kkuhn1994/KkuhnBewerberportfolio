/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lineparsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:29:54 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 17:42:57 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_light_line(char *line, t_world *world)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 3 && split_count != 4)
	{
		bail("light line in wrong form", 1, world);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3)
	{
		bail("light line in wrong form", 1, world);
	}
	if (split_count == 4 && count_split(ft_split(split_on_space[3], ',')) != 3)
		bail("light line in wrong form", 1, world);
}

void	check_camera_line(char *line, t_world *world)
{
	char	**split_on_space;

	split_on_space = ft_split(line, ' ');
	if (count_split(split_on_space) != 4)
	{
		bail("camera line in wrong form", 1, world);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3)
	{
		bail("camera line in wrong form", 1, world);
	}
}

int	check_plane_line(char *line, t_world *world)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 4)
	{
		bail("plane line in wrong form", 1, world);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3
		|| count_split(ft_split(split_on_space[3], ',')) != 3)
	{
		bail("plane line in wrong form", 1, world);
	}
	return (0);
}

void	check_ambient_light_line(char *line, t_world *world)
{
	char	**split_on_space;

	split_on_space = ft_split(line, ' ');
	if (count_split(split_on_space) != 3)
	{
		bail("ambient_light line in wrong form", 1, world);
	}
	if (count_split(ft_split(split_on_space[2], ',')) != 3)
	{
		bail("ambient_light line in wrong form", 1, world);
	}
}

void	check_cylinder_line(char *line, t_world *world)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 6)
	{
		bail("cylinder line in wrong form", 2, world);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3
		|| count_split(ft_split(split_on_space[5], ',')) != 3)
	{
		bail("cylinder line in wrong form", 2, world);
	}
}
