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

	init_philo(philo, &data);
	ft_thread(philo, &data);

	//funct qui free et destroy les thread et mutex
	free(philo);
	return (0);
}

	// printf("tous les étape sont bien dérouler \n");
	// printf("AFFICHAGE DES DATA \n");
	// printf("nb_of_philos = %d\n", data.nb_of_philos);
	// printf("time_to_die = %d\n", data.time_to_die);
	// printf("time_to_eat = %d\n", data.time_to_eat);
	// printf("time_to_sleep = %d\n", data.time_to_sleep);
	// printf("nb_to_eat = %d\n", data.nb_to_eat);