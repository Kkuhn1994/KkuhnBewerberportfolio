/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:18:06 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 19:05:14 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	**alloc(char **splitted_map, t_basic *mlb, int i)
{
	int			j;
	char		**split;
	t_matrix	**map;

	while (splitted_map[i] != 0)
		i ++;
	map = malloc (i * sizeof(t_matrix *));
	mlb->map = malloc (i * sizeof(t_matrix *));
	mlb->int_per_line = malloc (i * sizeof(int));
	mlb->nr_line = i + 1;
	i = 0;
	while (splitted_map[i] != 0)
	{
		j = 0;
		split = ft_split(splitted_map[i], ' ');
		while (split[j] != 0)
			j ++;
		map[i] = malloc (j * sizeof(t_matrix));
		mlb->map[i] = malloc (j * sizeof(t_matrix));
		mlb->int_per_line[i] = j;
		i ++;
		free_map3(split);
	}
	return (map);
}

char	*color(char *string)
{
	char	*color;

	color = ft_strnstr(string, ",", ft_strlen(string));
	if (color == NULL)
		return ("0xFFFFFF");
	return (&color[1]);
}

t_matrix	**init_values(char **splittedmap, t_basic *mlb, t_matrix **map)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (splittedmap[i] != 0)
	{
		j = 0;
		split = ft_split(splittedmap[i], ' ');
		while (split[j] != 0)
		{
			mlb->map[i][j] = ft_atoi(split[j]);
			map[i][j].x = (long double)(-(mlb->int_per_line[0]
						+ 1) / 2 + j + 1);
			map[i][j].y = (long double)(mlb->nr_line / 2 - i - 1);
			map[i][j].z = ft_atoi(split[j]);
			map[i][j].color = color(split[j]);
			j ++;
		}
		free_map3(split);
		i ++;
	}
	return (map);
}

t_matrix	**loadmap(char *file, t_basic *mlb)
{
	char		*map;
	char		**splitted_map;
	t_matrix	**xyzmap;
	int			i;

	i = 0;
	mlb->nr_p_line = INT_MAX;
	map = readfile(file, mlb[0]);
	splitted_map = ft_split(map, '\n');
	xyzmap = alloc(splitted_map, mlb, 0);
	xyzmap = init_values(splitted_map, mlb, xyzmap);
	while (i < mlb->nr_line - 1)
	{
		if (mlb->int_per_line[i] < mlb->nr_p_line)
			mlb->nr_p_line = mlb->int_per_line[i];
		i ++;
	}
	i = 0;
	free(map);
	free_map3(splitted_map);
	return (xyzmap);
}
