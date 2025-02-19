/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:11:00 by kkuhn             #+#    #+#             */
/*   Updated: 2024/10/20 20:57:59 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// int main(void)
// {
//     char dst[10];
//     char *str = "123456";
//     char dst2[10];
//     char *str2 = "3123456";
// 	memset(dst, 'A', 10);
//     printf("%li\n",ft_strlcpy(dst, "1", 0));
// 	memset(dst2, 'A', 10);
// 	printf("%li\n",strlcpy(dst2, "1", 0));
//     printf("%s\n",dst);
//     printf("%s\n",dst2);
// 	    char dst3[15];
//     char *str3 = "123456";
//     char dst4[4];
//     char *str4 = "3123456";
//     printf("%li\n",ft_strlcpy(dst3, "1", 1));
// 	printf("%li\n",strlcpy(dst4, "1", 1));
//     printf("%s\n",dst3);
//     printf("%s\n",dst4);
// 	    char *str5 = "123456";
//     char dst5[4];
// 	char dst6[4];
//     char *str6 = "3123456";
//     printf("%li\n",ft_strlcpy(dst5, "1", 1));
// 	printf("%li\n",strlcpy(dst6, "1", 1));
//     printf("%s\n",dst5);
//     printf("%s\n",dst6);
// }