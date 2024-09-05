/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:42:38 by kkuhn             #+#    #+#             */
/*   Updated: 2024/05/13 22:29:53 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

int		check_smallest(int *array, int size_a);
int		check_array(int *stack_a, size_t size_a);
char	*ft_strjoin2(char *s1, char *s2);
int		**allocate(int **stacks, size_t size_a);

#endif