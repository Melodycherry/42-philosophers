/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:33:35 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:06 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "struct.h"

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

// FONCTIONS
// Parsing
t_bool	is_valid_int(char *str);
t_bool 	is_valid_input(char **av);
int		easy_atoi(const char *str);

#endif 