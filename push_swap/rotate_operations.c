/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:39:12 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 19:20:25 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(int rot_a, int rot_b, size_t size_a, size_t size_b)
{
	rot_a = size_a - rot_a;
	rot_b = size_b - rot_b;
	while (rot_a > 0 && rot_b > 0)
	{
		ft_putstr_fd("rrr\n", 1);
		rot_a --;
		rot_b --;
	}
	while (rot_a > 0)
	{
		ft_putstr_fd("rra\n", 1);
		rot_a --;
	}
	while (rot_b > 0)
	{
		ft_putstr_fd("rrb\n", 1);
		rot_b --;
	}
}

void	rotate_both(int rotate_a, int rotate_b)
{
	while (rotate_a > 0 && rotate_b > 0)
	{
		ft_putstr_fd("rr\n", 1);
		rotate_a --;
		rotate_b --;
	}
	while (rotate_a > 0)
	{
		ft_putstr_fd("ra\n", 1);
		rotate_a --;
	}
	while (rotate_b > 0)
	{
		ft_putstr_fd("rb\n", 1);
		rotate_b --;
	}
}

void	print_b_rotate(int rotate_b, size_t size_b)
{
	int	reverse;

	reverse = 0;
	if (rotate_b > (int)size_b / 2)
	{
		rotate_b = size_b - rotate_b;
		reverse = 1;
	}
	while (rotate_b > 0)
	{
		if (reverse == 1)
			ft_putstr_fd("rrb\n", 1);
		else
			ft_putstr_fd("rb\n", 1);
		rotate_b --;
	}
}

void	rotate_different(int rot_a, int rot_b, size_t size_a, size_t size_b)
{
	int	reverse;

	reverse = 0;
	if (rot_a > (int)size_a / 2)
	{
		rot_a = size_a - rot_a;
		reverse = 1;
	}
	while (rot_a > 0)
	{
		if (reverse == 1)
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("ra\n", 1);
		rot_a --;
	}
	print_b_rotate(rot_b, size_b);
}
