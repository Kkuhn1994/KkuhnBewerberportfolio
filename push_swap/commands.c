/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:42:08 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/10 14:42:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rb(int *stack_b, size_t size_b)
{
	if (size_b >= 2)
		shift_up(stack_b, size_b);
	return (stack_b);
}

void	rr(int **stack_a, int **stack_b, size_t size_a, size_t size_b)
{
	if (size_a > 1)
		stack_a[0] = ra(stack_a[0], size_a);
	if (size_b > 1)
		stack_b[0] = rb(stack_b[0], size_b);
}

int	*rra(int *stack_a, size_t size_a)
{
	if (size_a >= 2)
		shift_down(stack_a, size_a);
	return (stack_a);
}

int	*rrb(int *stack_b, size_t size_b)
{
	if (size_b >= 2)
		shift_down(stack_b, size_b);
	return (stack_b);
}

void	rrr(int **stack_a, int **stack_b, size_t size_a, size_t size_b)
{
	if (size_a > 1)
		stack_a[0] = rra(stack_a[0], size_a);
	if (size_b > 1)
		stack_b[0] = rrb(stack_b[0], size_b);
}
