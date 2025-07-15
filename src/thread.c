/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:20:19 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/15 16:07:27 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create the threads and join them

// create as many threads as philosophers 
// Each philo thread will run the philo routine function

// MONITOR :
//  2 checks in it that run infinitely until a philo dies 
// or they all ate the number of meals they need to (last input argument)
// check that the time a philo needs to die didn’t surpass the last meal he had 
// and that he is not concurrently eating

// dead flag ? 
// If he indeed died we change the dead flag to 1 
// and that will break the loop in all of the threads. 
// The other check is to see if all the philos finished eating the amount of meals they need to
// and if they did we will again change the dead flag to one and break the threads loop.

