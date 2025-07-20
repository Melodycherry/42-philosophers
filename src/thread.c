/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:20:19 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 22:06:42 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create the threads and join them
// create as many threads as philosophers 
// Each philo thread will run the philo routine function

int	create_thread(t_data *data)
{
	int i;

	i = 0;
	while ( i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, philo_routine, &data->philo[i]) != 0)
		{
			printf("erreur creation thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}
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

// ---------------------------------------------------------------------------------------------------

// MONITOR 
// va verif si un philo est mort 
// = n 'a pas mange depuis plus que time to die 
// 
// verif si nombre de meal max atteint ( repetition)