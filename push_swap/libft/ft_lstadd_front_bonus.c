/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:31:38 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/18 19:31:38 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*store;

	store = lst[0];
	lst[0] = new;
	new->next = store;
}

// t_list *ft_lstnew(void *content)
// {
// 	t_list *next_node;
// 	next_node = (t_list *)malloc(sizeof(t_list));
// 	next_node -> content = content;
// 	next_node -> next = 0;
// 	return (next_node);
// int main(void)
// {
// 	char *a;
// 	char *b;
// 	b = "blabla";
// 	a = "letter";
// 	t_list *head = ft_lstnew(b);
// 	t_list *head2 = ft_lstnew(a);
// 	ft_lstadd_front(&head,head2);
// 	t_list *current = head;
//     printf("Liste: ");
//     // Durchlaufe jeden Knoten und drucke den Inhalt
//     while (current != NULL) {
//         printf("%s ", current->content); // 
//         current = current->next;
//     }
//     printf("\n");
// }