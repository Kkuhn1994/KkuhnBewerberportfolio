/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:19 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/12 22:18:37 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*endofstring;

	c = c % 256;
	i = ft_strlen(s);
	endofstring = s + i;
	while (i >= 0)
	{
		if (*endofstring == c)
			return (endofstring);
		endofstring --;
		i --;
	}
	return (0);
}

// int main(void)
// {
// 	char *s = "Hallo wie geht es dir ";
// 	printf("%p\n", ft_strrchr("teste", 'e'));

// 	char *s2 = "Hallo wie geht es dir ";
// 	printf("%p", strrchr("teste", 'e'));
// }