/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/15 16:48:10 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_philo
{
	pthread_t	thread;
	int			num_philo;
	int			philo_id; // pour numeroter les philo ? 
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_meals;
	// mutex right fork ?
	// mutex left fork ?? 
	
} t_philo;

