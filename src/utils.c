#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 13 && str[i] <= 9) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0'); 
		i++;
	}
	return(nb * sign);
}
