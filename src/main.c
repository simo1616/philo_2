#include "philo.h"


int	main (int ac, char **av)
{
	// if(ac < 5 || ac > 6)
	// {
	// 	printf("\033[091mError: please enter : \033[091m\n");
	// 	printf("\033[093m./philo <Philosophers> <time_to_die> <time_to_eat> <time_to_sleep> (<nb_eat>)\033[091m\n");
	// 	return(1);
	// }
	(void)ac;
	int i = 1;
	while (av[i])
	{
		printf("arg#%d = %d\n ", i, ft_atoi(av[i]));
		i++;
	}
	return (0);
}
