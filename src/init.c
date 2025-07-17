/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:07:34 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/17 13:49:21 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// init toute la struct ?? 
void	init_all(t_philo *philo )
{
	philo->num_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->num_meals = 0;
	philo->philo_id = 0;
	philo->thread = 0;
}
void	fill_struct(t_philo *philo, int ac, char **av)
{
	philo->num_philo = easy_atoi(av[1]);
	philo->time_to_die = easy_atoi(av[2]);
	philo->time_to_eat = easy_atoi(av[3]);
	philo->time_to_sleep = easy_atoi(av[4]);
	if (ac == 6)
		philo->num_meals = easy_atoi(av[5]);
}

// init mutex separement ? check comment ca marche 