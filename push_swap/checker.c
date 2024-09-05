/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:12:43 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/15 21:56:00 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swaps_and_push(int **stacks, size_t *size_a, size_t *size_b, char *input)
{
	if (ft_memcmp(input, "sa\n", 3) == 0)
		stacks[0] = sa(stacks[0], *size_a);
	else if (ft_memcmp(input, "sb\n", 3) == 0)
		stacks[1] = sa(stacks[1], *size_b);
	else if (ft_memcmp(input, "ss\n", 3) == 0)
		ss(&stacks[0], &stacks[1], *size_a, *size_b);
	else if (ft_memcmp(input, "pa\n", 3) == 0)
		pa(&stacks[0], &stacks[1], size_a, size_b);
	else if (ft_memcmp(input, "pb\n", 3) == 0)
		pb(&stacks[0], &stacks[1], size_a, size_b);
	else if (ft_memcmp(input, "ra\n", 3) == 0)
		stacks[0] = ra(stacks[0], *size_a);
	else if (ft_memcmp(input, "rb\n", 3) == 0)
		stacks[1] = rb(stacks[1], *size_b);
	else if (ft_memcmp(input, "rr\n", 3) == 0)
		rr(&stacks[0], &stacks[1],*size_a, *size_b);
	else
		return (-1);
	return (0);
}

int	commands(int **stacks, size_t *size_a, size_t *size_b, char *input)
{
	if (swaps_and_push(stacks, size_a, size_b, input) == 0)
		return (3);
	else if (ft_memcmp(input, "rra\n", 4) == 0)
		stacks[0] = rra(stacks[0], *size_a);
	else if (ft_memcmp(input, "rrb\n", 4) == 0)
		stacks[1] = rrb(stacks[1], *size_b);
	else if (ft_memcmp(input, "rrr\n", 4) == 0)
		rrr(&stacks[0], &stacks[1],*size_a, *size_b);
	else
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (4);
}

void	solve(int **stacks, size_t *size_a, size_t *size_b, int i)
{
	char	*input;
	char	*buffer;
	int		j;

	buffer = ft_calloc (2, 1);
	input = ft_strdup("");
	if (buffer == 0 || input == 0)
		return ;
	while (read(0, buffer, 1) != 0)
		input = ft_strjoin2(input, buffer);
	while (input[i] != 0)
	{
		j = commands(stacks, size_a, size_b, &input[i]);
		if (j == 0)
			break ;
		i = i + j;
	}
	if (check_array(stacks[0], *size_a) == 0 && *size_b == 0)
		write(1, "OK\n", 3);
	else if (j != 0)
		write(1, "KO\n", 3);
	free(input);
	free(buffer);
}

size_t	errorhandling(int argc, char *argv[])
{
	int	number_count2;
	int	number_counta;
	int	i;

	number_counta = 0;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		number_count2 = count_numbers(argv[i]);
		if (number_count2 == -1)
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
		number_counta += number_count2;
		i ++;
	}
	return (number_counta);
}

int	main(int argc, char *argv[])
{
	int		**stacks;
	size_t	size_a;
	size_t	size_b;

	stacks = 0;
	size_b = 0;
	size_a = errorhandling(argc, argv);
	if (size_a == 0)
		return (0);
	stacks = allocate(stacks, size_a);
	if (stacks == 0)
		return (0);
	stacks[0] = fill_stack_a(argv, stacks[0], argc, 1);
	if (stacks[0] != 0)
		solve(stacks, &size_a, &size_b, 0);
	free(stacks[0]);
	free(stacks[1]);
	free(stacks);
	return (0);
}
