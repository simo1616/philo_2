#include "philo.h"


void	*ft_routine(void *arg)
{
	t_philo *philo;
	t_data *data;
	
	philo = (t_philo *)arg;
	data = philo->data;
	philo->last_meal = get_time();
	if (philo->id % 2 == 0)
        usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		if(data->death_rep || 
			(get_time() - philo->last_meal > (uint64_t)data->time_to_die))
		{
			if(!data->death_rep)
			{
				display_status(*philo, IS_DIE, data);
				data->death_rep = 1;
			}
			pthread_mutex_unlock(&data->death_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->death_mutex);

	// 	printf("Philosopher %d last meal: %" PRIu64 ", current time: %" PRIu64 ", time_to_die: %d\n",
    //    philo->id, philo->last_meal, get_time(), data->time_to_die);


		display_status(*philo, IS_TK_FORK, data);
		display_status(*philo, IS_TK_FORK, data);

		pthread_mutex_lock(&data->death_mutex);
		display_status(*philo, IS_EAT, data);
		philo->last_meal = get_time();
		philo->cnt_meals++;
		pthread_mutex_unlock(&data->death_mutex);

		ft_usleep(data->time_to_eat * 1000, data);

		if(data->nb_to_eat == -1 || philo->cnt_meals < data->nb_to_eat)
			return NULL;

		display_status(*philo, IS_SLEEP, data);
		ft_usleep(data->time_to_sleep * 1000, data);
		display_status(*philo, IS_THINK, data);
		


	}
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
