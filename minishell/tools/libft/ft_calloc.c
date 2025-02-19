/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:20:12 by kkuhn             #+#    #+#             */
/*   Updated: 2024/11/03 20:13:15 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	char	*allocated_memory;

	allocated_memory = (void *) ft_gc_malloc (count * size);
	if (allocated_memory == 0)
		return (NULL);
	ft_memset(allocated_memory, 0, count * size);
	return (allocated_memory);
}
