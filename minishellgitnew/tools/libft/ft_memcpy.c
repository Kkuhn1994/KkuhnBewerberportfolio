/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:07:39 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 20:54:12 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*srcptr;

	i = 0;
	ptr = dst;
	srcptr = (char *)src;
	if (!src && !dst && n > 0)
		return (0);
	while (i < n)
	{
		ptr[i] = srcptr[i];
		i ++;
	}
	return (dst);
}

// int main(void)
// {
//     char dst[0];
//     char src[0]= "";
//     char dst2[0];
//     char src2[0]= "";

//      ft_memcpy(dst,src,10);
//     printf("%s\n", dst);

//     memcpy(dst2,src2,10);
//     printf("%s\n", dst2);

//     return 0;
// }