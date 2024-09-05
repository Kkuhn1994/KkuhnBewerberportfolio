/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:27:53 by kkuhn             #+#    #+#             */
/*   Updated: 2024/09/04 19:54:40 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../tools/libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct variable_t
{
	char *name;
	char *value;
} t_var;

typedef struct mini_t
{
	char	*line;
	char	**envp;
	t_var 	*variables;
	size_t	nr_var;
	char	**arguments;
	int		finished;
	int 	argc;
}	t_mini;

//EXEC_FILES
void	exec(char *cmd, t_mini *mini);
void	execute(t_mini *mini);
void	execute_pipes(t_mini *mini, int i);
void	unset(t_mini *mini);
void	exit_programm(t_mini *mini);
void	echo(t_mini *mini, int i);
void	show_env(t_mini *mini);
void	change_directory(char *path, t_mini *mini);
void	show_path(void);
void	ls(t_mini *mini);
void	new_line(void);

//UTILS
char	*find_path(char *envp[], char *cmd);
int		check_for_pipes(char **str);
void	redirect(char *cmd, int fdin, t_mini *mini);
char	*ft_remove_space(char *cmd);
int		openfile(char *filename, int mode, int is_here_doc);
char	*increment(char *string);

//ALLOCATIONS
void	free_2dchar(char **array);
void	realloc_smaller_2d(t_mini *mini, char *string);
char	**realloc_2dchar(char **src, char *string, int i);
void	free_function(t_mini *ministruct);
void	leaks(void);

//SIGNALS
void	handle_sigint(int sig);
void handle_sigterm(int	sig, t_mini *mini);
void	add_signalhandler(t_mini *mini);

void	print_arguments(char **arguments);
void	init(t_mini *ministruct, char **envp);
void	free_stuff(t_mini *mini);
char	**allocate_command(char *cmd, t_mini *mini, int i);
int		search_var(t_mini *mini, char *string);
void	save_var(t_mini *mini, int i);
void	read_perma_history(void);
void	perma_history(char *cmdline);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_export(t_mini *mini);
int		check_envp(t_mini *mini, char *argument);
char	*var_value(char *string, int i);

#endif
