## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/leonjunwei/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

* The flow of execution jumps to a different point in the program.

2) What is the fundamental problem caches are meant to solve?

* Speed of instruction execution is often much faster than the speed of memory access.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

* 50% hit rate: 0.5 * 1 ns + 0.5 * 10 ns = 5.5 ns
* 90% hit rate: 0.9 * 1 ns + 0.1 * 10 ns = 1.9 ns

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

* Defragmentation tends to improve locality a little. Maybe putting all the bits a program needs to run in the same file?
* Fragmentation probably decreases locality. So does writing a new value into the program counter (jump/goto statements)?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

* Not really? It'll work better on most caches but you don't have to know any details about the actual cache (cache or block size etc.) to do it.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

* I'd say about $50/GiB?

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

* Each level of the hierarchy is bigger and slower than the one above it, and each level acts as a cache for the one below it. As we get closer to the bottom, we have more time to decide how best to use the cache. 

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

* Impose a limit on physical memory used by a certain process, or kill programs with very high rates of paging.



