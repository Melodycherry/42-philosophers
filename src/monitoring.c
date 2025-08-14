/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:27:59 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/14 16:59:46 by mlaffita         ###   ########.fr       */
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
		usleep(1000);
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

int	philo_should_die(t_philo *philo, t_data *data)
{
	long long	now;
	long long	last_meal;

	if (data->repetition > 0 && philo->meal_num >= data->repetition)
		return (0);
	now = get_time();
	last_meal = philo->last_meal;
	if ((now - last_meal) > data->time_to_die)
		return (1);
	return (0);
}

int	check_philo_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->mutex_state);
		if (philo_should_die(&data->philo[i], data))
		{
			print_action(&data->philo[i], "died");
			data->is_dead = 1;
			pthread_mutex_unlock(&data->mutex_state);
			return (1);
		}
		pthread_mutex_unlock(&data->mutex_state);
		i++;
	}
	return (0);
}
