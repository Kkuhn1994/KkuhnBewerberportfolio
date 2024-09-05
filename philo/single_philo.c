/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:28:46 by kkuhn             #+#    #+#             */
/*   Updated: 2024/08/15 18:51:33 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philo(void *input)
{
	t_data	*data;

	data = input;
	while (gettime() < data->start_time)
		usleep(100);
	pthread_mutex_lock(&data->forks[0]);
	write_message("has taken a fork", &data->philos[0], COLOR_CYAN);
	while (gettime() < data->start_time + data->time_to_die)
		usleep(100);
	write_message("died", &data->philos[0], COLOR_RED);
	pthread_mutex_unlock(&data->forks[0]);
	return (NULL);
}

static int	is_not_digit(const char *number, int *info_store)
{
	if (*number < '0' || *number > '9' )
	{
		if ((*number <= '\057' && info_store[1] == -1) || *number == '\e')
			return (0);
		if (*number == '-')
		{
			info_store[0] = -1;
			info_store[1] = -1;
		}
		else if (*number == '+')
			info_store[1] = -1;
		else if ((*number <= '\037' && *number >= '\016')
			|| *number >= '\041' || *number <= '\010')
			info_store[2] = 1;
		if ((*number == ' ' || *number >= '\072' ) && info_store[2] == 1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *number)
{
	int	num;
	int	info_store[4];

	info_store[3] = 0;
	info_store[0] = 1;
	info_store[1] = 0;
	info_store[2] = 0;
	num = 0;
	while (*number != 0)
	{
		if (is_not_digit(number, info_store) == 0)
			return (0);
		if (*number >= '0' && *number <= '9')
		{
			num = num * 10 + *number - '0';
			info_store[3] = 1;
		}
		number ++;
		if (!(*number >= '0' && *number <= '9') && (info_store[3] == 1))
			return (num * info_store[0]);
	}
	return (num * info_store[0]);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}
