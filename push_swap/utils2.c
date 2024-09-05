/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:14:17 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 19:22:26 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			write(1, "ERROR", 5);
			return (0);
		}
		number_counta += number_count2;
		i ++;
	}
	return (number_counta);
}

void	rotate_to_right_position(int **stack_a, size_t a)
{
	int		i;
	int		smallest_number;
	size_t	size_b;

	i = 0;
	size_b = 0;
	smallest_number = stack_a[0][check_smallest(stack_a[0], a)];
	while (i < (int)a)
	{
		if (stack_a[0][0] == smallest_number)
			break ;
		stack_a[0] = ra(stack_a[0], a);
		i ++;
	}
	command_print(i, 0, &a, &size_b);
}

int	check_middle(int *stack_a, size_t size_a)
{
	int	*temp;
	int	smallest;
	int	i;
	int	j;
	int	returnvalue;

	i = 0;
	temp = malloc (size_a * sizeof(int));
	while (i < (int)size_a)
	{
		smallest = INT_MAX;
		j = 0;
		while (j < (int)size_a)
		{
			if (number_array(stack_a[j], temp, i) == 0 && stack_a[j] < smallest)
				smallest = stack_a[j];
			j ++;
		}
		temp[i] = smallest;
		i ++;
	}
	returnvalue = temp[size_a / 2];
	free (temp);
	return (returnvalue);
}

void	command_print(int rot_a, int rot_b, size_t *size_a, size_t *size_b)
{
	int	*array;
	int	solution;
	int	*rotates;

	array = malloc (4 * sizeof (int));
	rotates = malloc (2 * sizeof (int *));
	rotates[0] = rot_a;
	rotates[1] = rot_b;
	solution = calculate_best(rotates, *size_a, *size_b, &array);
	if (solution == 0)
		rotate_both(rot_a, rot_b);
	if (solution == 1)
		reverse_rotate_both(rot_a, rot_b, *size_a, *size_b);
	if (solution == 2 || solution == 3)
		rotate_different(rot_a, rot_b, *size_a, *size_b);
	free(array);
	free(rotates);
}

void	middle(int **stack_a, size_t size_a)
{
	if (stack_a[0][0] > stack_a[0][1] && stack_a[0][size_a - 1] > stack_a[0][1])
	{
		stack_a[0] = sa(stack_a[0], size_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack_a[0][0] > stack_a[0][size_a - 1]
		&& stack_a[0][1] > stack_a[0][size_a - 1])
	{
		stack_a[0] = rra(stack_a[0], size_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (stack_a[0][1] > stack_a[0][size_a - 1])
	{
		stack_a[0] = rra(stack_a[0], size_a);
		stack_a[0] = sa(stack_a[0], size_a);
		ft_putstr_fd("rra\n", 1);
		ft_putstr_fd("sa\n", 1);
	}
}
