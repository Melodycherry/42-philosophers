/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:09:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/20 22:46:11 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checker les fonctions pour le temps
// modif de la structure avec le temps de depart de chaque actions ? 


long	get_time(void)
{
	struct timeval	tv; // tv.sec = secondes / tv.usec = microseconde

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // converti tt en miliseconde 
}

long	current_time(t_data *data)
{
	return (get_time() - data->start_time); // pour le temps ecoule depuis le debut du program 
}

// printf : 
// current_time(philo->data) 
// ensuite philo ID
// and next le mess 

// faire la fonction ft_usleep ? Car plus precis ?? 
