/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stuff2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:51:50 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 18:05:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_in_folder(char *cmd)
{
	char	**command;

	command = ft_gc_malloc (2 * sizeof(char *));
	command[0] = ft_strdup(cmd);
	command[1] = 0;
	return (command);
}

char	*remove_end_spaces(char *string)
{
	int		i;
	int		store_size;
	int		count_spaces;
	char	*result;

	i = ft_strlen(string);
	store_size = i;
	count_spaces = 0;
	while (string[i - 1] == ' ' && i > 0)
	{
		count_spaces ++;
		i --;
	}
	result = ft_gc_malloc(store_size + 1 - count_spaces);
	i = 0;
	while (i < store_size - count_spaces)
	{
		result[i] = string[i];
		i ++;
	}
	result[i] = 0;
	return (result);
}

void	parse_pipe_cmd(char **cmd, int *i, char **p)
{
	char	*string;

	if ((p[0][0] == '<' || p[0][0] == '>') && p[0][0] == p[0][1])
	{
		cmd[*i] = ft_gc_malloc(3);
		cmd[*i][0] = p[0][0];
		cmd[*i][1] = p[0][0];
		cmd[*i][2] = 0;
		p[0] += 2;
	}
	else
	{
		cmd[*i] = ft_gc_malloc (2);
		cmd[*i][0] = p[0][0];
		cmd[*i][1] = 0;
	}
	*i += 1;
	p[0] += 1;
	while (p[0][0] == ' ')
		p[0]++;
	string = ft_str_safe(&p[0], '|', '<', '>');
	cmd[*i] = remove_end_spaces(string);
	*i += 1;
}

void	count_prefix(char **commands, char *cmd, int i, int size)
{
	while (i < size)
	{
		if (*cmd != ' ' && *cmd != '\'' && *cmd != '"')
		{
			commands[i] = ft_str_safe(&cmd, ' ', 0, 0);
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
	if (check_for_pipes(cmd) == 0)
		return (parse_pipes(mini, commands));
	commands = ft_gc_malloc ((size + 1) * sizeof(char *));
	count_prefix(commands, cmd, i, size);
	return (commands);
}
