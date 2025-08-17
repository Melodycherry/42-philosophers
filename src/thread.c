/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:20:19 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/17 16:11:47 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_thread(t_data *data)
{
	int i ;
	pthread_t	monitor_thread;
	t_philo *philo;
	
	data->start_time = get_time();
	if ( data->num_philo == 1)
	{
		one_philo_case(data);
		return (1);
	}
	i = 0;
	while ( i < data->num_philo)
	{
		philo = &data->philo[i];
		philo->last_meal = data->start_time;
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo) != 0)
		return (0);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &monitoring, data) != 0)
	return (0);
	pthread_detach(monitor_thread);
	return (1);
}

int	join_threads(t_data *data)
{
	int	i;

	if ( data->num_philo == 1)
		return (0);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
