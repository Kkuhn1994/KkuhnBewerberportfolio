/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:55:00 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/08 15:21:29 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h> 

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

// int main(void){
// 	ft_putnbr_fd(2147483647, 4);
// 	return 0;
// }