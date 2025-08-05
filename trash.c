
// void	init_forks(t_data *data)
// {
// 	int i;

// 	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
// 	if (!data->forks)
// 	{
// 		printf("erreur malloc forks\n");
// 		return ;
// 	}
// 	i = 0;
// 	while ( i < data->num_philo) // init les mutex 
// 	{
// 		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
// 		{
// 			printf("erreur init mutex\n");
// 			// faire destroy de ce qui a deja ete creer ? 
// 			return  ;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->num_philo) // pour assigner les forks aux philo
// 	{
// 		// data->philo[i].left_fork = &data->forks[i];
// 		// data->philo[i].right_fork = &data->forks[(i + 1) % data->num_philo];
// 		// i++;
// 		if (i % 2 == 0)
// 		{
// 			data->philo[i].left_fork = &data->forks[i];
// 			data->philo[i].right_fork = &data->forks[(i + 1) % data->num_philo];
// 		}
// 		else
// 		{
// 			data->philo[i].left_fork = &data->forks[(i + 1) % data->num_philo];
// 			data->philo[i].right_fork = &data->forks[i];
// 		}
// 		i++;
// 	}
// }

// void	print_action(t_philo *philo, char *msg)
// {
// 	pthread_mutex_lock(&philo->data->mutex_print);
// 	printf("%ld %d %s\n", current_time(philo->data), philo->philo_id, msg);
// 	pthread_mutex_unlock(&philo->data->mutex_print);

// }

// void	print_action(t_philo *philo, char *msg) // tentative 2
// {
// 	long ts = current_time(philo->data);

// 	pthread_mutex_lock(&philo->data->mutex_print);
// 	if (!game_over(philo))
// 		printf("%ld %d %s\n", ts, philo->philo_id, msg);
// 	pthread_mutex_unlock(&philo->data->mutex_print);
// }

// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo = (t_philo *)arg; // check si ok 
	
// 	//printf("Philo %d started\n", philo->philo_id); // debug 
// 	if (philo->philo_id % 2 == 0)
// 		ft_usleep(philo, 10); // attention deadlock
// 		//ft_usleep(philo, philo->data->time_to_eat / 2);
// 	while (!game_over(philo))
// 	{
// 		if (philo->data->repetition > 0 && philo->meal_num >= philo->data->repetition) // si un philo a deja assez mange il sort 
// 			break;
// 		eating(philo);
// 		// if (game_over(philo)) // check car ca affiche de la merde 
// 		// 	break;
// 		sleeping(philo);
// 		// if (game_over(philo)) // donc a enlever si le pb est regle avec le mutex de printf
// 		// 	break;
// 		thinking(philo);
// 	}
// 	return NULL;
// }


// void	eating(t_philo *philo)
// {
// 	// FORK
// 	pthread_mutex_t *first;
// 	pthread_mutex_t *second;

// 	if (philo->left_fork < philo->right_fork)
// 	{
// 		first = philo->left_fork;
// 		second = philo->right_fork;
// 	}
// 	else
// 	{
// 		first = philo->right_fork;
// 		second = philo->left_fork;
// 	}
// 	pthread_mutex_lock(first);
// 	if (!game_over(philo))
// 		print_action(philo, " has taken a fork");
// 	pthread_mutex_lock(second);
// 		if (!game_over(philo))
// 	print_action(philo, " has taken a second fork");

// 	//EAT
// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	if (!game_over(philo))
// 		print_action(philo, " is eating");
// 	philo->last_meal = get_time();
// 	philo->meal_num++;
// 	pthread_mutex_unlock(&philo->data->mutex_state);
// 	ft_usleep(philo, philo->data->time_to_eat);

// 	//UNLOCK LES FORKS
// 	pthread_mutex_unlock(philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// }

// void	eating(t_philo *philo) // tentative 2
// {
// 	pthread_mutex_t *first;
// 	pthread_mutex_t *second;

// 	// Choix de l'ordre pour éviter le deadlock
// 	if (philo->left_fork < philo->right_fork)
// 	{
// 		first = philo->left_fork;
// 		second = philo->right_fork;
// 	}
// 	else
// 	{
// 		first = philo->right_fork;
// 		second = philo->left_fork;
// 	}

// 	// Prendre les fourchettes
// 	pthread_mutex_lock(first);
// 	if (!game_over(philo))
// 		print_action(philo, "has taken a fork");

// 	pthread_mutex_lock(second);
// 	if (!game_over(philo))
// 		print_action(philo, "has taken a second fork");

// 	// Manger
// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	if (!game_over(philo))
// 		print_action(philo, "is eating");
// 	philo->last_meal = get_time();
// 	philo->meal_num++;
// 	pthread_mutex_unlock(&philo->data->mutex_state);

// 	ft_usleep(philo, philo->data->time_to_eat);

// 	// Relâcher les fourchettes
// 	pthread_mutex_unlock(first);
// 	pthread_mutex_unlock(second);
// }

// void	ft_usleep(t_philo *philo, long duration)
// {
// 	long start;
	
// 	start = get_time();
// 	while(!game_over(philo))
// 	{
// 		if(get_time() - start >= duration)
// 			break;
// 		usleep(100);
// 	}
// }

// void	ft_usleep(t_philo *philo, long duration) // tentative 2
// {
// 	(void)philo;
// 	usleep(duration * 1000); // 100 ms -> 100000 µs
// }

/**
 * @brief  2 checks that run infinitely until a philo dies
 * or they all ate the number of meals they need to (last input argument)
 * check that the time a philo needs to die didn’t surpass the last meal he had 
 * and that he is not concurrently eating
 * @param arg 
 * @return void* 
 */
// void	*monitoring(void *arg)
// {
// 	t_data *data = (t_data *)arg;
// 	int i;
// 	int full_count;
// 	long now;

// 	while (1)
// 	{
// 		i = 0;
// 		full_count = 0;
// 		while (i < data->num_philo) // verif de la mort
// 		{
// 			now = get_time();
// 			if ((now - data->philo[i].last_meal) > data->time_to_die)
// 			{
// 				pthread_mutex_lock(&data->mutex_state); // protection pour eviter race condition 
// 				data->is_dead = 1;
// 				pthread_mutex_unlock(&data->mutex_state);
// 				print_action(&data->philo[i], " died");
// 				return (NULL);
// 			}
// 			if (data->repetition > 0 && data->philo[i].meal_num >= data->repetition)
// 				full_count++;
// 			i++;
// 		}
// 		if (data->repetition > 0 && full_count == data->num_philo) // si tout le monde a mange le nombre de repet
// 		{
// 			pthread_mutex_lock(&data->mutex_state);
// 			data->are_full = 1; // flag
// 			pthread_mutex_unlock(&data->mutex_state);
// 			return (NULL);
// 		}
// 		usleep(1000); // micro sommeil pour la surveillance
// 	}
// }

// void	*monitoring(void *arg) // tentative 2
// {
// 	t_data *data = (t_data *)arg;
// 	int i;
// 	int full_count;
// 	long now;
// 	long last_meal;

// 	while (1)
// 	{
// 		i = 0;
// 		full_count = 0;
// 		while (i < data->num_philo)
// 		{
// 			pthread_mutex_lock(&data->mutex_state);
// 			last_meal = data->philo[i].last_meal;
// 			pthread_mutex_unlock(&data->mutex_state);

// 			now = get_time();
// 			if ((now - last_meal) > data->time_to_die)
// 			{
// 				pthread_mutex_lock(&data->mutex_state);
// 				data->is_dead = 1;
// 				pthread_mutex_unlock(&data->mutex_state);
// 				print_action(&data->philo[i], " died");
// 				return (NULL);
// 			}

// 			pthread_mutex_lock(&data->mutex_state);
// 			if (data->repetition > 0 && data->philo[i].meal_num >= data->repetition)
// 				full_count++;
// 			pthread_mutex_unlock(&data->mutex_state);

// 			i++;
// 		}
// 		if (data->repetition > 0 && full_count == data->num_philo)
// 		{
// 			pthread_mutex_lock(&data->mutex_state);
// 			data->are_full = 1;
// 			pthread_mutex_unlock(&data->mutex_state);
// 			return (NULL);
// 		}
// 		usleep(1000);
// 	}
// }

// int	game_over(t_philo *philo)
// {
// 	int	end;

// 	pthread_mutex_lock(&philo->data->mutex_state);
// 	end = (philo->data->is_dead || philo->data->are_full);
// 	pthread_mutex_unlock(&philo->data->mutex_state);
// 	return (end);
// }

// ROUTINE V2 AVEC TOUS LES MUTEX DE LA TERRE
// a mettre seulement si ca marche pas 
// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo = (t_philo *)arg;

// 	if (philo->philo_id % 2 == 0)
// 		usleep(1000); // Petit décalage pour éviter conflits

// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->data->mutex_state);
// 		if (philo->data->is_dead)
// 		{
// 			pthread_mutex_unlock(&philo->data->mutex_state);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&philo->data->mutex_state);

// 		eating(philo);

// 		pthread_mutex_lock(&philo->data->mutex_state);
// 		if (philo->data->repetition > 0
// 			&& philo->meal_num >= philo->data->repetition)
// 		{
// 			pthread_mutex_unlock(&philo->data->mutex_state);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&philo->data->mutex_state);

// 		sleeping(philo);
// 		thinking(philo);
// 	}
// 	return (NULL);
// }

// void	*monitoring(void *arg) // ok fonctionne mais utilise version refacto 
// en 3 fonction avec plus de securite 
// {
// 	t_data		*data;
// 	int			i;
// 	int			full_count;
// 	long long	last_meal;

// 	data = (t_data *)arg;
// 	while (1)
// 	{
// 		i = 0;
// 		full_count = 0;
// 		while (i < data->num_philo)
// 		{
// 			pthread_mutex_lock(&data->mutex_state);
// 			last_meal = data->philo[i].last_meal;
// 			if ((get_time() - last_meal) > data->time_to_die)
// 			{
// 				print_action(&data->philo[i], "died");
// 				data->is_dead = 1;
// 				pthread_mutex_unlock(&data->mutex_state);
// 				return (NULL);
// 			}
// 			if (data->repetition > 0
// 				&& data->philo[i].meal_num >= data->repetition)
// 				full_count++;
// 			pthread_mutex_unlock(&data->mutex_state);
// 			i++;
// 		}
// 		if (data->repetition > 0 && full_count == data->num_philo)
// 			return (NULL);
// 		usleep(500);
// 	}
// }