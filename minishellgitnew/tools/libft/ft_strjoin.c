/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:18:48 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/09 15:34:34 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;

	i = 0;
	joined_str = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined_str == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		joined_str[i] = s1[i];
		i ++;
	}
	while (*s2 != 0)
	{
		joined_str[i] = *s2;
		s2 ++;
		i ++;
	}
	joined_str[i] = 0;
	return (joined_str);
}

// int	main(void)
// {
// 	char const *s1 = "Hallo";
// 	char const *s2 = " wie geht es dir";
// 	printf("%s",ft_strjoin(s1,s2));
// 	return 0; 
// }