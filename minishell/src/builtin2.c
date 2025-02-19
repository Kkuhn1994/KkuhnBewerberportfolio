/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:52:57 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 18:08:07 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execvecall_for_everythingelse(t_mini *mini)
{
	char	*path;
	pid_t	pid;	
	char	**args;

	pid = fork();
	if (pid == 0)
	{
		args = allocate_command(mini->line, mini, 0);
		path = find_path(mini->envp, mini->arguments[0]);
		if (path == 0)
		{
			ft_putstr_fd(mini->arguments[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		execve(path, args, mini->envp);
	}
	waitpid(pid, &mini->exitcode, 0);
}

void	unset(t_mini *mini)
{
	int		j;
	char	*string;
	int		i;

	i = 0;
	if (mini->argc < 2)
		return ;
	while (++ i < mini->argc)
	{
		j = check_envp(mini, mini->arguments[i]);
		string = ft_strjoin(mini->arguments[i], "=");
		if (j == 0)
			return ;
		else
			realloc_smaller_2d(mini, string);
	}
}
