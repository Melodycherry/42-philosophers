/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 22:40:32 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_data	t_data;

// other struc pour chaque philo 
typedef struct s_philo
{
	int				philo_id;
	int				meal_num;
	int				last_meal; // check si int est ok pour ca 
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data // avec toutes les donnees
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				repetition;
	long			start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_data;

#endif