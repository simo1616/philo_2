#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define IS_TK_FORK	"has taken a fork"
#define IS_EAT		"is eating"
#define IS_SLEEP	"is sleeping"
#define IS_THINK	"is thinking"
#define IS_DIE		"died"

typedef struct s_data
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_to_eat;
} t_data;

typedef struct s_philo
{
	int	id;
	//t_data data;
} t_philo;

int		ft_atoi(char *str);
int		init_data(t_data *data, char **av, int ac);
void	error(char *str);
int		check_data(t_data *data);
int		check_ac(int ac);
void	init_philo(t_philo *philo, t_data *data);
#endif