/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:52:00 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 18:05:09 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_pipe_symbol(char *symbol, int *i)
{
	*i += 1;
	if (symbol[0] == symbol[1])
	{
		*i += 1;
		return (ft_substr(symbol, 0, 2));
	}
	return (ft_substr(symbol, 0, 1));
}

char	*pipe_cmd(char *line, int *i)
{
	int		j;
	char	*cmd;

	j = 0;
	if (line[*i] == '|' || line[*i] == '<' || line[*i] == '>')
		return (is_pipe_symbol(&line[*i], i));
	while (line[*i + j] != '|' && line[*i + j] != '<'
		&& line[*i + j] != '>' && line[*i + j] != 0)
		j ++;
	cmd = ft_gc_malloc(j + 1);
	j = 0;
	while (line[*i] != '|' && line[*i] != '<'
		&& line[*i] != '>' && line[*i] != 0)
	{
		cmd[j] = line[*i];
		*i += 1;
		j ++;
	}
	cmd[j] = 0;
	return (cmd);
}

char	**parse_pipes(t_mini *mini, char **cmd)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	while (mini->line[i] != 0)
	{
		while (mini->line[i] == ' ')
			i ++;
		string = pipe_cmd(mini->line, &i);
		cmd[j] = remove_end_spaces(string);
		j ++;
	}
	cmd[j] = 0;
	return (cmd);
}
