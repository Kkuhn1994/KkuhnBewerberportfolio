/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:27:53 by kkuhn             #+#    #+#             */
/*   Updated: 2024/11/03 17:47:22 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../tools/libft/libft.h"
# include "garbage_collector.h"
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
	char	*name;
	char	*value;
}			t_var;

typedef struct mini_t
{
	int		exitcode;
	int		exitstatus;
	char	*line;
	char	**envp;
	t_var	*variables;
	size_t	nr_var;
	char	**arguments;
	int		finished;
	int		fdin;
	int		argc;
	int		store;
	int		store2;
}			t_mini;

//Norminated
int		count_parts(char *cmd);
int		count_pipeparts(char *cmd);
char	*ft_str_safe(char **cmd, char c, char a, char b);
void	ft_short2(int *counter, char **cmd, char c);
void	ft_short(int *i, char **commands, char **cmd, char c);

// EXEC_FILES
void	exec(char *cmd, t_mini *mini);
void	execute(t_mini *mini);
void	execute_pipes(t_mini *mini, int i);
void	unset(t_mini *mini);
void	exit_programm(t_mini *mini);
void	echo(t_mini *mini, int i);
void	show_env(t_mini *mini);
void	change_directory(char *path, t_mini *mini);
void	show_path(t_mini *mini);
void	execvecall_for_everythingelse(t_mini *mini);
void	new_line(void);
void	execute_pipes(t_mini *mini, int i);

// UTILS

char	*find_path(char *envp[], char *cmd);
int		check_for_pipes(char *str);
void	redirect(char *cmd, t_mini *mini);
char	*ft_remove_space(char *cmd);
char	*remove_end_spaces(char *string);
int		openfile(char *filename, int mode, int is_here_doc);
int		input_stuff(t_mini *mini, int *i);
int		output_stuff(t_mini *mini, int i);
char	*increment(char *string);

// ALLOCATIONS
void	realloc_smaller_2d(t_mini *mini, char *string);
char	**realloc_2dchar(char **src, char *string, int i);
char	**parse_pipes(t_mini *mini, char **cmd);

// SIGNALS
void	handle_sigint(int sig);
void	handle_sigterm(int sig);
void	add_signalhandler(t_mini *mini);

void	print_arguments(char **arguments);
void	init(t_mini *ministruct, char **envp);
char	**allocate_command(char *cmd, t_mini *mini, int i);
int		search_var(t_mini *mini, char *string);
void	save_var(t_mini *mini, int i);
void	read_perma_history(void);
void	perma_history(char *cmdline);
void	ft_export(t_mini *mini);
int		check_envp(t_mini *mini, char *argument);
char	*var_value(char *string, int i);

// PARSING
char	**alloc_pipes(t_mini *mini, char **cmd);

#endif
