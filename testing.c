/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:05:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/16 15:45:55 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//#define MAX_PHILOS 200

// void	*philo_life(void *arg)
// {
// 	int id = *(int *)arg;

// 	printf("Philo %d : hello\n", id);
// 	usleep(500000); // 0.5 seconde
// 	printf("Philo %d : he's dead\n", id);

// 	return NULL;
// }

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	int i = 0;
// 	int nb_philos = atoi(av[1]);

// 	pthread_t threads[MAX_PHILOS];
// 	int ids[MAX_PHILOS];

// 	while (i < nb_philos)
// 	{
// 		ids[i] = i + 1;
// 		pthread_create(&threads[i], NULL, philo_life, &ids[i]);
// 		i++;
// 	}

// 	usleep(1000000); // attendre que tous les threads meurent
// 	printf("Fin du programme.\n");
// 	return 0;
// }
