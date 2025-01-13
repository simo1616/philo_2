#include "philo.h"


int	main (int ac, char **av)
{
	if(!check_ac(ac))
		return(1);

	//int i = 1;
	t_data data;

	if(!init_data(&data, av, ac))
		return(1);
	if(!check_data(&data))
		return (1);
	printf("tous les étape sont bien dérouler \n");
	printf("AFFICHAGE DES DATA \n");
	printf("nb_of_philos = %d\n", data.nb_of_philos);
	printf("time_to_die = %d\n", data.time_to_die);
	printf("time_to_eat = %d\n", data.time_to_eat);
	printf("time_to_sleep = %d\n", data.time_to_sleep);
	printf("nb_to_eat = %d\n", data.nb_to_eat);
	return (0);
}

