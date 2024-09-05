/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:52:47 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/15 22:32:59 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include "libft/libft.h"

int	*reverse_push(int *st_a, int *st_b, size_t size_a, size_t size_b)
{
	int		small_big[2];
	int		rotate[2];
	int		*array;
	int		*array2;
	size_t	i;

	i = 0;
	array2 = malloc (4 * sizeof(int));
	small_big[0] = st_a[check_smallest(st_a, size_a)];
	small_big[1] = st_a[check_biggest(st_a, size_a)];
	array = malloc (size_b * sizeof(int));
	while (i < size_b)
	{
		if (st_b[0] < small_big[0])
			rotate[0] = reverse_rotate(st_a, &small_big[0], st_b[i], size_a);
		else if (st_b[0] > small_big[1])
			rotate[0] = reverse_rotate(st_a, &small_big[1], st_b[i], size_a);
		else
			rotate[0] = reverse_rotate(st_a, NULL, st_b[i], size_a);
		rotate[1] = i;
		array[i] = array2[calculate_best(rotate, size_a, size_b, &array2)];
		i ++;
	}
	free(array2);
	return (array);
}

void	ft_push_b_to_a(int **st_a, int **st_b, size_t *size_a, size_t *size_b)
{
	int	*nr_commands;
	int	rotates[2];
	int	*small_big;

	small_big = malloc (3 * sizeof(int));
	small_big[0] = st_a[0][0];
	small_big[1] = st_a[0][*size_a - 1];
	while (*size_b > 0)
	{
		small_big[2] = 0;
		if (st_b[0][0] < st_b[0][1] && st_a[0][0] > st_a[0][1])
		{
			st_b[0] = sb(st_b[0], *size_b);
			ft_putstr_fd("sb\n", 1);
		}
		nr_commands = reverse_push(st_a[0], st_b[0], *size_a, *size_b);
		rotates[1] = check_smallest(nr_commands, *size_b);
		rotate_b(st_b, rotates[1], *size_b);
		rotates[0] = rotate_a(st_a, st_b[0], small_big, *size_a);
		command_print(rotates[0], rotates[1], size_a, size_b);
		pa(st_a, st_b, size_a, size_b);
		ft_putstr_fd("pa\n", 1);
		free(nr_commands);
	}
	free(small_big);
}

void	ft_push_a_to_b(int **stack_a, int **stack_b, size_t **size, int i)
{
	int	middle_value;
	int	rot_a;
	int	rot_b;

	rot_b = 0;
	rot_a = 0;
	middle_value = check_middle(stack_a[0], size[0][0]);
	while (size[0][0] > 3)
	{
		if (stack_a[0][0] > middle_value && i > 0)
		{
			stack_a[0] = ra(stack_a[0], size[0][0]);
			rot_a++;
		}
		else
		{
			rot_b = rotate(stack_a, stack_b, size, 0);
			command_print(rot_a, rot_b, &size[0][0], &size[0][1]);
			pb(stack_a, stack_b, &size[0][0], &size[0][1]);
			ft_putstr_fd("pb\n", 1);
			rot_b = 0;
			rot_a = 0;
		}
		i --;
	}
}

void	ft_solve(int *stack_a, int *stack_b, size_t *size_a)
{
	size_t	**size;

	size = malloc (sizeof (size_t *));
	size[0] = malloc (2 * sizeof (size_t));
	size[0][0] = *size_a;
	size[0][1] = 0;
	ft_push_a_to_b(&stack_a, &stack_b, size, *size_a);
	middle(&stack_a, size[0][0]);
	ft_push_b_to_a(&stack_a, &stack_b, &size[0][0], &size[0][1]);
	rotate_to_right_position(&stack_a, size[0][0]);
	free(size[0]);
	free(size);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	size_t	number_counta;

	if (errorhandling(argc, argv) == 0)
		return (0);
	else
		number_counta = errorhandling(argc, argv);
	stack_a = malloc (number_counta * sizeof(int));
	stack_b = malloc (number_counta * sizeof(int));
	if (stack_a == 0 || stack_b == 0)
		return (0);
	stack_a = fill_stack_a(argv, stack_a, argc, 1);
	if (stack_a != 0)
	{
		if (check_array(stack_a, number_counta) != 0)
			ft_solve(stack_a, stack_b, &number_counta);
	}
	free(stack_a);
	free(stack_b);
}
