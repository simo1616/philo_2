#include "philo.h"

int	init_forks_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philos);
	if(!data->forks)
		return (0);
	while(i < data->nb_of_philos)
	{
		if(pthread_mutex_init(&data->forks[i], NULL))
		{
			while (--i >= 0)
                pthread_mutex_destroy(&data->forks[i]);
			error("Mutex_fork_initialising FAILLED");
            free(data->forks);
            return (0);
		}
		i++;
	}
	return (1);
}


int	init_data(t_philo **philo, t_data *data, char **av, int ac)
{
	data->nb_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
	{
		data->nb_to_eat = ft_atoi(av[5]);
		if(data->nb_to_eat <= 0)
		{
			error("Invalid nb_to_eat");
			return(0);
		}
	}
	else
		data->nb_to_eat = -1;
	data->death_rep = 0;
	*philo = (t_philo *)malloc((sizeof(t_philo) * data->nb_of_philos));
	if(!(*philo))
		return (0);
	data->start_time = get_time();
	data->philo = *philo;
	if(!init_forks_mutex(data))
		return (0);
	if(pthread_mutex_init(&data->death_mutex, NULL))
	{
		error("Mutex_initialising FAILLED");
		return (0);
	}
	
	return(1);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].last_meal = get_time();
		philo[i].cnt_meals = 0;
		i++;
	}
}