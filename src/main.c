/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 15:36:09 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av) 
{
	t_data data;
	pthread_t monitor;
	
	// verif 
	if (ac < 5 || ac > 6)
	{
		printf("Need 'Philo - Time to die - Time to eat - Time to sleep'\n ");
		printf("(Number of time they need to eat is optional)\n ");
		return (1);
	}
	if (!is_valid_input(av))
		return (1);
		
	// init 
	init_all(&data, ac, av);
	data.start_time = get_time();

	// si juste 1 philo ( faire fonction separee plus tard maybe )
	if (data.num_philo == 1)
	{
		printf("%ld 1 died\n", get_time() - data.start_time);
		free(data.forks);
		free(data.philo);
		return (0);
	}
	
	// philo start eating and doing stuff :
	if (create_thread(&data) != 0)
	{
		free(data.forks);
		free(data.philo);
		return (1);
	}
	
	// creer monitoring
	if (pthread_create(&monitor, NULL, monitoring, &data)!= 0)
	{
		join_threads(&data); // car thread lance precedemnent, deja en train de tourner 
		free(data.forks);
		free(data.philo);
		return (1);
	}
	pthread_join(monitor, NULL);
	join_threads(&data);

	// destroy and free 
	pthread_mutex_destroy(&data.mutex_print);
	free(data.forks);
	free(data.philo);
	return (0);
}
