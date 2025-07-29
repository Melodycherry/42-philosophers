/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:07:34 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/29 16:48:33 by mlaffita         ###   ########.fr       */
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
	pthread_mutex_init(&data->mutex_state, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
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
		i++;
	}
}

void	fill_struct(t_data *data, int ac, char **av)
{
	data->num_philo = easy_atoi(av[1]);
	data->time_to_die = easy_atoi(av[2]);
	data->time_to_eat = easy_atoi(av[3]);
	data->time_to_sleep = easy_atoi(av[4]);
	if (ac == 6)
		data->repetition = easy_atoi(av[5]);
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
	{
		printf("Malloc erreur");
		return ;// check si exit ou free ou autre
	}
}

void	init_forks(t_data *data) // tentative 2
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
			// destroy de ceux déjà créés a faire maybe
			return ;
		}
		i++;
	}
	//Attribution des fourchettes à chaque philosophe
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

void	init_all(t_data *data, int ac, char **av)
{
	init_data(data);
	fill_struct(data, ac, av);
	init_forks(data);
	init_philos(data);
}
