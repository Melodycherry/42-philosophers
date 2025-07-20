/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 22:53:46 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg; // check si ok 
	
	// protection au demarrage ? si nombre est pair
	if (philo->philo_id % 2 == 0)
		usleep(500); // attention deadlock 
		
	while (1) // while ( philo not dead ?? )
	{
		//eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	eating(t_philo *philo)
{
	// We will lock the right fork first using pthread_mutex_lock 
	// and print the message, 
	// and do the same with the left fork. 
	// Then he will eat using ft_usleep again and only then he will drop the forks by unlocking the locks
	// before that we change some variables that give our monitor indications 

	// FORK
	pthread_mutex_lock(philo->left_fork);
	printf("%ld ", current_time(philo->data));
	printf("%d has taken a fork\n", philo->philo_id);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld ", current_time(philo->data));
	printf("%d has taken another fork\n", philo->philo_id);

	//EAT
	printf("%ld ", current_time(philo->data));
	printf("%d is eating\n", philo->philo_id);
	philo->last_meal = get_time();
	philo->meal_num++;
	usleep(philo->data->time_to_die * 1000);

	//UNLOCK LES FORKS
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	printf("%ld ", current_time(philo->data));
	printf("%d ", philo->philo_id);
	printf("is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000); // car on veut en miliseconde 
}

void	thinking(t_philo *philo)
{
	printf("%ld ", current_time(philo->data));
	printf("%d ", philo->philo_id);
	printf("is thinking\n");
}
// void	*philo_routine(void *arg) // routine de test
// {
// 	t_philo *philo = (t_philo *)arg;
// 	// on doit cast a l interieur car fonction pthread est defini avec void arg
// 	// routine obligatoirement type void et void *arg
// 	printf("Philo %d pense\n", philo->philo_id);
// 	usleep(100000); // 0.1s
// 	printf("Philo %d mange\n", philo->philo_id);
// 	usleep(100000);
// 	printf("Philo %d dort\n", philo->philo_id);
// 	return (NULL);
// }

// loop that will break as soon as a philo is dead 

