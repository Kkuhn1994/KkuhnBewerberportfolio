/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:15:25 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 20:17:28 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d",ft_isprint('a'));
// 	printf("%d",ft_isprint('G'));
// 	printf("%d",ft_isprint('k'));
// 	printf("%d",ft_isprint('='));
// 	printf("%d",ft_isprint('0'));
// 	printf("%d",ft_isprint(' '));
//     printf("%d",isprint('a'));
// 	printf("%d",isprint('G'));
// 	printf("%d",isprint('k'));
// 	printf("%d",isprint('='));
// 	printf("%d",isprint('0'));
// 	printf("%d",isprint(' '));
// 	return (0);
// }