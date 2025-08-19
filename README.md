# 🍝 Philosophers - Threads & Mutexes

## 🎯 Objectifs

- Découvrir les **bases du multithreading** en C.  
- Comprendre l’utilisation des **mutex** pour éviter les problèmes de concurrence.  
- Implémenter une **simulation** du problème classique des philosophes mangeant des spaghettis.  

## 🪑 Description du projet

Un certain nombre de philosophes sont assis autour d’une table ronde, avec un grand plat de spaghettis au centre 🍝.  
Chaque philosophe alterne entre **manger**, **dormir** et **penser**:  

```
   ┌───────────┐
   │  Manger   │ 🍝
   └─────┬─────┘
         │
         ▼
   ┌───────────┐
   │  Dormir   │ 😴
   └─────┬─────┘
         │
         ▼
   ┌───────────┐
   │ Penser    │ 🤔
   └─────┬─────┘
         │
         ▼
      (boucle)
```

- Pour manger, un philosophe doit prendre **deux fourchettes** (celle de gauche et celle de droite). 🍴  
- Quand il a fini, il repose ses fourchettes et passe à l’étape suivante.  
- La simulation **s’arrête si un philosophe meurt** de faim (⏳ trop longtemps sans manger).
- OU s'ils ont mangé chacun le nombre de fois prédéterminé.    
- L’objectif est que **personne ne meure** et que la simulation soit correctement synchronisée.  

 
## ⚙️ Règles globales et paramètres

- **Pas de variables globales** 🚫.  
- Le programme doit prendre les arguments suivants :  

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers` → Nombre de philosophes et de fourchettes  
- `time_to_die (ms)` → Temps max avant qu’un philosophe meure sans avoir mangé  
- `time_to_eat (ms)` → Temps que met un philosophe pour manger  
- `time_to_sleep (ms)` → Temps passé à dormir  
- `[number_of_times_each_philosopher_must_eat]` → *(optionnel)* Si tous les philosophes ont mangé ce nombre de fois, la simulation s’arrête  

## 📋 Exemple de logs

200 1 has taken a fork  
201 1 has taken a fork  
202 1 is eating  
402 1 is sleeping  
603 1 is thinking  
800 1 died  


## 🔑 Contraintes

• 👤 Chaque philosophe est représenté par un thread  
• 🍴 Chaque fourchette est protégée par un mutex  
• 🥲 Si un seul philosophe → il ne peut pas manger car une seule fourchette est disponible  
• 🚫 Pas de data races tolérées  

--- 

**🧠 Ce que j’ai appris**:  

• 🧵 Gestion des threads avec `pthread`  
• 🔒 Synchronisation avec mutex pour protéger les ressources partagées  
• ⏳ Gestion du temps avec `gettimeofday` et `usleep`  
• 🛠️ Implémentation d’une simulation concurrente robuste  
• ❌ Détection et prévention des data races et deadlocks  

---

✅ **STATUT:**  
📅 **Date de rendu** : En attente   
📝 **Note obtenue** : En attente  

---
