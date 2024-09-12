/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:48:08 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:05:48 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	if (!s1)
		return (0);
	while (start < (int)ft_strlen((char *)s1))
	{
		if (!ft_strchr(set, s1[start]))
			return (start);
		start++;
	}
	return (start);
}

static int	ft_calc_end(char const *s1, char const *set)
{
	int	end;

	if (!s1)
		return (0);
	end = ft_strlen((char *)s1) - 1;
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end]))
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!set)
		return (NULL);
	end = ft_calc_end(s1, set);
	start = ft_calc_start(s1, set);
	if (start > end || !s1)
	{
		result = malloc(1 * sizeof(char));
		if (result == 0)
			return (0);
		result[0] = '\0';
		return (result);
	}
	result = malloc((end - start + 1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)&s1[start], end - start + 1 + 1);
	return (result);
}
