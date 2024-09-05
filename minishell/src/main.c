#include "minishell.h"

void	print_arguments(char **arguments)
{
	int	i;

	i = 0;

	while (arguments[i] != 0)
	{
		printf("%s\n", arguments[i]);
		i ++;
	}
}

int	main(int argc, char *argv[], char **env)
{
	t_mini	mini;

	// atexit(leaks);
	add_signalhandler(&mini);
	if (argc != 0)
		argv[1] = 0;
	init(&mini, env);
	while (mini.finished == 0)
	{
		mini.argc = 0;
		mini.line = readline("KUHN_SILVESTRI_SHELL % ");
		perma_history(mini.line);
		add_history(mini.line);
		mini.arguments = allocate_command(mini.line, &mini, 0);
		// print_arguments(mini.arguments);
		execute(&mini);
		free_stuff(&mini);
	}
	free_function(&mini);
	return (0);
}
