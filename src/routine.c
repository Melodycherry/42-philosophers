/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 14:19:25 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *arg) 
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(200);
	while (!philo->data->is_dead)
	{
		// A RAJOUTER PLUS TARD QD LE MONITOR SERA BACK : 
		//if (philo->data->repetition > 0 && philo->meal_num >= philo->data->repetition) // si un philo a deja assez mange il sort 
		// 	break;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo) // ajouter meal num somewhere 
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->philo_id % 2 == 0)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_lock(first);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_action(philo, "has taken another fork"); // a changer 
	print_action(philo, "is eating");
	philo->last_meal = get_time();
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}
