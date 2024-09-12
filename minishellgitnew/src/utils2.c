#include "minishell.h"

int check_for_pipes(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '<' || str[i] == '|' || str[i] == '>')
			return 0;
		i ++;
	}
	return 1;
}

char	*find_path(char *envp[], char *cmd)
{
	int		i;
	char	*path;
	char	*part_path;
	char	**paths;

	i = 0;
	if (ft_strnstr(&cmd[0], ".sh", ft_strlen(&cmd[0])) != 0
		|| ft_strnstr(&cmd[0], "/", ft_strlen(&cmd[0])) != 0)
		return (ft_remove_space(&cmd[0]));
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i ++;
	paths = ft_split(&envp[i][5], ':');
	i = -1;
	while (paths[++ i] != 0)
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (free_2dchar(paths), path);
		free(path);
	}
	free_2dchar(paths);
	return (0);
}

void handle_sigquit(int	sig)
{
}

void handle_sigint(int	sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	add_signalhandler(t_mini *mini)
{
	struct sigaction sigint;
	struct sigaction sigquit;
	struct termios	term;

	sigint.sa_handler = handle_sigint;
	sigemptyset(&sigint.sa_mask);
    sigint.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigquit.sa_handler = handle_sigquit;
	sigemptyset(&sigquit.sa_mask);
    sigquit.sa_flags = 0;
	sigaction(SIGQUIT, &sigquit, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
