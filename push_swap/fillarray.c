/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillarray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:40:05 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 22:28:00 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *string)
{
	int	count_numbers;

	count_numbers = 0;
	while (*string != 0)
	{
		while (*string == ' ' || *string == '-')
			string ++;
		if (*string >= '0' && *string <= '9')
		{
			count_numbers += 1;
			while (*string >= '0' && *string <= '9')
				string ++;
		}
		else if (*string != 0)
			return (-1);
	}
	return (count_numbers);
}

int	ft_atoi2(char *string, int *is_error)
{
	long	number;
	int		is_negative;

	number = 0;
	is_negative = 1;
	while (*string == ' ')
		string ++;
	while (*string != 0 && *string != ' ')
	{
		if (*string == '-')
			is_negative = -is_negative;
		if (number > INT_MAX || number < INT_MIN)
		{
			*is_error = 1;
			return (0);
		}
		if (*string >= '0' && *string <= '9')
			number = number * 10 + *string - '0';
		string ++;
	}
	return (number * is_negative);
}

int	doublecheck(int *number, int a, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (a == number[i])
			return (-1);
		i ++;
	}
	return (0);
}

int	*fill_stack_a(char *argv[], int *a, int argc, int i)
{
	int		n[2];

	n[0] = 0;
	n[1] = 0;
	while (i < argc)
	{
		while (*argv[i] != 0)
		{
			a[n[0]] = ft_atoi2(argv[i], &n[1]);
			if (n[1] != 0 || doublecheck(a, a[n[0]], n[0]) != 0)
			{
				write(1, "ERROR\n", 6);
				free(a);
				return (0);
			}
			n[0]++;
			while (*argv[i] == ' ' || *argv[i] == '-')
				argv[i]++;
			while (*argv[i] >= '0' && *argv[i] <= '9' && *argv[i] != 0)
				argv[i]++;
		}
		i ++;
	}
	return (a);
}
