/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 17:53:27 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	openfile(char *filename, int mode, int is_here_doc)
{
	if (mode == 0)
	{
		if (access(filename, F_OK))
			return (STDIN_FILENO);
		return (open(filename, O_RDONLY));
	}
	else if (is_here_doc == 0)
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666));
	else
		return (open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666));
}

void	execute(t_mini *mini)
{
	int	i;

	i = 0;
	if (check_for_pipes(mini->line) == 0)
		execute_pipes(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "env", 4) == 0)
		show_env(mini);
	else if (ft_strchr(mini->arguments[0], '=') != 0)
		save_var(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "cd", 3) == 0)
		change_directory(mini->arguments[1], mini);
	else if (ft_strncmp(mini->arguments[0], "pwd", 4) == 0)
		show_path(mini);
	else if (ft_strncmp(mini->arguments[0], "echo", 5) == 0)
		echo(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "exit", 5) == 0)
		exit(0);
	else if (ft_strncmp(mini->arguments[0], "export", 7) == 0)
		ft_export(mini);
	else if (ft_strncmp(mini->arguments[0], "unset", 6) == 0)
		unset(mini);
	else
		execvecall_for_everythingelse(mini);
}
