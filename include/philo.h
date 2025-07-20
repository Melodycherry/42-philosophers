/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:33:35 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 17:50:44 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
void 	init_all(t_data *data, int ac, char **av);
void	init_data(t_data *data );
void	init_philos(t_data *data);
void	init_forks(t_data *data);
void	fill_struct(t_data *data, int ac, char **av);
// routine
void	*philo_routine(void *arg);
// thread
int		create_thread(t_data *data);
void	join_threads(t_data *data);

#endif 