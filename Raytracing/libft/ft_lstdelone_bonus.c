/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:29:46 by kkuhn             #+#    #+#             */
/*   Updated: 2025/04/03 17:01:28 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == 0)
		return ;
	if (lst == 0)
		return ;
	if (lst->content != NULL)
	{
		del(lst->content);
		lst->content = NULL;
	}
	free(lst);
	lst = NULL;
}
