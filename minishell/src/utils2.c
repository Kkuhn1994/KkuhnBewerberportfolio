#include "minishell.h"

int check_for_pipes(char **str)
{
	int i;

	i = 0;
	while(str[i] != 0)
	{
		if(strncmp(str[i], "|", 2) == 0)
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

void	handle_sigint(int sig)
{
	int	i;

	i = sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void handle_sigterm(int	sig, t_mini *mini)
{
	// free_function(mini);
	// free_stuff(mini);
    exit(0);
}

void	add_signalhandler(t_mini *mini)
{
	struct sigaction sigint;

	struct sigaction sigkill;
	struct termios	term;

	sigint.sa_handler = handle_sigint;
	sigemptyset(&sigint.sa_mask);
	sigaction(SIGINT, &sigint, NULL);
	sigkill.sa_handler = handle_sigint;
	sigemptyset(&sigkill.sa_mask);
	sigkill.sa_mask = 
	sigaction(SIGTERM, &sigkill, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
