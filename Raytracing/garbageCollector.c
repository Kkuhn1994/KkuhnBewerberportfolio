/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageCollector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:40:51 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 12:17:42 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbageCollector.h"

void	*get_adress_of_list(void)
{
	static t_list	list = {0};

	return (&list);
}

void	ft_free(void *data)
{
	t_list	*list;
	t_list	*current;
	t_list	*prev;

	list = get_adress_of_list();
	current = (list)->next;
	prev = list;
	while (current)
	{
		if (current->content == data)
		{
			prev->next = current->next;
			free(current->content);
			current->content = NULL;
			free(current);
			current = NULL;
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	*ft_malloc(int size)
{
	t_list	*list;
	void	*content;
	t_list	*new_node;

	content = malloc(size);
	if (!content)
		return (NULL);
	list = get_adress_of_list();
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(content);
		content = NULL;
		return (NULL);
	}
	new_node->content = content;
	new_node->size = size;
	new_node->next = list->next;
	list->next = new_node;
	return (content);
}

void	__attribute__((destructor))	free_list(void)
{
	t_list	*list;
	t_list	*current;
	t_list	*next;

	list = get_adress_of_list();
	current = list->next;
	while (current)
	{
		next = current->next;
		if (current->content)
		{
			free(current->content);
			current->content = NULL;
		}
		free(current);
		current = NULL;
		current = next;
	}
	list->next = NULL;
}
