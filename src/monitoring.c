/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:27:59 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/17 16:10:39 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->end)
	{
		if (check_philo_death(data))
			return (NULL);
		if (all_philos_ate_enough(data))
		{
			pthread_mutex_lock(&data->mutex_state);
			data->end = TRUE;
			pthread_mutex_unlock(&data->mutex_state);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	all_philos_ate_enough(t_data *data)
{
	int	i;
	int full_count;
	t_philo	*philo;

	if (data->repetition <= 0)
		return (0);
	i = 0;
	full_count = 0;
	while (i < data->num_philo)
	{
		philo = &data->philo[i];
		pthread_mutex_lock(&data->mutex_state);
		if (philo->full)
			full_count++;
		pthread_mutex_unlock(&data->mutex_state);
		i++;
	}
	if (full_count == data->num_philo)
		return (1);
	return (0);
}

int	check_philo_death(t_data *data)
{
	int	i;
	long	now;
	t_philo	*philo;

	i = 0;
	while (i < data->num_philo)
	{
		philo = &data->philo[i];
		pthread_mutex_lock(&data->mutex_state);
		now = get_time();
		if (now - philo->last_meal > data->time_to_die)
		{
			print_action(&data->philo[i], "died");
			data->end = TRUE;
			pthread_mutex_unlock(&data->mutex_state);
			return (1);
		}
		pthread_mutex_unlock(&data->mutex_state);
		i++;
	}
	return (0);
}