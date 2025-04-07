/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lineparsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:29:54 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/27 20:31:09 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_spere_or_light_line(char *line)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 4 && split_count != 5)
	{
		write(2, "sphere or light line in wrong form", 34);
		exit(1);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[3], ',')) != 3)
	{
		write(2, "sphere or light line in wrong form", 34);
		exit(1);
	}
	if (split_count == 5 && (count_split(ft_split(split_on_space[4],
					',')) != 3))
	{
		write(2, "sphere or light line in wrong form", 34);
		exit(1);
	}
}

void	check_camera_line(char *line)
{
	char	**split_on_space;

	split_on_space = ft_split(line, ' ');
	if (count_split(split_on_space) != 4)
	{
		write(2, "camera line in wrong form",
			ft_strlen("camera line in wrong form"));
		exit(1);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3)
	{
		write(2, "camera line in wrong form",
			ft_strlen("camera line in wrong form"));
		exit(1);
	}
}

int	check_plane_line(char *line)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 4 && split_count != 5)
	{
		write(2, "plane line in wrong form",
			ft_strlen("plane line in wrong form"));
		exit(0);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3
		|| count_split(ft_split(split_on_space[3], ',')) != 3)
	{
		write(2, "plane line in wrong form", 24);
		exit(0);
	}
	if (split_count == 5 && (count_split(ft_split(split_on_space[4],
					',')) != 3))
		return (write(2, "plane line in wrong form", 24), 1);
	return (0);
}

void	check_ambient_light_line(char *line)
{
	char	**split_on_space;

	split_on_space = ft_split(line, ' ');
	if (count_split(split_on_space) != 3)
	{
		write(2, "ambient_light line in wrong form",
			ft_strlen("ambient_light line in wrong form"));
		exit(1);
	}
	if (count_split(ft_split(split_on_space[2], ',')) != 3)
	{
		write(2, "ambient_light line in wrong form",
			ft_strlen("ambient_light line in wrong form"));
		exit(1);
	}
}

void	check_cylinder_line(char *line)
{
	char	**split_on_space;
	int		split_count;

	split_on_space = ft_split(line, ' ');
	split_count = count_split(split_on_space);
	if (split_count != 6 && split_count != 7)
	{
		write(2, "cylinder line in wrong form",
			ft_strlen("cylinder line in wrong form"));
		exit(1);
	}
	if (count_split(ft_split(split_on_space[1], ',')) != 3
		|| count_split(ft_split(split_on_space[2], ',')) != 3
		|| count_split(ft_split(split_on_space[5], ',')) != 3)
	{
		write(2, "cylinder line in wrong form", 27);
		exit(1);
	}
	if (split_count == 7 && (count_split(ft_split(split_on_space[6],
					',')) != 3))
	{
		write(2, "cylinder line in wrong form", 27);
		exit(1);
	}
}
