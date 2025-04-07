/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:02:15 by kkuhn             #+#    #+#             */
/*   Updated: 2025/04/03 21:14:21 by qhahn            ###   ########.fr       */
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

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || (start == 0 && len == 0))
		return (ft_strdup(""));
	if (start == 0 && len >= ft_strlen(s))
		return (ft_strdup((char *)s));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substring = (char *)MALLOC(len + 1);
	if (substring == 0)
		return (0);
	while (i < len && s[i + start] != 0)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = 0;
	return (substring);
}

// int main()
// {
//    char	str[] = "tripouille";
// 	char * s = strdup("4");
// 	printf("%s",ft_substr(str, 0, 10));
//     return (0);
// }