/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:50:40 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 17:50:41 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_for_pipes(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '<' || str[i] == '|' || str[i] == '>')
			return (0);
		i ++;
	}
	return (1);
}

char	*find_path(char *envp[], char *cmd)
{
	int		i;
	char	*path;
	char	*part_path;
	char	**paths;

	i = 0;
	if (ft_strnstr(&cmd[0], ".sh", ft_strlen(&cmd[0])) != 0
		|| ft_strnstr(&cmd[0], "/", ft_strlen(&cmd[0])) != 0)
		return (ft_remove_space(&cmd[0]));
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i ++;
	paths = ft_split(&envp[i][5], ':');
	i = -1;
	while (paths[++ i] != 0)
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
	}
	return (0);
}
