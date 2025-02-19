/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:01:08 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:06:08 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// char	ft_toupper2(unsigned int i,char c)
// {
// 	if(c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return c;
// }
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*copy_s;

	copy_s = (char *) malloc (ft_strlen(s) + 1);
	if (copy_s == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		copy_s[i] = f(i, s[i]);
		i ++;
	}
	copy_s[i] = 0;
	return (copy_s);
}

// int main(void)
// {
// 	char *string = "awcgc133";

// 	char *result = ft_strmapi(string, &ft_toupper2);
// 	printf("%s\n", string);
// 	printf("%s", result);
// 	return 0;
// }
