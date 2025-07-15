/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/15 16:07:23 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

// DONC while (1) ou while ( philo not dead ?? )
// { 
// 		eat()
//		sleep()
//		think()
// }