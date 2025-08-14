/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:27:59 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/14 16:39:01 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*monitoring(void *arg) // fonction initiale 
// {
// 	t_data	*data;

// 	data = (t_data *)arg;
// 	while (1)
// 	{
// 		if (check_philo_death(data))
// 			return (NULL);
// 		if (all_philos_ate_enough(data))
// 		{
// 			pthread_mutex_lock(&data->mutex_state);
// 			data->is_dead = 1;
// 			pthread_mutex_unlock(&data->mutex_state);
// 			return (NULL);
// 		}
// 		usleep(500);
// 	}
// }

// int	all_philos_ate_enough(t_data *data)
// {
// 	int	i;

// 	if (data->repetition <= 0)
// 		return (0);
// 	i = 0;
// 	while (i < data->num_philo)
// 	{
// 		pthread_mutex_lock(&data->mutex_state);
// 		if (data->philo[i].meal_num < data->repetition)
// 		{
// 			pthread_mutex_unlock(&data->mutex_state);
// 			return (0);
// 		}
// 		pthread_mutex_unlock(&data->mutex_state);
// 		i++;
// 	}
// 	return (1);
// }

// int	philo_should_die(t_philo *philo, t_data *data)
// {
// 	long long	now;
// 	long long	last_meal;

// 	if (data->repetition > 0 && philo->meal_num >= data->repetition)
// 		return (0);
// 	now = get_time();
// 	last_meal = philo->last_meal;
// 	if ((now - last_meal) > data->time_to_die)
// 		return (1);
// 	return (0);
// }

// int	check_philo_death(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_philo)
// 	{
// 		pthread_mutex_lock(&data->mutex_state);
// 		if (philo_should_die(&data->philo[i], data))
// 		{
// 			print_action(&data->philo[i], "died");
// 			data->is_dead = 1;
// 			pthread_mutex_unlock(&data->mutex_state);
// 			return (1);
// 		}
// 		pthread_mutex_unlock(&data->mutex_state);
// 		i++;
// 	}
// 	return (0);
// }


static int everyone_full(t_data *d)
{
    int i;

    if (d->repetition <= 0) return 0;
    i = 0;
    while (i < d->num_philo)
    {
        if (get_meal_num(&d->philo[i]) < d->repetition)
            return 0;
        i++;
    }
    return 1;
}

void *monitoring(void *arg)
{
    t_data *d = (t_data *)arg;
    int i;

    while (1)
    {
        // 1) arrêt si tous ont fini
        if (everyone_full(d))
        {
            pthread_mutex_lock(&d->mutex_state);
            d->are_full = 1;
            pthread_mutex_unlock(&d->mutex_state);
            return NULL;
        }

        // 2) détection de mort
        i = 0;
        while (i < d->num_philo)
        {
            long long last = get_last_meal(&d->philo[i]);
            long long diff = get_time() - last;

            if (diff > d->time_to_die)
            {
                // set flag AVANT d’imprimer pour bloquer le spam
                pthread_mutex_lock(&d->mutex_state);
                if (!d->is_dead) d->is_dead = 1;
                pthread_mutex_unlock(&d->mutex_state);

                pthread_mutex_lock(&d->mutex_print);
                printf("%lld %d %s\n", current_time(d), d->philo[i].philo_id, "died");
                pthread_mutex_unlock(&d->mutex_print);
                return NULL;
            }
            i++;
        }
        usleep(500); // micro-pause pour ne pas burner le CPU
    }
}
