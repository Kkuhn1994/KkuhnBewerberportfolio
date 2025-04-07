/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:24:09 by kkuhn             #+#    #+#             */
/*   Updated: 2025/03/18 20:06:48 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = (t_list *)malloc(sizeof(t_list));
	if (next_node == 0)
		return (0);
	next_node -> content = content;
	next_node -> next = 0;
	return (next_node);
}

// int main(void)
// {
// 	char *a;
// 	a = "letter";	
// 	t_list *head = ft_lstnew(a);
// 	t_list *current = head;
//     printf("Liste: ");
//     // Durchlaufe jeden Knoten und drucke den Inhalt
//     while (current != NULL) {
//         printf("%s ", current->content); // A
//         current = current->next;
//     }
//     printf("\n");
// }