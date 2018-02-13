## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

* 6? 5 bits would let us represent 32.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

* 2^32 = 4294967296 characters

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

* Memory is volatile (unusable once power is cut) but storage is persistent

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

* GiBs and GBs have different sizes (GiB is 1024^3 bytes, GB is 1000^3 bytes). The internet says 1GiB ≈ 1.074GB.

5) How does the virtual memory system help isolate processes from each other?

* Each process is assigned some virtual address space, which it can "use" to read and write from. However, the computer translates these virtual addresses into physical memory addresses on a per-process basis, meaning that no matter what virtual address the process is designed to call, it will never physically conflict with another address used by a different process. 

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

* So they can both grow without bumping into each other.

7) What Python data structure would you use to represent a sparse array?

* A dictionary/hashmap, probably.

8) What is a context switch?

* A context switch occurs when a computer saves the state of one process and shuts it down, running another process.

