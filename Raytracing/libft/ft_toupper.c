/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:00:45 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/07 15:04:38 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
// int main(void)
// {
// 	char c = 'c';
// 	char v = 'C';	
// 	write (1, ft_toupper(c), 1);
// 	;
// 	write (1, ft_toupper(v), 1);

// 	char c2 = 'c';
// 	char v2 = 'C';	
// 	toupper(c2);
// 	write (1,&c2, 1);
// 	toupper(v2);
// 	write (1, &v2, 1);
// }