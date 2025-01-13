#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && ((str[i] >= 13 && str[i] <= 9) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if(nb * sign > INT_MAX || nb * sign < INT_MIN )
		return (-1);
	return((int )nb * sign);
}

