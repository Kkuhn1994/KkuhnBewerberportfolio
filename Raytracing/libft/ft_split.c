/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:35:55 by kkuhn             #+#    #+#             */
/*   Updated: 2025/03/24 17:59:58 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stringcounter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s != 0)
				s++;
		}
		if (*s != 0)
			s++;
	}
	return (i);
}

static size_t	ft_strlen_delimiter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != 0 && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split2(char const *s, char c, int *j, char **strarray)
{
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s != 0)
		{
			strarray[*j] = ft_substr(s, 0, ft_strlen_delimiter(s, c));
			if (strarray[*j] == NULL)
				return (NULL);
			*j = *j + 1;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	strarray[*j] = 0;
	return (strarray);
}

char	**ft_split(char const *s, char c)
{
	char	**strarray;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	if (!*s)
	{
		strarray = MALLOC(1 * sizeof(char *));
		if (!strarray)
			return (NULL);
		strarray[0] = 0;
		return (strarray);
	}
	strarray = (char **)MALLOC((ft_stringcounter(s, c) + 1) * sizeof(char *));
	if (strarray == 0)
		return (0);
	strarray = ft_split2(s, c, &j, strarray);
	if (strarray == 0)
		return (0);
	return (strarray);
}

// int main(void)
// {
// 	char *string = "hello!"  ;
// 	char c =' ';
// 	char **stringarray;
// 	int i = 0;
// 	stringarray = ft_split(string, c);
// 	while (i <= 10)
// 	{
// 		printf("%s\n", stringarray[i]);
// 		i ++;
// 	}
// }
