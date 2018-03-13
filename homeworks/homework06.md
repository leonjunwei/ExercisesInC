## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/leonjunwei/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

* free() probably takes constant time. realloc() and calloc() are probably proportional to the size of one of the chunks, and apparently malloc() is sort of proportional to how easy it is to find a chunk of the right size (and add boundary tags)?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

* We get a completely arbitrary value.

b) Writing to unallocated memory.

* It's possible that we'll write something in an unallocated chunk, allocate (but not clear) it later, and call it without changing its contents. Then we're in trouble because there's something there that we didn't expect. Alternatively we might overwrite some of malloc()'s  internal structure.

c) Reading from a freed chunk.

* We get something we weren't expecting (something else wrote something in the freed chunk, maybe).

d) Writing to a freed chunk.

* We write something in a freed chunk and later on we get something we aren't expecting again. A freed chunk is basically unallocated memory, AFAIK?

e) Failing to free a chunk that is no longer needed.

* Memory leaks. If a program creates enough chunks that aren't freed, eventually they'll eat up all available memory?


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

* compiz and root

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

* Fragmentation apparently makes memory caching less effective. Defragmentation tends to help.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
