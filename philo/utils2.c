/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:51:08 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/15 18:51:14 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	{
		while (*s != 0)
		{
			write(fd, s, 1);
			s ++;
		}
	}
}

static void	print_number(int number, int fd)
{
	char	zahl;

	if (number > 0)
	{
		print_number(number / 10, fd);
		zahl = number % 10 + '0';
		write(fd, &zahl, 1);
	}
}

void	ft_putnbr_fd(int number, int fd)
{
	char	*min_int;
	char	null ;
	char	minus ;

	minus = '-';
	null = '0';
	min_int = "-2147483648";
	if (number == INT_MIN)
	{
		write(fd, min_int, 11);
		return ;
	}
	if (number == 0)
		write(fd, &null, 1);
	if (number < 0)
	{
		write(fd, &minus, 1);
		print_number(-number, fd);
	}
	if (number > 0)
		print_number(number, fd);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*str != 0)
	{
		i ++;
		str ++;
	}
	return (i);
}
