/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:53:06 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 17:34:48 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap(int *number_array, size_t size)
{
	int	temp;

	if (size < 1)
		return (0);
	temp = number_array[0];
	number_array[0] = number_array[1];
	number_array[1] = temp;
	return (number_array);
}

void	push(int **stack_a, int **stack_b, size_t *size_of_a, size_t *size_of_b)
{
	int	temp;
	int	temp2;
	int	i;

	i = 0;
	if (size_of_a == 0)
		return ;
	temp = stack_a[0][0];
	while (i + 1 < (int)size_of_a[0])
	{
		stack_a[0][i] = stack_a[0][i + 1];
		i ++;
	}
	*size_of_a -= 1;
	i = 0;
	*size_of_b += 1;
	while (i < (int)size_of_b[0])
	{
		temp2 = stack_b[0][i];
		stack_b[0][i] = temp;
		temp = temp2;
		i ++;
	}
}

int	*shift_down(int *stack, size_t size)
{
	int	temp;

	if (stack == 0)
		return (0);
	temp = stack[size - 1];
	while (size - 1 > 0)
	{
		stack[size - 1] = stack[size - 2];
		size --;
	}
	stack[0] = temp;
	return (stack);
}

int	*shift_up(int *stack, size_t size)
{
	int		temp;
	size_t	i;

	i = 0;
	if (stack == 0)
		return (0);
	temp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i ++;
	}
	stack[i] = temp;
	return (stack);
}

int	*sa(int *stack_a, size_t size_a)
{
	stack_a = swap(stack_a, size_a);
	return (stack_a);
}
