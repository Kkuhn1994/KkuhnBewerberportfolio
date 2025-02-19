/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:51:27 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/03 17:51:29 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigquit(int sig)
{
}

void	handle_sigint(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	add_signalhandler(t_mini *mini)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	struct termios		term;

	sigint.sa_handler = handle_sigint;
	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigquit.sa_handler = handle_sigquit;
	sigemptyset(&sigquit.sa_mask);
	sigquit.sa_flags = 0;
	sigaction(SIGQUIT, &sigquit, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
