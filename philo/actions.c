/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:09:37 by kkuhn             #+#    #+#             */
/*   Updated: 2024/09/05 17:35:55 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	if (check_death(philo) != 0)
		return ;
	philo->start_think = gettime();
	philo->time_to_think = (philo->time_to_die
			- (gettime() - philo->start_eat)) * 0.5;
	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_unlock(&philo->data->write);
	write_message("thinks", philo, COLOR_YELLOW);
	while (gettime() - philo->start_think < philo->time_to_think)
		usleep(100);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deathlock);
	if (philo->data->finished == 1)
	{
		pthread_mutex_unlock(&philo->data->deathlock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deathlock);
	return (0);
}

void	take_forks(t_philo *philo)
{
	int	l;
	int	r;

	l = philo->id - 1;
	r = philo->id % philo->numphilo;
	if (check_death(philo) != 0)
		return ;
	pthread_mutex_lock(&philo->data->arbitrator2);
	if (l < r)
	{
		pthread_mutex_lock(&philo->data->forks[l]);
		write_message("takes left fork", philo, COLOR_BLUE);
		pthread_mutex_lock(&philo->data->forks[r]);
		write_message("takes right fork", philo, COLOR_BLUE);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[r]);
		write_message("takes right fork", philo, COLOR_BLUE);
		pthread_mutex_lock(&philo->data->forks[l]);
		write_message("takes left fork", philo, COLOR_BLUE);
	}
	pthread_mutex_unlock(&philo->data->arbitrator2);
}

void	eating(t_philo *philo)
{
	philo->start_eat = gettime();
	if (check_death(philo) != 0)
		return ;
	write_message("is eating", philo, COLOR_MAGENTA);
	while (gettime() < philo->start_eat + philo->time_to_eat)
		usleep(100);
	pthread_mutex_lock(&philo->arbitrator);
	pthread_mutex_unlock(&philo->arbitrator);
}

void	drop_forks(t_philo *philo)
{
	int	l;
	int	r;

	if (check_death(philo) != 0)
		return ;
	l = philo->id - 1;
	r = philo->id % philo->numphilo;
	if (l > r)
	{
		if (pthread_mutex_unlock(&philo->data->forks[l]) != 0)
			perror("fork unlock l");
		write_message("dropped left fork", philo, COLOR_GREEN);
		if (pthread_mutex_unlock(&philo->data->forks[r]) != 0)
			perror("fork unlock r");
		write_message("dropped right fork", philo, COLOR_GREEN);
	}
	else
	{
		if (pthread_mutex_unlock(&philo->data->forks[r]) != 0)
			perror("fork unlock r");
		write_message("dropped right fork", philo, COLOR_GREEN);
		if (pthread_mutex_unlock(&philo->data->forks[l]) != 0)
			perror("fork unlock l");
		write_message("dropped left fork", philo, COLOR_GREEN);
	}
}
