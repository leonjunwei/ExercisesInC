## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/leonjunwei/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

* Handling interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

*  The program counter?

3) What is the difference between an interrupt and a context switch?

* An interrupt usually has the same process running before and after it, while a context switch means a different process runs after the switch. In addition, a context switch sometimes involves clearing data from the MMU and loading new data into a cache, while an interrupt usually does not.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

* A process receives a reply to a packet that it sent some time ago.

5) Why might a scheduler want to give higher priority to an I/O bound process?

* The user may be waiting for a reply, so an I/O bound process that's just gotten a reply might be more important than a CPU-bound process running in the background.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

* Put 8 slices on 8 cores. Wait 5 minutes, then flip and wait another 5 minutes. Put the remaining 4 slices on 4 cores. Wait 5 minutes, then flip and wait another 5 minutes. This also allows us to start another 4 pieces of french toast if more people show up before the first 10 minutes have elapsed.



