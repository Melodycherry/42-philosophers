/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:45:03 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 18:04:45 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	if (!philo->data->is_dead)
		printf("%ld %d %s\n", current_time(philo->data), philo->philo_id, msg);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

int	one_philo_case(t_data *data)
{
	printf("0 1 take a fork\n");
	printf("%d 1 died\n", data->time_to_die);
	free(data->forks);
	free(data->philo);
	return (1);
}

void	destroy_and_free(t_data *data)
{
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_state);
	free(data->forks);
	free(data->philo);
}
