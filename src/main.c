/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/22 15:08:25 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	pthread_t monitor;
	
	if (ac < 5 || ac > 6)
	{
		printf("Need 'Philo - Time to die - Time to eat - Time to sleep'\n ");
		printf("(Number of time they need to eat is optional)\n ");
		return (1);
	}
	if (!is_valid_input(av))
		return (1);
	init_all(&data, ac, av);

	// philo start eating and doing stuff :
	data.start_time = get_time(); // deplace ici ??
	printf("Start time: %ld\n", data.start_time); // print debug 
	if (create_thread(&data) != 0)
	{
		// free data philo
		// free data forks
		return (1);
	}
	// creer monitoring
	if (pthread_create(&monitor, NULL, &monitoring, &data)!= 0)
	{
		join_threads(&data); // car thread lance precedemnent, deja en train de tourner 
		// free data philo
		// free data forks
		return (1);
	}
	pthread_join(monitor, NULL);
	join_threads(&data);

	// destroy mutex et free ? 
	// free les fork, free les philo ( les 2 ou il y a malloc ) 
	// free toute la struct ? 
	
	return (0);
}
