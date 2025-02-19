/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:07:29 by kkuhn             #+#    #+#             */
/*   Updated: 2024/11/03 20:07:20 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*get_adress_of_list(void)
{
	static t_list	list;

	return (&list);
}

void	*ft_gc_malloc(int size)
{
	t_list	*ptrlist;
	void	*content;
	t_list	*new_node;

	content = malloc(size);
	if (content == 0)
		return (0);
	ptrlist = get_adress_of_list();
	new_node = ft_lstnew(content);
	ft_lstadd_front(&ptrlist, new_node);
	return (content);
}

void __attribute__ ((destructor))	free_list(void)
{
	void	*ptrlist;

	ptrlist = get_adress_of_list();
	ft_lstclear(ptrlist, free);
}
