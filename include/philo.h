/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:33:35 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/05 16:33:45 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include "struct.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// FONCTIONS

// Parsing
t_bool			is_valid_int(char *str);
t_bool			is_valid_input(char **av);
int				first_check(int ac, char **av);
// init
void			init_all(t_data *data, int ac, char **av);
void			init_data(t_data *data );
void			init_philos(t_data *data);
void			init_forks(t_data *data);
int				fill_struct(t_data *data, int ac, char **av);
void			take_forks(t_data *data);
// routine
void			*philo_routine(void *arg);
void			odd_or_even_philo(t_philo *philo,
					pthread_mutex_t **first, pthread_mutex_t **second);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
// thread
int				create_thread(t_data *data);
void			join_threads(t_data *data);
// monitoring
void			*monitoring(void *arg);
int				all_philos_ate_enough(t_data *data);
int				check_philo_death(t_data *data);
// Time
long long		get_time(void);
long long		current_time(t_data *data);
void			ft_usleep(long time_in_ms);
// utils
void			print_action(t_philo *philo, char *msg);
int				one_philo_case(t_data *data);
void			destroy_and_free(t_data *data);
long long		easy_atol(const char *str);

#endif 