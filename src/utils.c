/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:45:03 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/29 16:31:55 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void print_action(t_philo *philo, char *msg) 
{
	pthread_mutex_lock(&philo->data->mutex_print);
	if (!philo->data->is_dead)
		printf("%ld %d %s\n", current_time(philo->data), philo->philo_id, msg);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

// faire fonction pour printer mess erreur ( sur la sortie erreur ? ) 

// faire aussi une fonction comme minishell pour erreur malloc et free tout ? 

// check ce qui sera malloc dans le projet
// faire les free en fonction 
