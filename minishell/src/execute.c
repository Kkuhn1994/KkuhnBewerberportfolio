#include "minishell.h"

void	exit_programm(t_mini *mini)
{
	free_stuff(mini);
	free_function(mini);
	exit(0);
}

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

void	exec(char *cmd, t_mini *mini)
{
	char	**args;
	char	*path;

	args = allocate_command(cmd, mini, 0);
	path = find_path(mini->envp, args[0]);
	if (path == 0)
	{
		free_2dchar(args);
		exit(127);
	}
	execve(path, args, mini->envp);
	exit(127);
}

int	ft_search_out(char **args, int i)
{
	int	j;

	j = i;
	while (args[j] != 0 && j < i + 2)
		j ++;
	if (ft_strncmp(args[j], ">", 2) == 0)
		return (0);
	return (1);
}

void	input_stuff(t_mini *mini, int *i)
{
	int		fdin;

	if (ft_strncmp(mini->arguments[*i], "<", 2) == 0)
	{
		fdin = openfile(mini->arguments[*i + 1], 0, 0);
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		*i += 2;
	}
	if (fdin == -1)
	{
		printf("file not available");
		exit(0);
	}
}

void	execute_pipes(t_mini *mini, int i)
{

	int fdout;
	pid_t	pid;

	pid = fork();
	
	if (pid == 0)
	{
		while (mini->arguments[i] != 0)
		{
			fdout = 1;
			input_stuff(mini, &i);

			if (ft_strncmp(mini->arguments[i + 2], ">", 2) == 0)
			{

				fdout = openfile(mini->arguments[i + 3], 1, 0);
				dup2(fdout, STDOUT_FILENO);
			}
			if (ft_strncmp(mini->arguments[i], "|", 1) == 0 && i < mini->argc - 2)
			{
				redirect(mini->arguments[i + 1], fdout, mini);
				i += 2;
			}
			else
			{
				exec(mini->arguments[i + 1], mini);
				i += 2;
			}
			if (fdout != 1)
				i += 2;
		}
	}
	waitpid(pid, NULL, 0);
}

void	execute(t_mini *mini)
{
	int	i;

	i = 0;
	if (check_for_pipes(mini->arguments) == 0)
		execute_pipes(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "env", 4) == 0)
		show_env(mini);
	else if (ft_strchr(mini->arguments[0], '=') != 0)
		save_var(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "cd", 3) == 0)
		change_directory(mini->arguments[1], mini);
	else if (ft_strncmp(mini->arguments[0], "pwd", 4) == 0)
		show_path();
	else if (ft_strncmp(mini->arguments[0], "echo", 5) == 0)
		echo(mini, 0);
	else if (ft_strncmp(mini->arguments[0], "exit", 5) == 0)
		exit_programm(mini);
	else if (ft_strncmp(mini->arguments[0], "export", 7) == 0)
		ft_export(mini);
	else if (ft_strncmp(mini->arguments[0], "unset", 6) == 0)
		unset(mini);
	else if (ft_strncmp(mini->arguments[0], "ls", 3) == 0)
		ls(mini);
	else if (ft_strncmp(mini->arguments[0], "clear", 6) == 0)
		printf("\e[1;1H\e[2J");
}
