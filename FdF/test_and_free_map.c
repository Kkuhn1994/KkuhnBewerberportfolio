/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_and_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:43 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/21 19:06:07 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin3(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == 0)
		return (ft_strdup(s2));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i ++;
	}
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i ++;
		j ++;
	}
	result[i] = 0;
	free(s1);
	return (result);
}

char	*readfile(char *file, t_basic mlb)
{
	int		fd;
	int		buffersize;
	char	buffer[2];
	char	*map;

	map = 0;
	fd = open(file, O_RDONLY);
	buffersize = read(fd, buffer, 1);
	buffer[1] = 0;
	while (buffersize > 0)
	{
		map = ft_strjoin3(map, buffer);
		buffersize = read(fd, buffer, 1);
	}
	return (map);
}

void	free_map(long double **map, int nr_line)
{
	int	i;

	i = 0;
	if (map == 0)
		return ;
	while (i != nr_line - 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map2(t_matrix **map, int nr_line)
{
	int	i;

	i = 0;
	if (map == 0)
		return ;
	while (i != nr_line - 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map3(char **map)
{
	int	i;

	i = 0;
	if (map == 0)
		return ;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
