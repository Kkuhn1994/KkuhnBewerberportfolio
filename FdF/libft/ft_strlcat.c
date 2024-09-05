/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:15:26 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 19:45:28 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t destsize)
{
	size_t	i;
	int		j;
	size_t	store;

	i = 0;
	j = 0;
	store = ft_strlen(src) + destsize;
	if (destsize > ft_strlen(dst))
		store = ft_strlen(src) + ft_strlen(dst);
	if (ft_strlen(dst) >= destsize)
		return (store);
	while (dst[i] != 0 && i < destsize - 1)
		i ++;
	while (i < destsize - 1 && src[j] != 0)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	if (i != 0)
		dst[i] = 0;
	return (store);
}

// int main(void)
// {
//     char dst[10]= "123";
//     char *src = "3532344";
//     char dst2[10]= "123";
//     char *src2 = "3532344";

//     printf("%li\n",ft_strlcat(dst, src, -1));
//     printf("%s\n",dst);

//     // printf("%li\n",strlcat(dst2, src2, -1));
//     // printf("%s",dst2);

// }