/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:07:34 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/13 17:28:09 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data )
{
	data->num_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->repetition = 0;
	data->philo = NULL;
	data->is_dead = 0;
	data->are_full = 0;
	data->forks = NULL;
	pthread_mutex_init(&data->mutex_state, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
}

int	fill_struct(t_data *data, int ac, char **av)
{
	data->num_philo = easy_atol(av[1]);
	data->time_to_die = easy_atol(av[2]);
	data->time_to_eat = easy_atol(av[3]);
	data->time_to_sleep = easy_atol(av[4]);
	if (ac == 6)
		data->repetition = easy_atol(av[5]);
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (printf("Malloc error"), 1);
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].meal_num = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].thread = 0;
		data->philo[i].data = data;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		i++;
	}
}

void	init_all(t_data *data, int ac, char **av)
{
	init_data(data);
	fill_struct(data, ac, av);
	init_forks(data);
	init_philos(data);
}
