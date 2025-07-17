/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/17 18:06:09 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Need 'Philo - Time to die - Time to eat - Time to sleep'\n ");
		printf("(Number of time they need to eat is optional)\n ");
		return (1);
	}
	if (!is_valid_input(av))
		return (1);
	init_data(&data);
	fill_struct(&data, ac, av);
	// init fork avant les philo ? 
	init_philos(&data);
	
	// philo start eating and doing stuff :
	// creer thread
	// creer monitoring
	// join tt les threads 

	// destroy mutex et free ? 
	// free les fork, free les philo ( les 2 ou il y a malloc ) 
	// free toute la struct ? 
	
	return (0);
}
