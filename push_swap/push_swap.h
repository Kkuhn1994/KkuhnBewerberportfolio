/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:08:47 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/15 21:03:02 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

void	middle(int **stack_a, size_t size_a);
int		*fill_stack_a(char *argv[], int *a, int argc, int i);
int		doublecheck(int *number, int a, int j);
int		ft_atoi2(char *string, int *is_error);
int		count_numbers(char *string);
int		*swap(int *number_array, size_t size);
void	push(int **st_a, int **st_b, size_t *size_of_a, size_t *size_of_b);
int		*shift_down(int *stack, size_t size);
int		*shift_up(int *stack, size_t size);
void	rrr(int **stack_a, int **stack_b, size_t size_a, size_t size_b);
int		*rrb(int *stack_b, size_t size_b);
int		*rra(int *stack_a, size_t size_a);
void	rr(int **stack_a, int **stack_b, size_t size_a, size_t size_b);
int		*rb(int *stack_b, size_t size_b);
int		*ra(int *stack_a, size_t size_a);
void	pb(int **stack_a, int **stack_b, size_t *size_a, size_t *size_b);
void	pa(int **stack_a, int **stack_b, size_t *size_a, size_t *size_b);
void	ss(int **stack_a, int **stack_b, size_t size_a, size_t size_b);
int		*sb(int *stack_b, size_t size_b);
int		*sa(int *stack_a, size_t size_a);
int		check_smallest(int *array, int size_a);
int		check_biggest(int *array, int size_a);
int		check_array(int *stack_a, size_t size_a);
int		*reverse_push(int *st_a, int *st_b, size_t size_a, size_t size_b);
void	ft_push_b_to_a(int **st_a, int **st_b, size_t *size_a, size_t *size_b);
void	ft_push_a_to_b(int **stack_a, int **stack_b, size_t **size, int i);
void	ft_solve(int *stack_a, int *stack_b, size_t *size);
void	rotate_b(int **stack_b, int b_rotates, size_t size_b);
int		rotate_a(int **st_a, int *b_0, int *smallandbig, size_t size);
int		reverse_rotate(int *stack_a, int *big_small, int stack_b, int size_a);
void	reverse_rotate_both(int rot_a, int rot_b, size_t size_a, size_t size_b);
void	rotate_both(int rotate_a, int rotate_b);
void	rotate_different(int rot_a, int rot_b, size_t size_a, size_t size_b);
int		rotate(int **stack_a, int **stack_b, size_t **size, int rotate_a);
size_t	errorhandling(int argc, char *argv[]);
void	rotate_to_right_position(int **stack_a, size_t a);
int		check_middle(int *stack_a, size_t size_a);
void	print_b_rotate(int rotate_b, size_t size_b);
void	command_print(int rot_a, int rot_b, size_t *size_a, size_t *size_b);
int		calculate_best(int *rotate, size_t size_a, size_t size_b, int **array);
int		number_array(int number, int *stack_a, int size);

#endif