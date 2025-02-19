/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:02:19 by kkuhn             #+#    #+#             */
/*   Updated: 2024/11/03 18:07:15 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H
# include <stdarg.h>
# include <stdlib.h>
# include "../tools/libft/libft.h"

void	*get_adress_of_list(void);
void	*ft_gc_malloc(int size);
void	free_list(void)__attribute__((destructor));

#endif