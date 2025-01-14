#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <limits.h>

#define IS_TK_FORK	"\033[093mhas taken a fork\033[0m"
#define IS_EAT		"\033[092mis eating\033[0m"
#define IS_SLEEP	"\033[094mis sleeping\033[0m"
#define IS_THINK	"\033[095mis thinking\033[0m"
#define IS_DIE		"\033[031mdied\033[0m"

typedef struct s_data
{
	int			nb_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_to_eat;
	uint64_t	start_time;
} t_data;

typedef struct s_philo
{
	int	id;
	//t_data data;
} t_philo;

int			ft_atoi(char *str);
int			init_data(t_data *data, char **av, int ac);
void		error(char *str);
int			check_data(t_data *data);
int			check_ac(int ac);
void		init_philo(t_philo *philo, t_data *data);
void		display_status(t_philo philo, char *status, t_data *data);
uint64_t	get_time(void);
uint64_t	get_cur_time(uint64_t start_time);
void		ft_thread(t_philo *philo, t_data *data);
#endif