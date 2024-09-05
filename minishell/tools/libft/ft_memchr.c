/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:09:47 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/13 22:06:39 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int size)
{
	int		i;
	char	*src;
	char	to_find;
	char	*to_find_ptr;

	to_find = (char)c;
	to_find_ptr = &to_find;
	src = (char *)s;
	i = 0;
	if (size == 0)
		return (0);
	while (ft_strncmp(src, to_find_ptr, 1) != 0 && i + 1 < size)
	{
		src ++;
		i ++;
	}
	if (ft_strncmp(src, to_find_ptr, 1) == 0)
		return ((void *)src);
	else
		return (0);
}

// int main(void)
// {
// 	void *s = "2936 b3f6 3a6c f700 28a3 349c c60d 5117";
// 	printf("%s\n", ft_memchr(s, 34, 21));
// 	void *s2 = "Hallo wie geht es dir ";
// 	printf("%s", memchr(s, 34, 21));
// }