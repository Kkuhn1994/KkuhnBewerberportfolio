/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:05:36 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/15 17:36:38 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>
# define COLOR_RED		"\033[31m"
# define COLOR_GREEN	"\033[32m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_BLUE		"\033[34m"
# define COLOR_MAGENTA	"\033[35m"
# define COLOR_CYAN		"\033[36m"
# define COLOR_RESET	"\033[0m"

typedef struct s_data	t_data;

typedef struct philo_t{
	t_data			*data;
	int				id;
	size_t			num_meals;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_think;
	time_t			time_to_sleep;
	time_t			start_eat;
	time_t			start_sleep;
	time_t			start_think;
	time_t			start_time;
	int				numphilo;
	int				philo_died;
	size_t			nrmeals;
	int				finished;
	pthread_mutex_t	arbitrator;
}	t_philo;

typedef struct s_data {
	size_t			num_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	size_t			num_meals;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	arbitrator2;
	pthread_mutex_t	deathlock;
	pthread_t		*threads;
	int				finished;
	int				i;
}	t_data;

void	exit_programm(char *errormessage);
void	free_function(t_data *data);
time_t	gettime(void);
void	write_message(char *action, t_philo *philo, char *color);
int		init(t_data *data, int argc, char *argv[]);
void	init_threads(t_data *data);
int		check(t_data *data);
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	drop_forks(t_philo *philo);
void	*single_philo(void *input);
int		check_death(t_philo *philo);
void	mutex_init(t_data *data);
void	think(t_philo *philo);
int		ft_atoi(const char *number);
int		ft_isdigit(int a);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int number, int fd);
char	*ft_itoa(int n);
size_t	ft_strlen(char const *str);

#endif 