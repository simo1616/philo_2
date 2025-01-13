#include "philo.h"


int check_ac(int ac)
{
	if(ac < 5 || ac > 6)
	{
		printf("\033[091mError: please enter : \033[0m\n");
		printf("\033[093m./philo <Philosophers> <time_to_die> \033[0m");
		printf("\033[093m<time_to_eat> <time_to_sleep> (<nb_eat>)\033[0m\n");
		return(0);
	}
	return(1);
}

int	check_data(t_data *data)
{
	if(data->nb_of_philos < 1)
	{
		error("\033[091mINVALIDE ARG OF NB_OF_PHILOS\033[0m");
		return(0);
	}
	if(data->time_to_die < 60)
	{
		error("\033[091mINVALIDE ARG OF TIME_TO_DIE\033[0m");
		return(0);
	}
	if(data->time_to_eat < 60)
	{
		error("\033[091mINVALIDE ARG OF TIME_TO_EAT\033[0m");
		return(0);
	}
	if(data->time_to_sleep < 60)
	{
		error("\033[091mINVALIDE ARG OF TIME_TO_SLEEP\033[0m");
		return(0);
	}
	return(1);
}
