/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:45:52 by mbendidi          #+#    #+#             */
/*   Updated: 2025/01/17 10:29:45 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->death_rep)
	{
		pthread_mutex_unlock(&data->death_mutex);
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(&data->forks[philo->id % data->nb_of_philos]);
		else
			pthread_mutex_unlock(&data->forks[philo->id - 1]);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

int	ft_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	if (pthread_create(&data->monitor, NULL, death_monitor, data))
	{
		error("Erreur lors de la création du thread moniteur\n");
		return (0);
	}
	while (i < data->nb_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]))
		{
			error("Erreur lors de la création du thread\n");
			return (0);
		}
		i++;
	}
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < data->nb_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (1);
}
