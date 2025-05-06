/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:18:26 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 12:37:18 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*alloc_transfer(void *ptr, int new_size, t_list *current, t_list *prev)
{
	void	*new_ptr;
	int		old_size;

	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	old_size = sizeof(current->content);
	if (old_size < new_size)
		old_size = new_size;
	ft_memcpy(new_ptr, ptr, current->size - 1);
	prev->next = current->next;
	free(current->content);
	free(current);
	return (new_ptr);
}

void	*rt_realloc(void *ptr, int new_size)
{
	t_list	*lst;
	t_list	*prev;
	t_list	*current;

	lst = get_adress_of_list();
	prev = lst;
	current = lst->next;
	if (!ptr)
		return (ft_malloc(new_size));
	if (new_size == 0)
		return (NULL);
	while (current)
	{
		if (current->content == ptr)
			return (alloc_transfer(ptr, new_size, current, prev));
		prev = current;
		current = current->next;
	}
	return (NULL);
}
