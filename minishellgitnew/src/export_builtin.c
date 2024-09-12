#include "minishell.h"

char	**realloc_2dchar(char **src, char *string, int i)
{
	char	**result;
	int		size;

	while (src[i] != 0)
		i ++;
	size = i;
	result = ft_calloc((size + 2), sizeof(char *));
	i = -1;
	while (++ i < size)
		result[i] = ft_strdup(src[i]);
	result[i] = ft_strdup(string);
	result[i + 1] = 0;
	free_2dchar(src);
	return (result);
}

int	check_envp(t_mini *mini, char *argument)
{
	int	i;

	i = 0;
	while (mini->envp[i] != 0)
	{
		if (ft_strncmp(mini->envp[i], argument, ft_strlen(argument)) == 0)
			return (i + 1);
		i ++;
	}
	return (0);
}

void	change_envp(t_mini *mini, char *name, char *string)
{
	int	i;

	i = 0;
	while (mini->envp[i] != 0)
	{
		if (ft_strncmp(mini->envp[i], name, ft_strlen(name)) == 0)
		{
			free(mini->envp[i]);
			mini->envp[i] = ft_strdup(string);
		}
		i ++;
	}
}

void	ft_export(t_mini *mini)
{
	char	*string;
	char	*string2;
	int		j;
	int		i;

	i = 0;
	if (mini->argc < 2)
		return ;
	while (++ i < mini->argc)
	{
		j = search_var(mini, mini->arguments[i]);
		if (j != 0)
		{
			string = ft_strjoin(mini->variables[j - 1].name, "=");
			string2 = ft_strjoin(string, mini->variables[j - 1].value);
			if (check_envp(mini, string) == 0)
				mini->envp = realloc_2dchar(mini->envp, string2, 0);
			else
				change_envp(mini, mini->variables[j - 1].name, string2);
			free(string);
			free(string2);
		}
	}
}
