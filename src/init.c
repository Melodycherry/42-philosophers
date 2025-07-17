/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:07:34 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/17 16:09:17 by mlaffita         ###   ########.fr       */
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
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].meal_num = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].thread = 0;
		data->philo[i].left_fork = NULL;
		data->philo[i].right_fork = NULL;
		data->philo[i].data = data;
		// gerer ce truc de fourchette pour chaque philo
		// fourchette gauche ?
		// fourchette droite ?
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
// init mutex separement ? check comment ca marche 

void	init_forks(t_data *data)
{
	(void)data;
	// faire initialisation des fourchettes 
	// check comment ca marche 
}