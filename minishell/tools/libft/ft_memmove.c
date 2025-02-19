/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:05:32 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:20:55 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr;
	char	*srcptr;

	i = 0;
	ptr = dst;
	srcptr = (char *)src;
	if (!dst && !src && len > 0)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			ptr[i] = srcptr[i];
			i ++;
		}
		return (dst);
	}
	while (len > 0)
	{
		ptr[len - 1] = srcptr[len - 1];
		len --;
	}
	return (dst);
}

// int main(void)
// {
//     char src[] = "123456";
//     char dst1[10];
//     char dst2[10];
//     // Mit ft_memmove kopieren
//     ft_memmove(dst1, src, 4);
//     printf(": %s\n",ft_memmove(dst1, "con\00te\0tur", 10));
//     // Mit memmove kopieren
//     memmove(dst2, src, 4);
//     printf("t: %s\n", memmove(dst2, "conte\0tur", 10));
//     return 0;
// }
