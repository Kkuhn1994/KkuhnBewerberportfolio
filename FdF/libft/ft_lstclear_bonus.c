/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:30:46 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/20 17:31:51 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*del) == 0)
		return ;
	while ((*lst) != 0)
	{
		next = (*lst)->next;
		ft_lstdelone (*lst, (*del));
		(*lst) = next;
	}
}
