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
	if (access(mini->fdin) != -1)
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

int	create_here_doc(char **arguments, int i, int fdin)
{
	char buffer[2];
	char *command_line;

	command_line = 0;
	buffer[1] = 0;
	while (1)
	{
		read(0, buffer, 1);
		command_line = ft_strjoin2(command_line, buffer);
		if (ft_strncmp(buffer, "\n", 1) == 0)
		{
			if (ft_strncmp(command_line, arguments[i + 1], ft_strlen(command_line) - 1) == 0)
			{
				free(command_line);
				command_line = 0;
				break ;
			}
			else
			{
				write(fdin, command_line, ft_strlen(command_line));
				free(command_line);
				command_line = 0;
			}
		}
	}
	close(fdin);
	fdin = open("here_doc.txt", O_WRONLY, 0644);
	return fdin;
}

int	input_stuff(t_mini *mini, int *i)
{
	int		fdin;

	if (ft_strncmp(mini->arguments[*i], "<<", 3) == 0)
	{
		mini->fdin = open("here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC, 06444);
		mini->fdin = create_here_doc(mini->arguments, *i, fdin);
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		*i += 2;
	}
	else if (ft_strncmp(mini->arguments[*i], "<", 2) == 0)
	{
		fdin = open("here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC, 06444);
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		*i += 2;
	}
	return fdin;
}

int	output_stuff(t_mini *mini, int i)
{
	int	fdout;

	if (ft_strncmp(mini->arguments[i + 1], ">", 2) == 0)
	{
		// printf("test3\n");
		// fflush(stdout);
		fdout = openfile(mini->arguments[i + 2], 1, 0);
		dup2(fdout, STDOUT_FILENO);
		return fdout;
	}
	if (ft_strncmp(mini->arguments[i + 2], ">", 2) == 0)
	{
		fdout = openfile(mini->arguments[i + 3], 1, 0);
		dup2(fdout, STDOUT_FILENO);
		return fdout;
	}
	if (ft_strncmp(mini->arguments[i + 2], ">>", 3) == 0)
	{
		fdout = openfile(mini->arguments[i + 3], 1, 1);
		dup2(fdout, STDOUT_FILENO);
		return fdout;
	}
	return 1;
}

void	execute_pipes(t_mini *mini, int i)
{
	pid_t	pid;
	int fdout;

	pid = fork();
	if (pid == 0)
	{
		while (mini->arguments[i] != 0)
		{
			
			fdout = 1;
			input_stuff(mini, &i);
			fdout = output_stuff(mini, i);
			// printf("%s\n", mini->arguments[i + 1]);
			if (ft_strncmp(mini->arguments[i], "|", 1) == 0 && i < mini->argc - 2)
			{
				// 	printf("test2\n");
				// fflush(stdout);
				redirect(mini->arguments[i + 1], fdout, mini);
				i += 2;
			}
			else if(ft_strncmp(mini->arguments[i], "|", 1) == 0)
			{
				// printf("test3\n");
				// fflush(stdout);
				exec(mini->arguments[i + 1], mini);
				i += 2;
			}		
			else if(ft_strncmp(mini->arguments[i + 1], "|", 1) == 0 && i < mini->argc - 2)
			{
				
				redirect(mini->arguments[i], fdout, mini);
				i +=1;
			}
			else
			{
				// printf("test5\n");
				// fflush(stdout);
				exec(mini->arguments[i], mini);
				i += 1;
				printf("%s\n", mini->arguments[i]);
			}
			if (fdout != 1)
			{
				i += 2;
			}
				
				// 				printf("test1\n");
				// fflush(stdout);
		}
		
		exit(0);
	}
	waitpid(pid, &mini->exitcode, 0);
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
