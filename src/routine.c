/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/21 16:43:18 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg; // check si ok 
	
	if (philo->philo_id % 2 == 0)
		usleep(1000); // attention deadlock 
	while (!game_over(philo))
	{
		if (philo->data->repetition > 0 && philo->meal_num >= philo->data->repetition) // si un philo a deja assez mange il sort 
			break;
		eating(philo);
		if (game_over(philo)) // check car ca affiche de la merde 
			break;
		sleeping(philo);
		if (game_over(philo)) // donc a enlever si le pb est regle avec le mutex de printf
			break;
		thinking(philo);
	}
	return NULL;
}

void	eating(t_philo *philo)
{
	// FORK
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d ", current_time(philo->data), philo->philo_id);
	printf("has taken the left fork\n");
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken the right fork\n", current_time(philo->data), philo->philo_id);
	printf("has taken the left fork\n");

	//EAT
	pthread_mutex_lock(&philo->data->mutex_state);
	printf("%ld %d is eating\n", current_time(philo->data), philo->philo_id);
	philo->last_meal = get_time();
	philo->meal_num++;
	pthread_mutex_unlock(&philo->data->mutex_state);
	ft_usleep(philo, philo->data->time_to_eat);

	//UNLOCK LES FORKS
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	printf("%ld %d ", current_time(philo->data), philo->philo_id);
	printf("is sleeping\n");
	ft_usleep(philo, philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	printf("%ld %d ", current_time(philo->data), philo->philo_id);
	printf("is thinking\n");
}


