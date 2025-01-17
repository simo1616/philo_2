/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:44:53 by mbendidi          #+#    #+#             */
/*   Updated: 2025/01/17 09:53:08 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (!check_ac(ac))
		return (1);
	if (!init_data(&philo, &data, av, ac))
		return (1);
	if (!check_data(&data))
		return (1);
	init_philo(philo, &data);
	if (data.nb_of_philos == 1)
	{
		display_status(philo[0], IS_TK_FORK, &data);
		ft_usleep(data.time_to_die, &data);
		display_status(philo[0], IS_DIE, &data);
		destroy_and_free(philo, &data);
		return (0);
	}
	ft_thread(philo, &data);
	destroy_and_free(philo, &data);
	return (0);
}
