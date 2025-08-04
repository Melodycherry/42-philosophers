/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:20:19 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 15:14:32 by mlaffita         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				philo_routine, &data->philo[i]) != 0)
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
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}
void	*monitoring(void *arg) // tentative simple avec just la mort des philo 
{
    t_data *data = (t_data *)arg;
    int i;
    long now;
    long last_meal;

    while (1)
    {
        i = 0;
        while (i < data->num_philo)
        {
            pthread_mutex_lock(&data->mutex_state);
            last_meal = data->philo[i].last_meal;
            pthread_mutex_unlock(&data->mutex_state);

            now = get_time();
            if ((now - last_meal) > data->time_to_die)
            {
                print_action(&data->philo[i], "died");
                pthread_mutex_lock(&data->mutex_state);
                data->is_dead = 1;
                pthread_mutex_unlock(&data->mutex_state);
                return NULL;
            }
            i++;
        }
        usleep(500);
    }
}