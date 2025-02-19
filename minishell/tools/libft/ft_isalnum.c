/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:18:18 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/12 22:22:51 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int a)
{
	a = a % 256;
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d",isalnum('a'));
// 	printf("%d",ft_isalnum('a'));
// 	printf("%d",ft_isalnum('G'));
// 	printf("%d",isalnum('G'));

// 	printf("%d",ft_isalnum('k'));
// 	printf("%d",ft_isalnum('='));
// 	printf("%d",ft_isalnum('0'));
// 	printf("%d",ft_isalnum(' '));
// 	return (0);
// }