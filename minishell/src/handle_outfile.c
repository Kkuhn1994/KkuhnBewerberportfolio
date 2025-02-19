/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:53 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 17:53:54 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	output_stuff(t_mini *mini, int i)
{
	int	fdout;

	fdout = 1;
	if (ft_strncmp(mini->arguments[i + 1 + mini->store], ">", 2) == 0)
	{
		fdout = openfile(mini->arguments[i + 2 + mini->store], 1, 0);
		mini->store2 = 2;
		return (fdout);
	}
	else if (ft_strncmp(mini->arguments[i + 1 + mini->store], ">>", 3) == 0)
	{
		fdout = openfile(mini->arguments[i + 2 + mini->store], 1, 1);
		mini->store2 = 2;
		return (fdout);
	}
	return (1);
}
