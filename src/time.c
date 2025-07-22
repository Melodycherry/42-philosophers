/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:09:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/22 15:10:22 by mlaffita         ###   ########.fr       */
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
	//printf("get_time() called, returns: %ld\n", tv_sec * 1000 + tv_usec / 1000); // printf debug
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	current_time(t_data *data)
{
	if (!data || data->start_time == 0)
		return (0);
	return (get_time() - data->start_time);
}

// void	ft_usleep(t_philo *philo, long duration)
// {
// 	long start;
	
// 	start = get_time();
// 	while(!game_over(philo))
// 	{
// 		if(get_time() - start >= duration)
// 			break;
// 		usleep(100);
// 	}
// }

void	ft_usleep(t_philo *philo, long duration) // tentative 2
{
	(void)philo;
	usleep(duration * 1000); // 100 ms -> 100000 µs
}
