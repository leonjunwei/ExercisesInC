/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 6;
    void *p = malloc(128);
    char *s = "Literal string";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("Address of p is %p\n", p);
    printf ("Address of s is %p\n", s);

    return 0;
}

/*
Address of main is 0x40057d
Address of var1 is 0x60104c
Address of var2 is 0x7ffd521ef158
Address of var3 is 0x7ffd521ef15c
Address of p is 0x7dc010
Address of s is 0x4006b4

*/