/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budget_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:10:22 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:59:02 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	budget_get_next_line(int fd, char **line)
{
	char	buffer[2];
	int		ret;
	char	*temp;

	*line = ft_malloc(5);
	if (!*line)
		return (-1);
	(*line)[0] = '\0';
	ret = read(fd, buffer, 1);
	while (ret > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
			return (1);
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		ft_free(temp);
		ret = read(fd, buffer, 1);
		if (ret < 0 || !*line)
			return (ft_free(*line), -1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}
