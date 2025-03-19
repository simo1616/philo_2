/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:46:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/03/19 16:30:12 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <inttypes.h>
# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define IS_TK_FORK "\033[093mhas taken a fork\033[0m"
# define IS_EAT "\033[092mis eating\033[0m"
# define IS_SLEEP "\033[094mis sleeping\033[0m"
# define IS_THINK "\033[095mis thinking\033[0m"
# define IS_DIE "\033[031mdied\033[0m"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					nb_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_to_eat;
	int					death_rep;
	uint64_t			start_time;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		print_mutex;
	pthread_t			monitor;
}						t_data;

struct					s_philo
{
	int					id;
	int					cnt_meals;
	pthread_t			thread;
	uint64_t			last_meal;
	t_data				*data;
};

int						ft_atoi(char *str);
void					error(char *str);

int						init_data(t_philo **philo, t_data *data, char **av,
							int ac);
int						init_values(t_data *data, char **av, int ac);
void					init_philo(t_philo *philo, t_data *data);
int						init_forks_mutex(t_data *data);
int						ft_thread(t_philo *philo, t_data *data);
void					*ft_routine(void *arg);
int						take_forks(t_philo *philo, int left_fork,
							int right_fork);
int						eat_action(t_philo *philo);
int						sleep_and_think(t_philo *philo);
int						check_death(t_philo *philo, t_data *data);
int						check_if_dead(t_data *data, t_philo *philo);
int						check_meals_count(t_data *data, int i);
int						monitor_philos(t_data *data, int *all_ate_enough);

int						check_data(t_data *data);
int						check_ac(int ac);
void					display_status(t_philo philo, char *status,
							t_data *data);
uint64_t				get_time(void);
uint64_t				get_cur_time(uint64_t start_time);
void					ft_usleep(uint64_t duration, t_data *data);
void					*death_monitor(void *arg);

void					destroy_and_free(t_philo *philo, t_data *data);
#endif