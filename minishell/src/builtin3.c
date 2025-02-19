/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 17:53:10 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_env(t_mini *mini)
{
	int	i;

	i = -1;
	if (ft_strncmp(mini->arguments[1], "echo", 5) == 0)
	{
		echo(mini, 1);
		return ;
	}
	if (ft_strncmp(mini->arguments[1], "pwd", 4) == 0)
	{
		show_path(mini);
		return ;
	}
	while (mini->envp[++ i] != 0)
		printf("%s\n", mini->envp[i]);
	mini->exitstatus = 0;
}

void	echo_print(char *string, t_mini *mini)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (string[i] != 0)
	{
		if (string[i] == '$')
		{
			if (string[i + 1] == '?')
			{
				printf("%d ", mini->exitstatus);
				i += 2;
				continue ;
			}
			j = search_var(mini, &string[i + 1]);
			if (j == 0)
				return ;
			printf("%s", mini->variables[j - 1].value);
			i += ft_strlen(mini->variables[j - 1].name);
		}
		else
			printf("%c", string[i]);
		i ++;
	}
}

void	echo(t_mini *mini, int i)
{
	int	j;

	j = 0;
	if (ft_strncmp(mini->arguments[1], "-n", 3) == 0)
		j = 1;
	while (mini->arguments[++ i + j] != 0)
	{
		echo_print(mini->arguments[i + j], mini);
		printf(" ");
	}
	if (ft_strncmp(mini->arguments[1], "-n", 3) != 0)
		printf("\n");
	mini->exitstatus = 0;
}
