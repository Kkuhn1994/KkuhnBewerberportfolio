/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:14:55 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 20:24:37 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitcount(int n)
{
	int	number_digits;

	number_digits = 0;
	while (n > 0)
	{
		number_digits ++;
		n = n / 10;
	}
	return (number_digits);
}

static char	*ft_specialcase2(int n, char *number)
{
	int	j;

	number = (char *) malloc (ft_digitcount(n) + 2);
	if (number == 0)
		return (0);
	j = ft_digitcount(n);
	number[ft_digitcount(n) + 1] = 0;
	while (n > 0)
	{
		number[j] = n % 10 + '0';
		j --;
		n = n / 10;
	}
	number[j] = '-';
	return (number);
}

static char	*ft_specialcase(int n, char *number)
{
	if (n == INT_MIN)
	{
		number = (char *) malloc (12 * sizeof(char));
		if (number == 0)
			return (0);
		ft_strlcpy(number, "-2147483648", 12);
		return (number);
	}
	n = -n;
	if (n == 0)
	{
		number = (char *) malloc (2);
		if (number == 0)
			return (0);
		number[0] = '0';
		number[1] = 0;
	}
	else
		return (ft_specialcase2(n, number));
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		j;

	number = 0;
	if (n <= 0)
		return (ft_specialcase(n, number));
	number = (char *) malloc (ft_digitcount(n) + 1);
	if (number == 0)
		return (0);
	j = ft_digitcount(n) - 1;
	number[ft_digitcount(n)] = 0;
	while (n > 0)
	{
		number[j] = n % 10 + '0';
		j --;
		n = n / 10;
	}
	return (number);
}

// int main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	return 0;
// }