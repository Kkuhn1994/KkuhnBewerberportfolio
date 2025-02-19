/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:51:18 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 18:43:24 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_space(char *cmd)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (cmd[i + j] != 0)
	{
		if (cmd[i + j] == ' ')
			j ++;
		if (cmd[i + j] == '\"')
			cmd[i] = '\"';
		else
			cmd[i] = cmd[i + j];
		i ++;
	}
	cmd[i + j] = 0;
	return (cmd);
}

char	*increment(char *string)
{
	char	*number;
	char	*returnstring;
	int		nr;

	number = ft_strchr(string, '=') + 1;
	nr = ft_atoi(number) + 1;
	number = ft_itoa(nr);
	returnstring = ft_strjoin("SHLVL=", number);
	return (returnstring);
}

void	init(t_mini *ministruct, char **envp)
{
	int	i;

	i = 0;
	read_perma_history();
	ministruct->nr_var = 0;
	ministruct->argc = 0;
	ministruct->store = 0;
	ministruct->store2 = 0;
	while (envp[i] != 0)
		i ++;
	ministruct->envp = ft_gc_malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "SHLVL", 5) != 0)
			ministruct->envp[i] = ft_strdup(envp[i]);
		else
			ministruct->envp[i] = increment(envp[i]);
		i ++;
	}
	ministruct->envp[i] = 0;
}

void	realloc_smaller_2d(t_mini *mini, char *string)
{
	char	**envp;
	int		i;
	int		j;

	i = 0;
	while (mini->envp[i] != 0)
		i ++;
	envp = malloc((i) * sizeof(char *));
	i = 0;
	j = 0;
	while (mini->envp[j] != 0)
	{
		if (ft_strncmp(mini->envp[j], string, ft_strlen(string)) != 0)
		{
			envp[i] = ft_strdup(mini->envp[j]);
			i ++;
		}
		j ++;
	}
	envp[i] = 0;
	mini->envp = envp;
}
