/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:21:21 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/06 17:21:57 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
	{
		printf("Erreur malloc forks\n");
		return ;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Erreur init mutex fork %d\n", i);
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return ;
		}
		i++;
	}
	take_forks(data);
}

void	take_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (i % 2 == 0)
		{
			data->philo[i].left_fork = &data->forks[i];
			data->philo[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		}
		else
		{
			data->philo[i].left_fork = &data->forks[(i + 1) % data->num_philo];
			data->philo[i].right_fork = &data->forks[i];
		}
		i++;
	}
}
