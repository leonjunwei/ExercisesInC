## Homework 1

### C Exercises

<<<<<<< HEAD
[Here is a link to the ex01 directory in my repository](https://github.com/leonjunwei/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
  * Dynamic typing (and storing variable names) is common in interpreted languages but rare in compiled languages.

2) Name two advantages of static typing over dynamic typing.
  * Compiler can check argument input types of a function when the function is called, instead of when it's run
  * Compiler can check for type mismatches at compile time instead of run time. This is faster, and errors can be found in parts of the code that are never called at run time.
  
3) Give an example of a static semantic error.
  * Calling a function with the wrong number or type of arguments

4) What are two reasons you might want to turn off code optimization?
 * (Forgot to answer this question) - optimization might break something in the program
 * Also optimization might make subtle changes in a running program that make it harder to debug. 
 
5) When you run `gcc` with `-S`, why might the results look different on different computers?
  * gcc is apparently configured to generate code for the machine it's run on.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?
 * My best guess is that the program that checks for function names (linker) is different from the one that checks for variable names (compiler)?
 
7) What is a segmentation fault?
 * An error that occurs when a program tries to read from or write to an illegal location in memory.
