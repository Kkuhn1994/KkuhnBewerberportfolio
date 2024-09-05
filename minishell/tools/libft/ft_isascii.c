/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:17:05 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 20:15:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d",ft_isascii('a'));
// 	printf("%d",isascii('a'));
// 	printf("%d",ft_isascii('G'));
// 	printf("%d",isascii('G'));
// 	printf("%d",ft_isascii('k'));
// 	printf("%d",isascii('k'));
// 	printf("%d",ft_isascii('='));
// 	printf("%d",isascii('='));
// 	printf("%d",ft_isascii('0'));
// 	printf("%d",isascii('0'));
// 	printf("%d",ft_isascii(' '));
// 	printf("%d",isascii(' '));
// 	return (0);
// }