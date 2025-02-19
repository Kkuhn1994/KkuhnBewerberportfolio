/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:51:39 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 18:05:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	string = ft_gc_malloc ((j + 1) * sizeof(char));
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
	return (counter);
}

int	count_parts(char *cmd)
{
	int	counter;
	int	is_word;

	is_word = 0;
	counter = 0;
	if (check_for_pipes(cmd) == 0)
		return (count_pipeparts(cmd));
	while (*cmd != 0)
	{
		if (*cmd != ' ' && *cmd != '\'' && *cmd != '"'
			&& *cmd != '|' && *cmd != '<' && *cmd != '>' && *cmd != 0)
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
