creer un thread pour chaque philo
utiliser mutex

mutex init va prendre nune variable et la verouiller 
mutex unlock pour ouvrir 
1 seul philo qui peut entrer 

race conduction ; qd plusieur philo tenten d'acceder a la meme chose
date race ; mutex dans le mutex

routine : eat, sleep, think ( think etant le temps pas defaut restant ) 

les philos ne peuvent pas communiquer entre eux 

utilisation d'un monitoring : un thread en plus pour boucler sur les philos et checker s'ils sont morts 
tant qu'ils ne meurent pas ils vivent a l'infini
si un philo meurt on arrete la simulation 

booleen pour check si fork dispo
* fork left
* fork right

ft_ussleep()
avec dedasn usleep()

philo routine
eat
sleep
think

coder chaque fonction ( avec un printf simple )

boucle while(1) qui tourne tout le temps

t_data pour la structure
stocker le nombre de philo 
time to eat
time to ...

check le sujet
check les parametres
check les fonctions autorisees et faire resumer 



— DRD: Run with valgrind --tool=drd to check for data races.

— Helgrind: Run with valgrind --tool=helgrind to find lock issues and potential deadlocks.

— FSanitise: Compile with -fsanitize=thread to detect threading problems while running.

