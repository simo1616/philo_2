#include "philo.h"


void	*ft_routine(void *arg)
{
	t_philo *philo;
	t_data *data;
	
	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
        usleep(1000);
	display_status(*philo, IS_TK_FORK, data);
	usleep(1000);
	display_status(*philo, IS_TK_FORK, data);

	display_status(*philo, IS_EAT, data);
	usleep(data->time_to_eat * 1000);
	display_status(*philo, IS_SLEEP, data);
	usleep(data->time_to_sleep * 1000);
	display_status(*philo, IS_THINK, data);
	usleep(1000);
	display_status(*philo, IS_DIE, data);
	return (NULL);
}

int	ft_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_of_philos)
	{
		if(pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]))
		{
			error("Erreur lors de la création du thread\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while(i < data->nb_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (1);
}
