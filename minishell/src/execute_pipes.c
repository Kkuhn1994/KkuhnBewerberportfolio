/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:17 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 20:13:40 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *cmd, t_mini *mini)
{
	char	**args;
	char	*path;

	args = allocate_command(cmd, mini, 0);
	path = find_path(mini->envp, args[0]);
	if (path == 0)
	{
		ft_putstr_fd(mini->arguments[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	execve(path, args, mini->envp);
	exit(127);
}

void	exec2(int fdin, int fdout, t_mini *mini, int *i)
{
	if (fdin == -1)
	{
		ft_putstr_fd(mini->arguments[*i + 2], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	exec(mini->arguments[*i], mini);
}

void	execute_command(t_mini *mini, int *i, int fdin, int fdout)
{
	pid_t	pid;

	if (ft_strncmp(mini->arguments[*i + 1 + mini->store + mini->store2], "|", 1)
		== 0 && mini->store2 != 2)
		redirect(mini->arguments[*i], mini);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			exec2(fdin, fdout, mini, i);
		}
	}
	if (fdin != 0)
		close(fdin);
	if (fdout != 1)
		close(fdout);
}

void	execute_pipes(t_mini *mini, int i)
{
	int		fdout;
	int		fdin;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		while (mini->arguments[i] != 0)
		{
			if (ft_strncmp(mini->arguments[i], "|", 2) == 0)
				i++;
			fdin = input_stuff(mini, &i);
			fdout = output_stuff(mini, i);
			execute_command(mini, &i, fdin, fdout);
			i += 1 + mini->store + mini->store2;
			mini->store = 0;
			mini->store2 = 0;
		}
		i = -1;
		while (++ i < 2)
			waitpid(-1, &mini->exitcode, 0);
		exit(0);
	}
	waitpid(-1, &mini->exitcode, 0);
}

void	redirect(char *cmd, t_mini *mini)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exec(cmd, mini);
	}
}
