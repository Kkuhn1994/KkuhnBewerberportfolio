/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:38:01 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/15 21:18:35 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(int **stack_b, int b_rotates, size_t size_b)
{
	while (b_rotates > 0)
	{
		stack_b[0] = rb(stack_b[0], size_b);
		b_rotates --;
	}
}

int	rotate_a(int **st_a, int *b_0, int *smallandbig, size_t size)
{
	if (*b_0 > smallandbig[1] || *b_0 < smallandbig[0])
	{
		while (st_a[0][0] != smallandbig[0])
		{
			st_a[0] = ra(st_a[0], size);
			smallandbig[2]++;
		}
		if (*b_0 > smallandbig[1])
			smallandbig[1] = *b_0;
		else
			smallandbig[0] = *b_0;
	}
	else
	{
		while (smallandbig[2] < (int)size)
		{
			if (*b_0 < st_a[0][0] && *b_0 > st_a[0][size - 1])
				break ;
			st_a[0] = ra(st_a[0], size);
			smallandbig[2]++;
		}
	}
	return (smallandbig[2]);
}

int	reverse_rotate(int *stack_a, int *big_small, int stack_b, int size_a)
{
	int	iterations;

	iterations = 0;
	if (big_small == NULL)
	{
		while (iterations < size_a - 1)
		{
			if (stack_a[iterations] > stack_b && stack_b > stack_a[size_a - 1])
				break ;
			iterations ++;
		}
	}
	else
	{
		while (stack_a[iterations] != *big_small)
			iterations ++;
		*big_small = stack_b;
	}
	if (iterations <= size_a / 2)
		return (iterations);
	else
		return (size_a - iterations);
}

int	rotate(int **stack_a, int **stack_b, size_t **size, int rotate_a)
{
	size_t	rotations_b;
	size_t	rotate_a_store;

	rotations_b = 0;
	rotate_a_store = rotate_a;
	while (rotate_a > 0)
	{
		stack_a[0] = ra(stack_a[0], size[0][0]);
		rotate_a --;
	}
	while (rotations_b < size[0][1])
	{
		if (stack_a[0][0] > stack_b[0][0])
			break ;
		stack_b[0] = rb(stack_b[0], size[0][1]);
		rotations_b ++;
	}
	return ((int)rotations_b);
}
