/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/18 16:10:52 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					philo_id;
	int					meal_num;
	long long			last_meal;
	bool				full;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	int						num_philo;
	long long				time_to_die;
	long long				time_to_eat;
	long long				time_to_sleep;
	int						repetition;
	long long				start_time;
	bool					end;
	t_philo					*philo;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_state;
	pthread_mutex_t			mutex_print;
}	t_data;

#endif