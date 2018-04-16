## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

* No synchronization errors occur even if the data structure is accessed by multiple threads.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

* If we keep adding elements to the array, eventually the indices for the next insertion and next removal will overlap, which would lead us to conclude that the queue was empty when it was in fact full. We therefore have to check to see if incrementing the index for next insertion would overlap with next removal: if so, the list reports that it's full and cannot accept another insertion, even though only n-1 elements have been inserted.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

* Two threads both try to push concurrently: they both write to the same index of the queue array and then both increment next_in. This skips an entry on the array, I think.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

* If it doesn't unlock the mutex, no other thread can do any work, which might result in nothing happening forever.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

* The mutex is definitely unlocked, and the condition that we're waiting on has probably changed?

6) What happens if you signal a condition variable when there are no waiting threads?

* Nothing.

7) Do you have to lock the mutex to signal a condition variable?

* I don't think so.

8) Does the condition have to be true when you signal a condition variable?

* Not necessarily? It just has to change.




