/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:48:55 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/12 22:15:40 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(char const *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str != 0)
// 	{
// 		i ++;
// 		str ++;
// 	}
// 	return (i);
// }

char	*ft_strchr(char const *s, int c)
{
	char	*ptr;

	c = c % 256;
	ptr = (char *)s;
	while (*ptr != 0)
	{
		if (*ptr == c)
			return (ptr);
		ptr ++;
	}
	if (c == 0)
		return ((char *) ptr);
	return (NULL);
}

// int main(void)
// {
// 	char *s = "teste";
// 	printf("%s\n", ft_strchr("teste", 357));

// 	printf("%s", strchr("teste", 357));
// }