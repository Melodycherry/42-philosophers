/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/05 16:06:02 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (!philo->data->is_dead)
	{
		eating(philo);
		if (philo->data->repetition > 0
			&& philo->meal_num >= philo->data->repetition)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	odd_or_even_philo(philo, &first, &second);
	pthread_mutex_lock(first);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_action(philo, "has taken another fork");
	pthread_mutex_lock(&philo->data->mutex_state);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->mutex_state);
	print_action(philo, "is eating 🍝");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->mutex_state);
	philo->meal_num++;
	pthread_mutex_unlock(&philo->data->mutex_state);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

void	odd_or_even_philo(t_philo *philo,
			pthread_mutex_t **first, pthread_mutex_t **second)
{
	if (philo->philo_id % 2 == 0)
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
	else
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
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
