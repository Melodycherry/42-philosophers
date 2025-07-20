/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 17:50:01 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*philo_routine(void *arg)
// {
// 	// protection au demarrage ? si nombre est pair
// 	while (1) // while ( philo not dead ?? )
// 	{
// 		// 		eat()
// 		//		sleep()
// 		//		think()
// 	}
// }
void	*philo_routine(void *arg) // routine de test
{
	t_philo *philo = (t_philo *)arg;
	// on doit cast a l interieur car fonction pthread est defini avec void arg
	// routine obligatoirement type void et void *arg
	printf("Philo %d pense\n", philo->philo_id);
	usleep(100000); // 0.1s
	printf("Philo %d mange\n", philo->philo_id);
	usleep(100000);
	printf("Philo %d dort\n", philo->philo_id);
	return (NULL);
}

// ---------------------------------------------------------------------------------------------------
// eat()
// We will lock the right fork first using pthread_mutex_lock 
// and print the message, 
// and do the same with the left fork. 
// Then he will eat using ft_usleep again and only then he will drop the forks by unlocking the locks
// before that we change some variables that give our monitor indications 


// sleep() 
// make them sleep the length of the input inserted by the user using our ft_usleep
// print the message “X is sleeping”

// think()
// print a message “X is thinking” (X is the philo number)


// loop that will break as soon as a philo is dead 

// ---------------------------------------------------------------------------------------------------

// - la routine detaillee :
// fork left
// fork right
// print "take forks"
// faire avec timestamp pour le last meal time ( a mettre dans la struc )
// time to eat ( avec usleep)
// unlock left
// unlock right
// time to sleep ( usleep again )
// print "thinkin"

// ---------------------------------------------------------------------------------------------------

// void eat(philo)
// mutex left fork
// print take left fork
// mutex right fork
// print right fork
// print is eating 
// recup temps de last meal
// incrementation de meal taken pour le dernier arg 
// usleep time to eat
// unlock fork left
// unlock fork right

// void slee(philo)
// print is sleeping
// usleep time to sleep

// void think(philo)
// print is thinking 

// ---------------------------------------------------------------------------------------------------

// MONITOR 
// va verif si un philo est mort 
// = n 'a pas mange depuis plus que time to die 
// 
// verif si nombre de meal max atteint ( repetition)
