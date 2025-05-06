/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_reduction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:48:18 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/17 16:54:35 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*clean_input_line(char *line)
{
	int		i;
	int		j;
	int		res_index;
	char	*result;

	i = 0;
	res_index = 0;
	j = 0;
	result = ft_strdup(line);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			j = 0;
			while (line[i + j] == ' ')
				j++;
			if (i != 0)
				i--;
			i += j;
		}
		result[res_index] = line[i];
		i++;
		res_index++;
	}
	return (result[res_index] = '\0', result);
}
