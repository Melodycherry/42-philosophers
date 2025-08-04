/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:09:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 18:05:03 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void) // changer en long long 
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	current_time(t_data *data) // la 
{
	if (!data || data->start_time == 0)
		return (0);
	return (get_time() - data->start_time);
}

void	ft_usleep(long time_in_ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time_in_ms)
		usleep(100);
}
