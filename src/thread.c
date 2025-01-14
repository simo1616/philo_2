#include "philo.h"

void	ft_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_of_philos)
	{
		display_status(philo[i], IS_TK_FORK, data);
		usleep(1000);
		display_status(philo[i], IS_TK_FORK, data);

		display_status(philo[i], IS_EAT, data);
		usleep(data->time_to_eat * 1000);
		display_status(philo[i], IS_SLEEP, data);
		usleep(data->time_to_sleep * 1000);
		display_status(philo[i], IS_THINK, data);
		usleep(1000);
		display_status(philo[i], IS_DIE, data);
		i++;
	}

}