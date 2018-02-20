## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/leonjunwei/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

* They provide the abstraction that your files are in a certain place on the computer. For example, logically a user would expect the data that makes up a file to be stored contiguously (or at least close together), but that's not always the case.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

* Each entry contains some sort of file identifier which tells the file system which files are open?

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

* Read large blocks of data whenever possible, start fetching blocks before they're actually requested, buffer written data on memory and write it to disk later, and cache the blocks in case the user wants them again.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

* We wrote some stuff but it hadn't been saved to disk, only buffered in volatile memory - when we lost power the memory was gone. 

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

* A File Allocation Table stores just enough information for you to reach all the blocks, as opposed to an inode which may take up more space than it actually needs (for files of awkward size). But reading from the middle of a file is easier with an inode, since we can do the math and call the appropriate block instead of needing to iterate through the linked-list-esque File Allocation Table Entry.

6) What is overhead?  What is fragmentation?

* Overhead is the additional cost that has to be paid for a functioning system. In the case of block management, it's how much space or time you need to set up the system that tells you where the blocks are, and which blocks are being used. Fragmentation is unused block space (whether partial or total).

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

* If everything is a stream of bytes, programmers who know how to interact with the stream can interact with basically anything on a computer. I'm not entirely sure why it might be a bad idea - something to do with time like concurrency or unsynchronized processes?

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



