#include "minishell.h"

void	ls(t_mini *mini)
{
	char	*path;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		path = find_path(mini->envp, mini->arguments[0]);
		execve(path, mini->arguments, mini->envp);
	}
	waitpid(pid, NULL, 0);
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
		{
			free(string);
			return ;
		}
		else
			realloc_smaller_2d(mini, string);
		free(string);
	}
}

void	redirect(char *cmd, int fdout, t_mini *mini)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if(pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		if (fdout == 1)
			dup2(pipefd[1], STDOUT_FILENO);
		else
			dup2(fdout, STDOUT_FILENO);
		close(pipefd[1]);
		// if (fdin == STDIN_FILENO)
		// 	exit(1);
		// else
		exec(cmd, mini);
	}
}
