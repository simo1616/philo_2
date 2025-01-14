#include "philo.h"

void	display_status(t_philo philo, char *status, t_data *data)
{
	printf("%04lu #%d %s\n", get_cur_time(data->start_time), philo.id, status);
}

	

void	error(char *str)
{
	printf("\033[091m%s\033[0m\n", str);
	return ;
}

