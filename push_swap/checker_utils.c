/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:48 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 22:29:32 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_array(int *stack_a, size_t size_a)
{
	int	i;

	i = 0;
	while (i < (int)size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
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
	free(s1);
	return (joined_str);
}

int	**allocate(int **stacks, size_t size_a)
{
	stacks = malloc (2 * sizeof (int *));
	if (stacks == 0)
		return (0);
	stacks[0] = malloc (size_a * sizeof(int));
	stacks[1] = malloc (size_a * sizeof(int));
	if (stacks[0] == 0 || stacks[1] == 0)
	{
		if (stacks[0] != NULL)
			free(stacks[0]);
		if (stacks[1] != NULL)
			free(stacks[1]);
		free(stacks);
		return (0);
	}
	return (stacks);
}
