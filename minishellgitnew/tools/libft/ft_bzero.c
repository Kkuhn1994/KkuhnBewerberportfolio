/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:23:48 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/07 14:34:08 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i ++;
	}
}

// int main(void)
// {
//     char array[5] = {1, 2, 3, 4, 5};
//     char array2[5] = {1, 2, 3, 4, 5};
//     ft_bzero(array , 3);
//         for (int i = 0; i < 5; ++i) {
//         printf("%d", array[i]);
//     }
//     bzero(array2 , 3);
//         for (int i = 0; i < 5; ++i) {
//         printf("%d", array2[i]);
//     }
// }