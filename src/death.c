/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:27:48 by mbendidi          #+#    #+#             */
/*   Updated: 2025/03/19 16:22:17 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_data *data, t_philo *philo)
{
	if (get_time() - philo->last_meal > (uint64_t)data->time_to_die)
	{
		display_status(*philo, IS_DIE, data);
		data->death_rep = 1;
		return (1);
	}
	return (0);
}

int	check_meals_count(t_data *data, int i)
{
	if (data->nb_to_eat != -1 && data->philo[i].cnt_meals < data->nb_to_eat)
		return (1);
	return (0);
}

int	monitor_philos(t_data *data, int *all_ate_enough)
{
	int	i;

	i = 0;
	*all_ate_enough = 1;
	while (i < data->nb_of_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_rep)
		{
			pthread_mutex_unlock(&data->death_mutex);
			return (1);
		}
		if (check_if_dead(data, &data->philo[i]))
		{
			pthread_mutex_unlock(&data->death_mutex);
			return (1);
		}
		if (check_meals_count(data, i))
			*all_ate_enough = 0;
		pthread_mutex_unlock(&data->death_mutex);
		i++;
	}
	return (0);
}

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		all_ate_enough;

	data = (t_data *)arg;
	while (1)
	{
		if (monitor_philos(data, &all_ate_enough))
			return (NULL);
		if (data->nb_to_eat != -1 && all_ate_enough)
		{
			pthread_mutex_lock(&data->death_mutex);
			data->death_rep = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return (NULL);
		}
		usleep(50);
	}
}
