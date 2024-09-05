/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:30:03 by kkuhn             #+#    #+#             */
/*   Updated: 2024/09/05 17:37:01 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeptime(t_philo *philo)
{
	if (check_death(philo) != 0)
		return ;
	philo->start_sleep = gettime();
	write_message("sleeps", philo, COLOR_CYAN);
	while (gettime() - philo->start_sleep < philo->time_to_sleep)
		usleep(100);
}

void	*routine(void *input)
{
	t_philo	*philo;
	int		died;

	died = 0;
	philo = input;
	while (gettime() < philo->start_time)
		usleep(100);
	if (philo->id % 2 == 0)
		think(philo);
	while (died != 1 && philo->num_meals > philo->nrmeals)
	{
		take_forks(philo);
		eating(philo);
		drop_forks(philo);
		philo->nrmeals++;
		sleeptime(philo);
		think(philo);
		pthread_mutex_lock(&philo->data->deathlock);
		if (philo->nrmeals < philo->num_meals)
			philo->finished = 1;
		died = philo->data->finished;
		pthread_mutex_unlock(&philo->data->deathlock);
	}
	return (NULL);
}

void	*grimreaper(void *input)
{
	size_t	i;
	t_data	*data;
	int		finished;

	data = input;
	finished = 0;
	while (finished == 0)
	{
		i = -1;
		while (++ i < data->num_philo)
		{
			pthread_mutex_lock(&data->deathlock);
			if (gettime() - data->philos[i].start_eat > data->time_to_die)
			{
				pthread_mutex_lock(&data->arbitrator2);
				data->finished = 1;
				finished = data->finished;
				pthread_mutex_unlock(&data->arbitrator2);
				if (data->philos[i].nrmeals < data->philos[i].num_meals)
					write_message("died", &data->philos[i], COLOR_RED);
			}
			pthread_mutex_unlock(&data->deathlock);
		}
	}
	return (NULL);
}

void	threads(t_data *data)
{
	size_t	i;

	init_threads(data);
	i = -1;
	mutex_init(data);
	pthread_create(&data->threads[data->num_philo], 0, &grimreaper, data);
	while (++ i < data->num_philo)
		pthread_create(&data->threads[i], 0, &routine, &data->philos[i]);
	i = -1;
	while (++ i < data->num_philo)
		pthread_join(data->threads[i], 0);
	pthread_mutex_lock(&data->arbitrator2);
	data->finished = 1;
	pthread_mutex_unlock(&data->arbitrator2);
	pthread_join(data->threads[i], 0);
	i = -1;
	while (++ i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philos[i].arbitrator);
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->arbitrator2);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.start_time = gettime() + 1000;
	if (init(&data, argc, argv) != 0)
		exit_programm("not enough, too many or wrong arguments");
	if (check(&data) == 0)
		threads(&data);
	free_function(&data);
	return (0);
}
