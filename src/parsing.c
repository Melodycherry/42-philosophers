/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:53:55 by mlaffita          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:56 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// valid input ( avec tt dedans ) faire un bool ? 
// - only digit
// - bigger than zero pour av 1 - 2 - 3 - 4
// - 0 ou plus pour av 5 ( optional) 
// - av 2 <= 200 ( max limit de philo ) 

t_bool	is_valid_int(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-') // juste pour le atoi et les mess erreurs plus precis
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return FALSE;
		i++;
	}
	return TRUE;
}

t_bool is_valid_input(char **av)
{
	int i;

	i = 1;
	if ((easy_atoi(av[1])) > 200) // pour les philo
	{
		printf("MAX number of philo is 200\n");
		return FALSE;
	}
	while (av[i])
	{
		if (is_valid_int(av[i]) == FALSE)
		{
			printf("Must be a number\n");
			return FALSE;
		}
		if ( i == 5) // seulement pour le nombre de meal
		{
			if (easy_atoi(av[i]) < 0)
			{
				printf("Number of meal nust be 0 or more\n");
				return FALSE;
			}
		}
		else // tt le reste doit etre positif 
		{
			if (easy_atoi(av[i]) <= 0)
			{
				printf("Number must be positive\n");
				return FALSE;
			}
		}
		i++;
	}
	return TRUE;	
}

int	easy_atoi(const char *str)
{
	int	i;
	int	result;
	int signe;

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
