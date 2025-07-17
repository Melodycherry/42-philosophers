/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/17 13:50:13 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo	philo;
	
	if (ac < 5 || ac > 6)
	{
		printf("Need 'Philo - Time to die - Time to eat - Time to sleep'\n ");
		printf("(Number of time they need to eat is optional)\n ");
		return (1);
	}
	if (!is_valid_input(av))
		return(1);
	init_all(&philo);
	fill_struct(&philo, ac, av);
	
	// philo start eating and doing stuff 

	// destroy mutex et free ? 

	return (0);
}
