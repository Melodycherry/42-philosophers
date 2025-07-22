/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/22 14:59:35 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg; // check si ok 
	
	//printf("Philo %d started\n", philo->philo_id); // debug 
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo, 10); // attention deadlock
		//ft_usleep(philo, philo->data->time_to_eat / 2);
	while (!game_over(philo))
	{
		if (philo->data->repetition > 0 && philo->meal_num >= philo->data->repetition) // si un philo a deja assez mange il sort 
			break;
		eating(philo);
		// if (game_over(philo)) // check car ca affiche de la merde 
		// 	break;
		sleeping(philo);
		// if (game_over(philo)) // donc a enlever si le pb est regle avec le mutex de printf
		// 	break;
		thinking(philo);
	}
	return NULL;
}

// void	eating(t_philo *philo)
// {
// 	// FORK
// 	pthread_mutex_t *first;
// 	pthread_mutex_t *second;

// 	if (philo->left_fork < philo->right_fork)
// 	{
// 		first = philo->left_fork;
// 		second = philo->right_fork;
// 	}
// 	else
// 	{
// 		first = philo->right_fork;
// 		second = philo->left_fork;
// 	}
// 	pthread_mutex_lock(first);
// 	if (!game_over(philo))
// 		print_action(philo, " has taken a fork");
// 	pthread_mutex_lock(second);
// 		if (!game_over(philo))
// 	print_action(philo, " has taken a second fork");

// 	//EAT
// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	if (!game_over(philo))
// 		print_action(philo, " is eating");
// 	philo->last_meal = get_time();
// 	philo->meal_num++;
// 	pthread_mutex_unlock(&philo->data->mutex_state);
// 	ft_usleep(philo, philo->data->time_to_eat);

// 	//UNLOCK LES FORKS
// 	pthread_mutex_unlock(philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// }

void	eating(t_philo *philo) // tentative 2
{
	pthread_mutex_t *first;
	pthread_mutex_t *second;

	// Choix de l'ordre pour éviter le deadlock
	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}

	// Prendre les fourchettes
	pthread_mutex_lock(first);
	if (!game_over(philo))
		print_action(philo, "has taken a fork");

	pthread_mutex_lock(second);
	if (!game_over(philo))
		print_action(philo, "has taken a second fork");

	// Manger
	pthread_mutex_lock(&philo->data->mutex_state);
	if (!game_over(philo))
		print_action(philo, "is eating");
	philo->last_meal = get_time();
	philo->meal_num++;
	pthread_mutex_unlock(&philo->data->mutex_state);

	ft_usleep(philo, philo->data->time_to_eat);

	// Relâcher les fourchettes
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, " is sleeping");
	ft_usleep(philo, philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_action(philo, " is thinking");
}


