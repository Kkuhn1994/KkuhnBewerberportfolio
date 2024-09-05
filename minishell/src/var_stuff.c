#include "minishell.h"

char	*var_name(char *string, int i)
{
	char	*name;

	name = malloc((i + 1) * sizeof(char));
	i = -1;
	while (string[++i] != '=')
		name[i] = string[i];
	name[i] = 0;
	return (name);
}

char	*var_value(char *string, int i)
{
	char	*value;
	int		j;

	j = 0;
	value = malloc((ft_strlen(string) - i) * sizeof(char));
	while (string[++ i] != 0)
	{
		value[j] = string[i];
		j ++;
	}
	value[j] = 0;
	return (value);
}

void	save_var(t_mini *mini, int i)
{
	t_var		*varlist;
	size_t		j;
	char		*name;

	while (mini->arguments[0][i] != '=')
		i ++;
	name = var_name(mini->arguments[0], i);
	j = search_var(mini, name);
	if (j != 0)
	{
		free(mini->variables[j - 1].value);
		free(name);
		mini->variables[j - 1].value = var_value(mini->arguments[0], i);
		return ;
	}
	j = -1;
	free(name);
	varlist = malloc((mini->nr_var + 1) * sizeof(t_var));
	while (++ j < mini->nr_var)
		varlist[j] = mini->variables[j];
	varlist[j].name = var_name(mini->arguments[0], i);
	varlist[j].value = var_value(mini->arguments[0], i);
	j = -1;
	free(mini->variables);
	mini->variables = varlist;
	mini->nr_var ++;
}

int	search_var(t_mini *mini, char *string)
{
	size_t	i;

	i = 0;
	while (i < mini->nr_var)
	{
		if (ft_strncmp(string, mini->variables[i].name,
				ft_strlen(mini->variables[i].name) + 1) == 0)
			return (i + 1);
		i ++;
	}
	return (0);
}
