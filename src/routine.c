/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:19:29 by mbendidi          #+#    #+#             */
/*   Updated: 2025/03/19 16:29:13 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo, int left_fork, int right_fork)
{
	int	first;
	int	second;

	if (philo->id % 2 == 0)
	{
		first = right_fork;
		second = left_fork;
	}
	else
	{
		first = left_fork;
		second = right_fork;
	}
	if (check_death(philo, philo->data))
		return (0);
	display_status(*philo, IS_TK_FORK, philo->data);
	pthread_mutex_lock(&philo->data->forks[second]);
	if (check_death(philo, philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[first]);
		pthread_mutex_unlock(&philo->data->forks[second]);
		return (0);
	}
	display_status(*philo, IS_TK_FORK, philo->data);
	return (1);
}

int	eat_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_time();
	display_status(*philo, IS_EAT, philo->data);
	philo->cnt_meals++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	ft_usleep(philo->data->time_to_eat, philo->data);
	return (1);
}

int	sleep_and_think(t_philo *philo)
{
	if (check_death(philo, philo->data))
		return (0);
	display_status(*philo, IS_SLEEP, philo->data);
	ft_usleep(philo->data->time_to_sleep, philo->data);
	if (check_death(philo, philo->data))
		return (0);
	display_status(*philo, IS_THINK, philo->data);
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	data = philo->data;
	left_fork = philo->id - 1;
	right_fork = philo->id % data->nb_of_philos;
	if (philo->id % 2 == 0)
		usleep(100000);
	while (1)
	{
		if (!take_forks(philo, left_fork, right_fork))
			return (NULL);
		if (!eat_action(philo))
			return (NULL);
		pthread_mutex_unlock(&data->forks[left_fork]);
		pthread_mutex_unlock(&data->forks[right_fork]);
		if (data->nb_to_eat != -1 && philo->cnt_meals >= data->nb_to_eat)
			return (NULL);
		if (!sleep_and_think(philo))
			return (NULL);
	}
	return (NULL);
}
