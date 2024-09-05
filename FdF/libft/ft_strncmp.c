/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:57:37 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/13 13:59:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i ++;
	}
	return (0);
}

// int main(void)
// {
// 	char *s1 = "Hallo , wie geht es dir";
// 	char *s2 = "Hallo , wie geht es dir2323";
// 	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
// 	printf("%d\n", strncmp("abcdef", "abc\375xx", 5));
// 	// printf("%d\n", ft_strncmp("abc", "abc", 7));
// 	// printf("%d\n", strncmp("abc", "abc", 7));
// }