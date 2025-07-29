/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:33:35 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/29 16:27:25 by mlaffita         ###   ########.fr       */
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
t_bool	is_valid_int(char *str);
t_bool	is_valid_input(char **av);
int		easy_atoi(const char *str);
// init
void	init_all(t_data *data, int ac, char **av);
void	init_data(t_data *data );
void	init_philos(t_data *data);
void	init_forks(t_data *data);
void	fill_struct(t_data *data, int ac, char **av);
// routine
void	*philo_routine(void *arg);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
// thread
int		create_thread(t_data *data);
void	join_threads(t_data *data);
void	*monitoring(void *arg);
int		game_over(t_philo *philo);
// Time
long	get_time(void);
long	current_time(t_data *data);
//void	ft_usleep(t_philo *philo, long duration);
void	ft_usleep(long time_in_ms);
// utils
void	print_action(t_philo *philo, char *msg);

#endif 