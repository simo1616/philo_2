#include "philo.h"


int	main (int ac, char **av)
{
	t_data data;
	t_philo *philo;

	if(!check_ac(ac))
		return(1);
	if(!init_data(&philo, &data, av, ac))
		return(1);
	if(!check_data(&data))
		return (1);
	if (data.nb_of_philos == 1)
    {
        display_status(philo[0], IS_TK_FORK, &data);
        ft_usleep(data.time_to_die, &data);
        display_status(philo[0], IS_DIE, &data);
        destroy_and_free(philo, &data);
        return (0);
    }

	init_philo(philo, &data);
	ft_thread(philo, &data);
	destroy_and_free(philo, &data);
	return (0);
}
