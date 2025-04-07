/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:03:14 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:41:31 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

double	budget_ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign[1];
	int		i;

	i = 0;
	result = 0;
	fraction = 0;
	sign[0] = 1;
	if (str[i] == '-')
		sign[i++] = -1;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] && str[i] == '.')
	{
		i++;
		while (str[i])
		{
			fraction = fraction * 10 + str[i] - '0';
			i++;
		}
	}
	return ((result + fraction / 10) * sign[0]);
}
