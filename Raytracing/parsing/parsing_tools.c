/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:03:18 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/27 20:29:57 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_ratio(char *str, double *ratio)
{
	*ratio = budget_ft_atof(str);
	return (*ratio < 0.0 || *ratio > 1.0);
}

int	parse_rgb(char *str, double rgb[3])
{
	char	**split;
	int		val;
	int		i;

	i = 0;
	split = ft_split(str, ',');
	if (!split || count_split(split) != 3)
	{
		ft_free_split(split);
		return (1);
	}
	while (i < 3)
	{
		val = ft_atoi(split[i]);
		if (val < 0 || val > 255)
		{
			ft_free_split(split);
			return (1);
		}
		rgb[i++] = val / 255.0;
	}
	ft_free_split(split);
	return (0);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		FREE(split[i]);
		i++;
	}
	FREE(split);
}

int	parse_xyz(char **split, double *xyz, int mode)
{
	int		i;
	float	number_to_parse;

	i = 0;
	while (split[i])
	{
		number_to_parse = budget_ft_atof(split[i]);
		if (i >= 3 || mode == 1 && (number_to_parse < -1
				|| number_to_parse > 1))
		{
			write(2, "Error\nWrong Input", ft_strlen("Error\nWrong Input"));
			return (0);
		}
		xyz[i] = number_to_parse;
		i++;
	}
	return (1);
}

int	count_split(char **split_string)
{
	int	i;

	i = 0;
	while (*split_string != 0)
	{
		split_string++;
		i++;
	}
	return (i);
}
