/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:32:38 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 17:36:49 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all(t_data *data, int ac, char **av)
{
	init_data(data);
	fill_struct(data, ac, av);
	init_forks(data);
	init_philos(data);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;

	if (!first_check(ac, av))
		return (1);
	init_all(&data, ac, av);
	data.start_time = get_time();
	if (data.num_philo == 1)
		return (one_philo_case(&data));
	if (create_thread(&data) != 0)
		return (destroy_and_free(&data), 1);
	if (pthread_create(&monitor, NULL, monitoring, &data) != 0)
	{
		join_threads(&data);
		destroy_and_free(&data);
		return (1);
	}
	pthread_join(monitor, NULL);
	join_threads(&data);
	destroy_and_free(&data);
	return (0);
}
