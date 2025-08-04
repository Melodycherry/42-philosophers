/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:05:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/08/04 18:12:09 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TESTS DE LA CORRECTION 
// 1 800 200 200 ( SHOULD DIE )
// 5 800 200 200 ( meurt PAS )
// 5 800 200 200 7 ( stop apres 7 fois chacun )
// 4 410 200 200 ( meurt PAS)
// 4 310 200 100 ( one philo die)
// test with 2 philo, death doit pas etre delay de plus de 10 ms


// leaks --atExit -- ./philo 5 400 200 200  



//#define MAX_PHILOS 200

// void	*philo_life(void *arg)
// {
// 	int id = *(int *)arg;

// 	printf("Philo %d : hello\n", id);
// 	usleep(500000); // 0.5 seconde
// 	printf("Philo %d : he's dead\n", id);

// 	return NULL;
// }

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	int i = 0;
// 	int nb_philos = atoi(av[1]);

// 	pthread_t threads[MAX_PHILOS];
// 	int ids[MAX_PHILOS];

// 	while (i < nb_philos)
// 	{
// 		ids[i] = i + 1;
// 		pthread_create(&threads[i], NULL, philo_life, &ids[i]);
// 		i++;
// 	}

// 	usleep(1000000); // attendre que tous les threads meurent
// 	printf("Fin du programme.\n");
// 	return 0;
// }

// BIG TESTING CAR PLUS RIEN FONCTIONNE 

// typedef struct s_data t_data;

// typedef struct s_philo
// {
// 	int				philo_id;
// 	int				meal_num;
// 	long			last_meal;
// 	pthread_mutex_t	*left_fork;
// 	pthread_mutex_t	*right_fork;
// 	t_data			*data;
// }	t_philo;

// typedef struct s_data
// {
// 	int				num_philo;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				is_dead;
// 	long			start_time;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	mutex_print;
// 	pthread_mutex_t	mutex_state;
// 	t_philo			*philo;
// }	t_data;

// long	get_time(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// }

// long	current_time(t_data *data)
// {
// 	return (get_time() - data->start_time);
// }

// void	print_action(t_philo *philo, char *msg)
// {
// 	pthread_mutex_lock(&philo->data->mutex_print);
// 	if (!philo->data->is_dead)
// 		printf("%ld %d %s\n", current_time(philo->data), philo->philo_id, msg);
// 	pthread_mutex_unlock(&philo->data->mutex_print);
// }

// void	ft_usleep(long time_in_ms)
// {
// 	long	start = get_time();
// 	while ((get_time() - start) < time_in_ms)
// 		usleep(100);  // 100 microseconds = 0.1ms
// }

// void	eating(t_philo *philo)
// {
// 	pthread_mutex_t *first;
// 	pthread_mutex_t *second;

// 	if (philo->philo_id % 2 == 0)
// 	{
// 		first = philo->right_fork;
// 		second = philo->left_fork;
// 	}
// 	else
// 	{
// 		first = philo->left_fork;
// 		second = philo->right_fork;
// 	}

// 	pthread_mutex_lock(first);
// 	print_action(philo, "has taken a fork");
// 	pthread_mutex_lock(second);
// 	print_action(philo, "has taken a fork");

// 	print_action(philo, "is eating");
// 	philo->last_meal = get_time();
// 	ft_usleep(philo->data->time_to_eat);

// 	pthread_mutex_unlock(first);
// 	pthread_mutex_unlock(second);
// }

// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo = (t_philo *)arg;

// 	if (philo->philo_id % 2 == 0)
// 		usleep(200);

// 	while (!philo->data->is_dead)
// 	{
// 		print_action(philo, "is thinking");
// 		eating(philo);
// 		print_action(philo, "is sleeping");
// 		ft_usleep(philo->data->time_to_sleep);
// 	}
// 	return (NULL);
// }

// Lancement dans le main()

// Assure-toi que :
//     data.start_time = get_time(); est bien juste avant les threads.
//     Tu initialises les fourchettes et philo->left_fork / right_fork bien assignés.

// 	./philo 4 800 200 200

// 	Should be :
	
// 	0 1 is thinking
// 	0 2 is thinking
// 	0 3 is thinking
// 	0 4 is thinking
// 	1 1 has taken a fork
// 	1 1 has taken a fork
// 	2 1 is eating


// element de main ( fonctionnait pour verif, toujours pas monitoring )

	// for (int i = 0; i < data.num_philo; i++)
	// 	pthread_create(&data.philo[i].thread, NULL, philo_routine, &data.philo[i]);

	// for (int i = 0; i < data.num_philo; i++)
	// 	pthread_join(data.philo[i].thread, NULL);

	// for (int i = 0; i < data.num_philo; i++)
	// 	pthread_mutex_destroy(&data.forks[i]);


// POUR ONLY ONE PHILO
// int	one_philo_case(t_data *data)
// {
// 	printf("%ld 1 has taken a fork\n", get_time() - data->start_time);
// 	usleep(data->time_to_die * 1000);
// 	printf("%ld 1 died\n", get_time() - data->start_time);
// 	free(data->forks);
// 	free(data->philo);
// 	return (1);
// }
// et dans le main() :
// 	if (data.num_philo == 1)
// 		return (one_philo_case(&data));
