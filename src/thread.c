#include "philo.h"


void	*death_monitor(void *arg)
{
    t_data	*data;
    int		i;
	int     all_ate_enough;

    data = (t_data *)arg;
    while (1)
    {
        i = 0;
		all_ate_enough = 1;
        while (i < data->nb_of_philos)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (data->death_rep)
            {
                pthread_mutex_unlock(&data->death_mutex);
                return (NULL);
            }
            if (get_time() - data->philo[i].last_meal > (uint64_t)data->time_to_die)
            {
                display_status(data->philo[i], IS_DIE, data);
                data->death_rep = 1;
                pthread_mutex_unlock(&data->death_mutex);
                return (NULL);
            }
			if (data->nb_to_eat != -1 && data->philo[i].cnt_meals < data->nb_to_eat)
                all_ate_enough = 0;
            pthread_mutex_unlock(&data->death_mutex);
            i++;
        }
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
        usleep(1000);

    while (1)
    {
        if (check_death(philo, data))
            return (NULL);

        pthread_mutex_lock(&data->forks[left_fork]);
        if (check_death(philo, data))
            return (NULL);
        display_status(*philo, IS_TK_FORK, data);

        pthread_mutex_lock(&data->forks[right_fork]);
        if (check_death(philo, data))
            return (NULL);
        display_status(*philo, IS_TK_FORK, data);

        pthread_mutex_lock(&data->death_mutex);
        philo->last_meal = get_time();
        display_status(*philo, IS_EAT, data);
        philo->cnt_meals++;
        pthread_mutex_unlock(&data->death_mutex);

        ft_usleep(data->time_to_eat, data);

        pthread_mutex_unlock(&data->forks[left_fork]);
        pthread_mutex_unlock(&data->forks[right_fork]);

        if (data->nb_to_eat != -1 && philo->cnt_meals >= data->nb_to_eat)
            return (NULL);

        if (check_death(philo, data))
            return (NULL);
        display_status(*philo, IS_SLEEP, data);
        ft_usleep(data->time_to_sleep, data);

        if (check_death(philo, data))
            return (NULL);
        display_status(*philo, IS_THINK, data);
    }
    return (NULL);
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
	while(i < data->nb_of_philos)
	{
		if(pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]))
		{
			error("Erreur lors de la création du thread\n");
			return (0);
		}
		i++;
	}
	pthread_join(data->monitor, NULL);
	i = 0;
	while(i < data->nb_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (1);
}
