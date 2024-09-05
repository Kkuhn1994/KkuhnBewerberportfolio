#include "minishell.h"

char	*ft_remove_space(char *cmd)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (cmd[i + j] != 0)
	{
		if (cmd[i + j] == ' ')
			j ++;
		if (cmd[i + j] == '\"')
			cmd[i] = '\"';
		else
			cmd[i] = cmd[i + j];
		i ++;
	}
	cmd[i + j] = 0;
	return (cmd);
}

char	*increment(char *string)
{
	char	*number;
	char	*returnstring;
	int		nr;

	number = ft_strchr(string, '=') + 1;
	nr = ft_atoi(number) + 1;
	number = ft_itoa(nr);
	returnstring = ft_strjoin("SHLVL=", number);
	free(number);
	return (returnstring);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0)
		return (ft_strdup(s2));
	result = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i ++;
	}
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i ++;
		j ++;
	}
	result[i] = 0;
	free(s1);
	return (result);
}

void	init(t_mini *ministruct, char **envp)
{
	int	i;

	i = 0;
	read_perma_history();
	ministruct->nr_var = 0;
	ministruct->argc = 0;
	while (envp[i] != 0)
		i ++;
	ministruct->envp = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "SHLVL", 5) != 0)
			ministruct->envp[i] = ft_strdup(envp[i]);
		else
			ministruct->envp[i] = increment(envp[i]);
		i ++;
	}
	ministruct->envp[i] = 0;
	realloc_smaller_2d(ministruct, "OLDPWD");
}
