/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:01:41 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/15 20:34:08 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_programm(char *errormessage)
{
	ft_putstr_fd(errormessage, 2);
	exit(1);
}

void	write_message(char *action, t_philo *philo, char *color)
{
	char	*id_string;

	pthread_mutex_lock(&philo->data->write);
	ft_putstr_fd(color, 1);
	ft_putstr_fd("philo", 1);
	ft_putstr_fd(" ", 1);
	id_string = ft_itoa(philo->id);
	ft_putstr_fd(id_string, 1);
	free(id_string);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd((int)(gettime() - philo->start_time), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(action, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(COLOR_RESET, 1);
	pthread_mutex_unlock(&philo->data->write);
}

time_t	gettime(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	free_function(t_data *data)
{
	free(data->forks);
	free(data->philos);
	free(data->threads);
}

int	check(t_data *data)
{
	if (data->num_philo > 200)
	{
		ft_putstr_fd("number philo invalid", 1);
		return (1);
	}
	if (data->num_philo == 1)
	{
		init_threads(data);
		pthread_mutex_init(&data->forks[0], NULL);
		pthread_mutex_init(&data->write, NULL);
		pthread_create(&data->threads[0], 0, &single_philo, data);
		pthread_join(data->threads[0], NULL);
		pthread_mutex_destroy(&data->forks[0]);
		pthread_mutex_destroy(&data->write);
		return (1);
	}
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
	{
		ft_putstr_fd("time invalid", 1);
		return (1);
	}
	return (0);
}
