/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:48:05 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/08 17:49:44 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*stringcopy;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s1) + 1;
	stringcopy = (char *) malloc (size);
	if (stringcopy == 0)
		return (0);
	while (s1[i] != 0)
	{
		stringcopy[i] = s1[i];
		i ++;
	}
	stringcopy[i] = 0;
	return (stringcopy);
}

// int	main(void)
// {
// 	char *string1 = "hallo";

// 	printf("%s\n", ft_strdup(string1));

// 		char *string2 = "hallo";

// 	printf("%s",  strdup(string2));
// }