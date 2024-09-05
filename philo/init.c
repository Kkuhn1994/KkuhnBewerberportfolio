/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:08 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/15 17:35:15 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argument_valid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++ i < argc)
	{
		j = -1;
		while (argv[i][++ j] != 0)
			if (ft_isdigit((int)argv[i][j]) == 0)
				exit_programm("argument is invalid");
	}
	return (0);
}

int	init(t_data *data, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	check_argument_valid(argc, argv);
	data->finished = 0;
	data->i = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	return (0);
}

void	init_threads(t_data *data)
{
	size_t	i;

	i = 0;
	data->forks = malloc ((data->num_philo) * sizeof(pthread_mutex_t));
	data->threads = malloc ((data->num_philo + 1) * sizeof(pthread_t));
	data->philos = malloc ((data->num_philo) * sizeof(t_philo));
	while (i < data->num_philo)
	{
		data->philos[i].numphilo = data->num_philo;
		data->philos[i].start_time = data->start_time;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		data->philos[i].num_meals = data->num_meals;
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].start_eat = data->philos[i].start_time;
		data->philos[i].philo_died = 0;
		data->philos[i].nrmeals = 0;
		data->philos[i].finished = 0;
		i ++;
	}
}

void	mutex_init(t_data *data)
{
	size_t	i;

	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->arbitrator2, NULL);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->philos[i].arbitrator, NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		i ++;
	}
}
