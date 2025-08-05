/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:27:59 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/05 16:41:11 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_philo_death(data))
			return (NULL);
		if (all_philos_ate_enough(data))
		{
			pthread_mutex_lock(&data->mutex_state);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->mutex_state);
			return (NULL);
		}
		usleep(500);
	}
}

int	all_philos_ate_enough(t_data *data)
{
	int	i;

	if (data->repetition <= 0)
		return (0);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->mutex_state);
		if (data->philo[i].meal_num < data->repetition)
		{
			pthread_mutex_unlock(&data->mutex_state);
			return (0);
		}
		pthread_mutex_unlock(&data->mutex_state);
		i++;
	}
	return (1);
}

int	check_philo_death(t_data *data)
{
	int			i;
	long long	last_meal;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->mutex_state);
		if (data->repetition > 0
			&& data->philo[i].meal_num >= data->repetition)
		{
			pthread_mutex_unlock(&data->mutex_state);
			i++;
			continue ;
		}
		last_meal = data->philo[i].last_meal;
		pthread_mutex_unlock(&data->mutex_state);
		if ((get_time() - last_meal) > data->time_to_die)
		{
			print_action(&data->philo[i], "died");
			pthread_mutex_lock(&data->mutex_state);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->mutex_state);
			return (1);
		}
		i++;
	}
	return (0);
}
