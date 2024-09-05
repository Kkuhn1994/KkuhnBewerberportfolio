#include "minishell.h"

void	change_old_pwd(t_mini *mini, int changed, int i)
{
	char	*pwd_string;
	char	*oldpwd;

	oldpwd = 0;
	if (check_envp(mini, "PWD") != 0)
		oldpwd = var_value(mini->envp[check_envp(mini, "PWD") - 1], 3);
	else if (check_envp(mini, "OLDPWD") != 0)
		oldpwd = ft_strdup("") ;
	else
		return;
	pwd_string = ft_strjoin("OLDPWD=", oldpwd);
	while (mini->envp[++i] != 0)
	{
		if (ft_strncmp(mini->envp[i], "OLDPWD", 6) == 0)
		{
			free(mini->envp[i]);
			mini->envp[i] = ft_strdup(pwd_string);
			changed = 1;
		}
	}
	if (changed == 0)
		mini->envp = realloc_2dchar(mini->envp, pwd_string, 0);
	free(pwd_string);
	free(oldpwd);
}

void	change_pwd(t_mini *mini, char *path)
{
	int		i;
	char	*pwd;
	

	pwd = malloc (1024);
	i = -1;
	if (chdir(path) != 0)
	{
		printf("zsh : no such file or directory: %s\n", path);
		return ;
	}
	change_old_pwd(mini, 0, -1);
	pwd = getcwd(pwd, 1024);
	while (mini->envp[++i] != 0)
	{
		if (ft_strncmp(mini->envp[i], "PWD", 3) == 0)
		{
			free(mini->envp[i]);
			mini->envp[i] = ft_strjoin("PWD=", pwd);
		}
	}
	free(pwd);
	free(path);

}

int	cd_special(char *path, t_mini *mini, int i, char *path2)
{
	if (ft_strncmp(path, "~", 1) == 0)
	{
		while (mini->envp[++ i] != 0)
		{
			if (ft_strncmp(mini->envp[i], "HOME=", 5) == 0)
			{
				path2 = ft_strjoin(&mini->envp[i][5], &path[1]);
				change_pwd(mini, path2);
				return 1;
			}
		}
	}
	else if (ft_strncmp(path, "-", 1) == 0)
	{
		while (mini->envp[++ i] != 0)
		{
			if (ft_strncmp(mini->envp[i], "OLDPWD=", 5) == 0)
			{
				path2 = ft_strdup(&mini->envp[i][7]);
				change_pwd(mini, path2);
				return 1;
			}
		}
	}
	return 0;
}

void	change_directory(char *path, t_mini *mini)
{
	char	*path2;
	int		i;

	i = 0;
	path2 = NULL;
	if (mini->argc > 2)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	else if (!path)
	{
		if (cd_special("~", mini, -1, path2) != 0)
			return ;
	}
	else
	{
		if (cd_special(path, mini, -1, path2) != 0)
			return ;
	}
	path2 = ft_strdup(path);
	change_pwd(mini, path2);
}

void	show_path(void)
{
	int		i;
	char	*path;

	i = 0;
	path = malloc(1024);
	path = getcwd(path, 1024);
	printf("%s\n", path);
	free(path);
}

void	show_env(t_mini *mini)
{
	int	i;

	i = -1;
	if (ft_strncmp(mini->arguments[1], "echo", 5) == 0)
	{
		echo(mini, 1);
		return ;
	}
	if (ft_strncmp(mini->arguments[1], "pwd", 4) == 0)
	{
		show_path();
		return ;
	}
	while (mini->envp[++ i] != 0)
		printf("%s\n", mini->envp[i]);
}

void	echo_print(char *string, t_mini *mini)
{
	int j;
	int i;

	i = 0;
	j = 0;
	
	while(string[i] != 0)
	{
		if(string[i] == '$')
		{
			j = search_var(mini , &string[i + 1]);
			if (j == 0)
				return ;
			printf("%s", mini->variables[j - 1].value);
			i += ft_strlen(mini->variables[j - 1].name);
		}
		else
			printf("%c", string[i]);
		i ++;
	}
}

void	echo(t_mini *mini, int i)
{
	while (mini->arguments[++ i] != 0)
	{
		echo_print(mini->arguments[i], mini);
		printf(" ");
	}
	printf("\n");
}
