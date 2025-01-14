#include "philo.h"


int	init_data(t_data *data, char **av, int ac)
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
	data->start_time = get_time();
	//printf("\nstart_time a l'init : %lu\n***********\n", data->start_time);
	return(1);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_of_philos)
	{
		philo[i].id = i + 1;
		i++;
	}

}