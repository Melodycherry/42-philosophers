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



