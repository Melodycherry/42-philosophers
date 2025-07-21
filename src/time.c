/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:09:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/21 16:26:28 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Get the time object
 * tv.sec = secondes
 * tv.usec = microseconde
 * @return long 
 */
long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	current_time(t_data *data)
{
	return (get_time() - data->start_time);
}

void	ft_usleep(t_philo *philo, long duration)
{
	long start;
	
	start = get_time();
	while(!game_over(philo))
	{
		if(get_time() - start >= duration)
			break;
		usleep(100);
	}
}
