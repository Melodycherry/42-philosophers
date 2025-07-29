
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