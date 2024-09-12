/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:17:29 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 20:17:55 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
	// printf("%d",ft_isalpha('a'));
	// printf("%d",ft_isalpha('G'));
	// printf("%d",ft_isalpha('k'));
	// printf("%d",ft_isalpha('='));
	// printf("%d",ft_isalpha('0'));
// 	// printf("%d",ft_isalpha(' '));
// 	    int i;
//         i = -1;
//         while (i < 530)
//         {
//                 if (!!ft_isalpha(i) != !! isalpha(i))
//                         printf("%s", "fail");
//                 i++;
//         }
// 	return (0);
// }