#include "minishell.h"

void	leaks()
{
	system("leaks minishell");
}

void	realloc_smaller_2d(t_mini *mini, char *string)
{
	char **envp;
	int i;
	int j;

	i = 0;
	while(mini->envp[i] != 0)
		i ++;
	envp = malloc((i) * sizeof(char *));
	i = 0;
	j = 0;
	while(mini->envp[j] != 0)
	{
		// printf("%s", mini->envp[j]);
		if (ft_strncmp(mini->envp[j], string, ft_strlen(string)) != 0)
		{
			envp[i] = ft_strdup(mini->envp[j]);
			i ++;
		}
		j ++;
	}
	envp[i] = 0;
	free_2dchar(mini->envp);
	mini->envp = envp;
}

void	free_function(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i] != 0)
	{
		free(mini->envp[i]);
		i ++;
	}
	free(mini->envp);
	while(mini->nr_var > 0)
	{
		free(mini->variables[mini->nr_var - 1].name);
		free(mini->variables[mini->nr_var - 1].value);
		mini->nr_var --;
	}
	free(mini->variables);
}

void	free_stuff(t_mini *mini)
{
	int	i;

	i = 0;
	free(mini->line);
	while (mini->arguments[i] != 0)
	{
		free(mini->arguments[i]);
		i ++;
	}
	free(mini->arguments);
}

void	free_2dchar(char **array)
{
	int	i;

	i = -1;
	while (array[++ i] != 0)
		free(array[i]);
	free(array);
}
