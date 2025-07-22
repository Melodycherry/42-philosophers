/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:20:19 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/22 13:02:39 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Create a thread object
 * create as many threads as philosophers 
 * Each philo thread will run the philo routine function
 * @param data 
 * @return int 
 */
int	create_thread(t_data *data)
{
	int i;

	i = 0;
	while ( i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, philo_routine, &data->philo[i]) != 0)
		{
			printf("erreur creation thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}
/**
 * @brief  2 checks that run infinitely until a philo dies
 * or they all ate the number of meals they need to (last input argument)
 * check that the time a philo needs to die didn’t surpass the last meal he had 
 * and that he is not concurrently eating
 * @param arg 
 * @return void* 
 */
void	*monitoring(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;
	int full_count;
	long now;

	while (1)
	{
		i = 0;
		full_count = 0;
		while (i < data->num_philo) // verif de la mort
		{
			now = get_time();
			if ((now - data->philo[i].last_meal) > data->time_to_die)
			{
				pthread_mutex_lock(&data->mutex_state); // protection pour eviter race condition 
				data->is_dead = 1;
				pthread_mutex_unlock(&data->mutex_state);
				print_action(&data->philo[i], " died");
				return (NULL);
			}
			if (data->repetition > 0 && data->philo[i].meal_num >= data->repetition)
				full_count++;
			i++;
		}
		if (data->repetition > 0 && full_count == data->num_philo) // si tout le monde a mange le nombre de repet
		{
			pthread_mutex_lock(&data->mutex_state);
			data->are_full = 1; // flag
			pthread_mutex_unlock(&data->mutex_state);
			return (NULL);
		}
		usleep(1000); // micro sommeil pour la surveillance
	}
}

int	game_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->data->mutex_state);
	end = (philo->data->is_dead || philo->data->are_full);
	pthread_mutex_unlock(&philo->data->mutex_state);
	return (end);
}