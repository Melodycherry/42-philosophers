/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:45:03 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/24 12:16:36 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	int	end;

	pthread_mutex_lock(&philo->data->mutex_print);
	pthread_mutex_lock(&philo->data->mutex_state);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->mutex_state);
	if (!end)
		printf("%lld %d %s\n", current_time(philo->data), philo->philo_id, msg);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

int	one_philo_case(t_data *data)
{
	printf("0 1 take a fork\n");
	ft_usleep(data->time_to_die);
	printf("%lld 1 died\n", data->time_to_die);
	return (1);
}

int	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_state);
	free(data->forks);
	free(data->philo);
	return (1);
}

long long	easy_atol(const char *str)
{
	int			i;
	long long	result;
	int			signe;

	i = 0;
	signe = 1;
	result = 0;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signe * result);
}
