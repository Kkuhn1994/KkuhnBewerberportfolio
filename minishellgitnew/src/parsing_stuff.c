#include "minishell.h"

void	ft_short2(int *counter, char **cmd, char c)
{
	cmd[0]++;
	counter[0]++;
	while (cmd[0][0] != c)
		cmd[0]++;
	cmd[0]++;
}

char	*ft_str_safe(char **cmd, char c, char a, char b)
{
	int		j;
	char	*string;

	j = 0;
	while (cmd[0][j] != c && cmd[0][j] != 0)
		j++;
	string = malloc ((j + 1) * sizeof(char));
	j = 0;
	while (*cmd[0] != c && *cmd[0] != b && *cmd[0] != a && *cmd[0] != 0)
	{
		string[j] = *cmd[0];
		j ++;
		cmd[0]++;
	}
	string[j] = 0;
	return (string);
}

void	ft_short(int *i, char **commands, char **cmd, char c)
{
	cmd[0]++;
	commands[*i] = ft_str_safe(cmd, c, 0, 0);
	*i += 1;
	cmd[0]++;
}

int	count_pipeparts(char *cmd)
{
	int	counter;

	counter = 0;
	while (*cmd != 0)
	{
		if (*cmd == '<' || *cmd == '|' || *cmd == '>')
		{
			counter += 2;
			cmd = cmd + 2;
			while (*cmd != '|' && *cmd != '<' && *cmd != '>' && *cmd != 0)
				cmd ++;
		}
		else
		{
			counter ++;
			while (*cmd != '|' && *cmd != '<' && *cmd != '>' && *cmd != 0)
				cmd ++;
		}
	}
	return counter;
}

int	count_parts(char *cmd)
{
	int	counter;
	int	is_word;

	is_word = 0;
	counter = 0;
	if (check_for_pipes(cmd) == 0)
		return count_pipeparts(cmd);
	while (*cmd != 0)
	{
		if (*cmd != ' ' && *cmd != '\'' && *cmd != '"' && *cmd != '|' && *cmd != '<' && *cmd != '>' && *cmd != 0)
		{
			counter ++;
			while (*cmd != ' ' && *cmd != '\'' && *cmd != 0 && *cmd != '"')
				cmd ++;
		}
		if (*cmd == '\'')
			ft_short2(&counter, &cmd, '\'');
		if (*cmd == '"')
			ft_short2(&counter, &cmd, '"');
		if (*cmd == ' ')
			cmd ++;
	}
	return (counter);
}

char	**cmd_in_folder(char *cmd)
{
	char	**command;

	command = malloc (2 * sizeof(char *));
	command[0] = ft_strdup(cmd);
	command[1] = 0;
	return (command);
}

char *remove_end_spaces(char *string)
{
	int i;
	int store_size;
	int count_spaces;
	char *result;

	i = ft_strlen(string);
	store_size = i;
	count_spaces = 0;
	while(string[i - 1] == ' ' && i > 0)
	{
		count_spaces ++;
		i --;
	}
	result = malloc(store_size + 1 - count_spaces);
	i = 0;
	while(i < store_size - count_spaces)
	{
		result[i] = string[i];
		i ++;
	}
	result[i] = 0;
	free(string);
	return result;
}

void	parse_pipe_cmd(char **cmd, int *i, char **p)
{
	char *string;
	
	if ((p[0][0] == '<' || p[0][0] == '>') && p[0][0] == p[0][1])
	{
		cmd[*i] = malloc(3);
		cmd[*i][0] = p[0][0];
		cmd[*i][1] = p[0][0];
		cmd[*i][2] = 0;
		p[0] += 2;
	}
	else
	{
		cmd[*i] = malloc (2);	
		cmd[*i][0] = p[0][0];
		cmd[*i][1] = 0;
	}
	*i += 1;
	p[0] += 1;
	while(p[0][0] == ' ')
		p[0] ++;
	string = ft_str_safe(&p[0], '|', '<', '>');
	cmd[*i] = remove_end_spaces(string);
	*i += 1;
}

char *pipe_cmd(char *line, int *i)
{
	int		j;
	char	*cmd;

	j = 0;
	if (line[*i] == '|')
	{
		*i += 1;
		return (ft_strdup("|"));
	}
	if (line[*i] == '<')
	{
		*i += 1;
		if(line[*i] == '<')
		{
			*i += 1;
			return (ft_strdup("<<"));
		}
		else
			return (ft_strdup("<"));
	}
	if (line[*i] == '>')
	{
		*i += 1;
		if(line[*i] == '>')
		{
			*i += 1;
			return (ft_strdup(">>"));
		}
		else
			return (ft_strdup(">"));
	}
	while (line[*i + j] != '|' && line[*i + j] != '<'
		&& line[*i + j] != '>' && line[*i + j] != 0)
		j ++;
	cmd = malloc(j + 1);
	j = 0;
	while (line[*i] != '|' && line[*i] != '<'
		&& line[*i] != '>' && line[*i] != 0)
	{
		cmd[j] = line[*i];
		*i += 1;
		j ++;
	}
	cmd[j] = 0;
	return cmd;
}

char **alloc_pipes(t_mini *mini, char **cmd)
{
	int i;
	int j;
	char *string;

	i = 0;
	j = 0;
	while(mini->line[i] != 0)
	{
		while(mini->line[i] == ' ')
			i ++;
		string = pipe_cmd(mini->line, &i);
		cmd[j] = remove_end_spaces(string);
		j ++;
	}
	cmd[j] = 0;
	return cmd;
}

char	**allocate_command(char *cmd, t_mini *mini, int i)
{
	char	**commands;
	int		size;

	if (ft_memcmp(cmd, "./", 2) == 0)
		return (cmd_in_folder(cmd));
	size = count_parts(cmd);
	if (mini->argc == 0)
		mini->argc = size;
	commands = malloc ((size + 1) * sizeof(char *));
	// printf("%d\n", size);
	if (check_for_pipes(cmd) == 0)
		return alloc_pipes(mini, commands);
	while (i < size)
	{
		if (*cmd != ' ' && *cmd != '\'' && *cmd != '"')
		{
			commands[i] = ft_str_safe(&cmd, ' ',0 , 0);
			i ++;
		}
		else if (*cmd == '\'')
			ft_short(&i, commands, &cmd, '\'');
		else if (*cmd == '"')
			ft_short(&i, commands, &cmd, '"');
		else if (*cmd == ' ')
			cmd ++;
	}
	commands[size] = 0;
	return (commands);
}
