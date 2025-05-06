/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:03:14 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/18 19:36:11 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static double	parse_integer_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_fraction_part(char *str, int *i)
{
	double	fraction;
	int		frac_digits;

	fraction = 0.0;
	frac_digits = 0;
	while (ft_isdigit(str[*i]))
	{
		fraction = fraction * 10 + (str[*i] - '0');
		frac_digits++;
		(*i)++;
	}
	while (frac_digits-- > 0)
		fraction /= 10.0;
	return (fraction);
}

double	budget_ft_atof(char *str)
{
	int		i;
	int		sign;
	double	integer_part;
	double	fraction_part;

	i = 0;
	fraction_part = 0.0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		(i)++;
	}
	integer_part = parse_integer_part(str, &i);
	if (str[i] == '.')
	{
		i++;
		fraction_part = parse_fraction_part(str, &i);
	}
	return ((integer_part + fraction_part) * sign);
}
