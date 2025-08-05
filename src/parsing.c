/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:53:55 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/05 16:33:24 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_valid_input(char **av)
{
	int	i;

	i = 1;
	if ((easy_atol(av[1])) > 200)
		return (printf("MAX number of philo is 200\n"), FALSE);
	while (av[i])
	{
		if (is_valid_int(av[i]) == FALSE)
			return (printf("Must be a number\n"), FALSE);
		if (i == 5)
		{
			if (easy_atol(av[i]) < 0)
				return (printf("Number of meal must be 0 or more\n"), FALSE);
		}
		else
		{
			if (easy_atol(av[i]) <= 0)
				return (printf("Number must be positive\n"), FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	first_check(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Need 'Philo - Time to die - Time to eat - Time to sleep'\n");
		printf("(Number of times they need to eat is optional)\n");
		return (0);
	}
	if (!is_valid_input(av))
		return (0);
	return (1);
}
