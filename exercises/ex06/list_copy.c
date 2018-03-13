/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
    int val;
    struct node2 *next;
} Node1;

typedef struct node2 {
    int val;
    struct node1 *next;
} Node2;

int main(){
    return 0;
}