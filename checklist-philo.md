## PHILOSOPHER

### **Main checklist**
What to do :  
•	Create a data structure to store all required information about a philosopher  
•	Create the correct number of philosopher  
•	Create the correct number of threads  
•	Create a routine (What each philosopher has to do ? In which order ?)  
•	Initiate the threads with said routine  

*Some variables have to be shared between all philosophers so take this into account when creating your data structures.*

### **Routine checklist**
•	Create a loop that runs until any of your philosophers die  

*If you have to loop until any of your philosphers die, it might be a good idea to check in the routine if any of your philosopher has died.*

That's basically it. Your philosophers have to do the following things (in order) in the routine.  
1.	Eat   
2.	Sleep  
3.	Think  
4.	Repeat  

Check how threads work and how you can use mutexes to lock / unlock some values. Once you understood that, you "just" have to make each philosopher eat, sleep and think in a loop. Don't forget to print the logs when the state of your philosophers change.

ex : ./philo 5 800 200 200 7


WHAT TO DO NEXT :

- init les mutex
chaque fourchette = un mutex
autant de fourchette que de philo
mettre dans un tabkeau dans la struct globale ( data)
-> Chaque philo récupère une fourchette gauche et une droite en fonction de son id (ex : left = i, right = (i + 1) % nb_philo)

- creer les thread
faire un thread par philo
utiliser la fonction pthread_create()
pthread_create(&philo[i].thread, NULL, &routine, &philo[i]); ???
dans la routine faire un cat ?? 

- la routine :
fork left
fork right
print "take forks"
faire avec timestamp pour le last meal time ( a mettre dans la struc )
time to eat ( avec usleep)
unlock left
unlock right
time to sleep ( usleep again )
print "thinkin"

- creer un thread de monitoring 
pour verif si un philo meurt 
arrete tt si philo meurt ou si ils ont tous fait leur nombre de repetition

-join tts les thread
check again comment ca marche
dans le main attendre la fin des thread des philo ET du monitor

- free et destroy
destroy tous les mutex
free tt 
philo, fork, struct ... 