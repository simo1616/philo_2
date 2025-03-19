/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:45:38 by mbendidi          #+#    #+#             */
/*   Updated: 2025/03/19 14:32:41 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_status(t_philo philo, char *status, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%04lu #%d %s\n", get_cur_time(data->start_time), philo.id, status);
	pthread_mutex_unlock(&data->print_mutex);
}

void	error(char *str)
{
	printf("\033[091m%s\033[0m\n", str);
	return ;
}
