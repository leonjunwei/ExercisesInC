## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

* They need a stack and a stack pointer and return addresses and all that stuff to call functions, so having a separate stack means each thread can call functions without interfering with each other.

2) What does the gcc flag `-lpthread` do?

* It links the pthread library.

3) What does the argument of `pthread_exit` do?

* It passes a value to whichever thread joins the exiting thread.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

* The join will probably work, but maybe the parent thread that's waiting to rejoin its child  will now wait forever?

5) What goes wrong if several threads try to increment a shared integer at the same time?

* They access the integer in an unsynchronized fashion, so the order in which they read or write the integer may be randomized.

6) What does it mean to "lock a mutex"?

* When a thread locks a mutex for a block of code, it blocks all other running threads from executing that block of code. This ensures the code is run by only one thread at a time, and usually in a predictable fashion.

