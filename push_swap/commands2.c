/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:41:13 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 18:11:52 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sb(int *stack_b, size_t size_b)
{
	stack_b = swap(stack_b, size_b);
	return (stack_b);
}

void	ss(int **stack_a, int **stack_b, size_t size_a, size_t size_b)
{
	stack_a[0] = sa(stack_a[0], size_a);
	stack_b[0] = sb(stack_b[0], size_b);
}

void	pa(int **stack_a, int **stack_b, size_t *size_a, size_t *size_b)
{
	if (*size_b == 0)
		return ;
	push(stack_b, stack_a, size_b, size_a);
}

void	pb(int **stack_a, int **stack_b, size_t *size_a, size_t *size_b)
{
	if (*size_a == 0)
		return ;
	push(stack_a, stack_b, size_a, size_b);
}

int	*ra(int *stack_a, size_t size_a)
{
	if (size_a >= 2)
		shift_up(stack_a, size_a);
	return (stack_a);
}
