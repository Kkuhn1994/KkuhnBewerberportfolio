/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:55:57 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:05:37 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// char *ft_skip()
char	*ft_specialcases(char *text, char *to_search, int *n)
{
	if (*n < 0)
		*n = ft_strlen(text) - *n;
	if (*to_search == 0)
		return (text);
	return (0);
}

char	*ft_strnstr(char *text, char *to_search, int n)
{
	int		i;
	int		j;
	char	*storeptr;

	i = 0;
	if (ft_specialcases(text, to_search, &n) != 0)
		return (text);
	while (i < n && *text != 0)
	{
		j = 0;
		storeptr = text;
		while (*text == to_search[j] && i + j < n && *text != 0)
		{
			text++;
			j ++;
		}
		text = storeptr;
		if (to_search[j] == 0)
			return (storeptr);
		text ++;
		i ++;
	}
	return (0);
}
// int	main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	printf("%s\n", ft_strnstr("", "teste", 2));
// 	printf("%s\n", strnstr("", "teste", 2));
// 	char *s3 ="aaxx";
// 	char *s4 = "xx";
// 	printf("%s\n", ft_strnstr("", "teste", 2));
// 	printf("%s\n", strnstr("", "teste", 2));
// 	printf("%s\n", ft_strnstr(haystack, "cd", 8));
// 	printf("%s\n", strnstr(haystack, "cd", 8));

// 	return 0;
// }
