/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:54:58 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 14:11:58 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	look_for_double_uppercase(char **input, int a, int c, t_world *world)
{
	int	l;

	l = 0;
	while (*input)
	{
		if (*input[0] == 'A')
			a++;
		if (*input[0] == 'C')
			c++;
		if (*input[0] == 'L')
			l++;
		else if (*input[0] >= '0' && *input[0] <= '9')
		{
			bail("first characters needs to be char", 1, world);
		}
		input++;
	}
	if (a != 1 || c != 1 || l != 1)
	{
		bail("wrong number of cameras, lights or ambient light", 1, world);
	}
}

char	**process_file(char *file_name, t_world *world)
{
	char	**input;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (ft_strncmp(&(file_name[ft_strlen(file_name) - 3]), ".rt", 3) != 0)
		bail("only .rt files", 1, world);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		bail("file not found", 1, world);
	input = ft_malloc(1000 * sizeof(char *));
	if (!input)
		return (NULL);
	while (budget_get_next_line(fd, &line) > 0)
	{
		input[i] = line;
		i++;
	}
	input[i] = line;
	input[++i] = NULL;
	look_for_double_uppercase(input, 0, 0, world);
	close(fd);
	return (input);
}

static void	free_input(char **input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	while (input[i])
		ft_free(input[i++]);
	ft_free(input);
}

static int	parse_line(t_world *world, char *line)
{
	if (line[0] == 'A')
		return (parse_ambient_light(world, line));
	if (line[0] == 'C')
		return (parse_camera(world, line));
	if (line[0] == 'L')
		return (parse_light(world, line));
	if (!ft_strncmp(line, "sp", 2))
		return (parse_sphere(world, line));
	if (!ft_strncmp(line, "pl", 2))
		return (parse_plane(world, line));
	if (!ft_strncmp(line, "cy", 2))
		return (parse_cylinder(world, line));
	return (0);
}

int	parse_input(char *file_name, t_world *world)
{
	char	**input;
	char	*cleaned;
	int		i;

	i = 0;
	world->all_sorted = ft_calloc(sizeof(double *), 100);
	if (!world->all_sorted)
		return (1);
	input = process_file(file_name, world);
	if (!input)
		return (1);
	while (input[i])
	{
		cleaned = clean_input_line(input[i]);
		if ((parse_line(world, cleaned)))
			return (1);
		i++;
	}
	return (free_input(input), 0);
}
