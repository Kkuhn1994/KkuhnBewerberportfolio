/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:15:17 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 19:21:03 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_smallest(int *array, int size_a)
{
	int	i;
	int	smallest_value;
	int	smallest_i;

	i = 0;
	smallest_value = INT_MAX;
	while (i < size_a)
	{
		if (smallest_value == INT_MAX || array[i] < smallest_value)
		{
			smallest_value = array[i];
			smallest_i = i;
		}
		i ++;
	}
	return (smallest_i);
}

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

int	calculate_best(int *rotate, size_t size_a, size_t size_b, int **array)
{
	int	number_a_rotate;
	int	number_b_rotate;

	number_b_rotate = rotate[1];
	number_a_rotate = rotate[0];
	if (number_a_rotate > number_b_rotate)
		array[0][0] = number_a_rotate;
	else
		array[0][0] = number_b_rotate;
	if (size_a - number_a_rotate > size_b - number_b_rotate)
		array[0][1] = size_a - number_a_rotate;
	else
		array[0][1] = size_b - number_b_rotate;
	array[0][2] = number_a_rotate + size_b - number_b_rotate;
	array[0][3] = number_b_rotate + size_a - number_a_rotate;
	return (check_smallest(array[0], 4));
}

int	check_biggest(int *array, int size_a)
{
	int	i;
	int	biggest_value;
	int	biggest_i;

	biggest_value = INT_MIN;
	i = 0;
	while (i < size_a)
	{
		if (biggest_value == INT_MIN || array[i] > biggest_value)
		{
			biggest_value = array[i];
			biggest_i = i;
		}
		i ++;
	}
	return (biggest_i);
}

int	number_array(int number, int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number == stack_a[i])
			return (-1);
		i ++;
	}
	return (0);
}
