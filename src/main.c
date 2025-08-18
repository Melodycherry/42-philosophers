/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/18 14:28:43 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor_thread;

	if (!first_check(ac, av))
		return (1);
	init_all(&data, ac, av);
	create_thread(&data, &monitor_thread);
	join_threads(&data);
	if (data.num_philo > 1)
		pthread_join(monitor_thread, NULL);
	destroy_and_free(&data);
	return (0);
}
