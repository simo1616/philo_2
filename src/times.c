/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:45:58 by mbendidi          #+#    #+#             */
/*   Updated: 2025/01/17 09:45:59 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t duration, t_data *data)
{
	uint64_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < duration)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_rep)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		usleep(50);
	}
}

uint64_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
	{
		error("gettimeofday() FAILED!\n");
		return (-1);
	}
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

uint64_t	get_cur_time(uint64_t start_time)
{
	uint64_t	cur_time;

	cur_time = get_time();
	return (cur_time - start_time);
}
