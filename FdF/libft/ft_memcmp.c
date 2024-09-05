/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:08:39 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:22:06 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t size)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if ((!s1 || !s2) && size > 0)
	{
		*ptr1 = 'a';
		*ptr2 = 'a';
		return (0);
	}
	while (i < size)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i ++;
	}
	return (0);
}

// int main(void)

// {
//         char *s1 = "atoms\0\0\0\0";
//         char *s2 = "atoms\0abc";
// 	char *s3 = "abcdeg";
// 	char *s4 = "abcdee";
// 	printf("%d\n", ft_memcmp(s1,s2,8));
// 	printf("%d\n", memcmp(s1,s2,8));
// 	return 0;
// }