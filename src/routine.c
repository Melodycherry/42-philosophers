/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:19:28 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/14 16:39:45 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*philo_routine(void *arg) // routine initiale
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	if (philo->philo_id % 2 == 0)
// 		usleep(1000);
// 	while (!philo->data->is_dead)
// 	{
// 		eating(philo);
// 		if (philo->data->repetition > 0
// 			&& philo->meal_num >= philo->data->repetition)
// 			break ;
// 		sleeping(philo);
// 		thinking(philo);
// 	}
// 	return (NULL);
// }

void *philo_routine(void *arg)
{
    t_philo *p = (t_philo *)arg;

    // petit décalage pour réduire la contention au départ
    if (p->philo_id % 2 == 0)
        usleep(500); // 0.5ms

    while (!game_over(p))
    {
        print_action(p, "is thinking");
        eating(p);
        if (game_over(p)) break;

        print_action(p, "is sleeping");
        ft_usleep(p, p->data->time_to_sleep);
    }
    return NULL;
}


// void	eating(t_philo *philo) // fonction initiale 
// {
// 	pthread_mutex_t	*first;
// 	pthread_mutex_t	*second;

// 	odd_or_even_philo(philo, &first, &second);
// 	pthread_mutex_lock(first);
// 	print_action(philo, "has taken a fork");
// 	pthread_mutex_lock(second);
// 	print_action(philo, "has taken another fork");
// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	philo->last_meal = get_time();
// 	pthread_mutex_unlock(&philo->data->mutex_state);
// 	print_action(philo, "is eating 🍝");
// 	ft_usleep(philo, philo->data->time_to_eat);
// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	philo->meal_num++;
// 	pthread_mutex_unlock(&philo->data->mutex_state);
// 	pthread_mutex_unlock(first);
// 	pthread_mutex_unlock(second);
// }

// void	odd_or_even_philo(t_philo *philo,
// 			pthread_mutex_t **first, pthread_mutex_t **second)
// {
// 	if (philo->philo_id % 2 == 0)
// 	{
// 		*first = philo->right_fork;
// 		*second = philo->left_fork;
// 	}
// 	else
// 	{
// 		*first = philo->left_fork;
// 		*second = philo->right_fork;
// 	}
// }

// choix d’un ordre total via l’adresse des mutex
static void pick_forks_order(t_philo *p, pthread_mutex_t **first, pthread_mutex_t **second)
{
    if (p->left_fork < p->right_fork) { *first = p->left_fork; *second = p->right_fork; }
    else                              { *first = p->right_fork; *second = p->left_fork; }
}

void eating(t_philo *p)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    pick_forks_order(p, &first, &second);

    pthread_mutex_lock(first);
    print_action(p, "has taken a fork");
    if (game_over(p)) { pthread_mutex_unlock(first); return; }

    pthread_mutex_lock(second);
    print_action(p, "has taken another fork");
    if (game_over(p)) { pthread_mutex_unlock(second); pthread_mutex_unlock(first); return; }

    set_last_meal(p, get_time());
    print_action(p, "is eating");
    ft_usleep(p, p->data->time_to_eat);

    increse_meal_num(p);

    pthread_mutex_unlock(second);
    pthread_mutex_unlock(first);
}


void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo, philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}
