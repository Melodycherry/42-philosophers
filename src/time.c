/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:09:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/13 17:38:00 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000LL) + ((long long)tv.tv_usec / 1000LL));
}

long long	current_time(t_data *data)
{
	// if (!data || data->start_time == 0) // check si ca change qqchose de laisser 
	// 	return (0);
	return (get_time() - data->start_time);
}

// void	ft_usleep(long time_in_ms) // ma version initiale
// {
// 	long	start;

// 	start = get_time();
// 	while ((get_time() - start) < time_in_ms)
// 		usleep(100);
// }

void    ft_usleep(t_philo *philo, long long duration_ms) // check version chatty pour problem linux
{
    long long target = get_time() + duration_ms;
    while (!game_over(philo))
    {
        long long now = get_time();
        if (now >= target)
            break;
        // dormir par petites tranches pour limiter la dérive du scheduler
        if (target - now > 2)          // il reste > 2ms
            usleep(200);               // 0.2 ms (valeur sûre sur Linux)
        else
            usleep(50);                // finition très fine
    }
}
