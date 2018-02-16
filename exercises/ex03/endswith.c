/* Example code for Software Systems at Olin College.

Instructions:

1) Fill in the body of endswith so it passes the tests.

You can use any of the functions in string.h
https://www.tutorialspoint.com/c_standard_library/string_h.htm

2) Remove the TODO comment.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* endswith: Checks whether s ends with suffix.

s: string
suffix: string
returns: 1 if true, 0 otherwise
*/
int endswith(char *s, char *suffix)
{
    // int res;
    // TODO: Fill this in!
    int diff = strlen(s)-strlen(suffix);
    if (diff < 0) return 0;
    else if (strcmp(s+diff,suffix) == 0) {
            return 1;
        } else {
            return 0;
        };

    // if (strlen(s)<strlen(suffix)){
    //     // res = 0;
    //     return 0;
    // }

    // else if (strlen(s)==strlen(suffix)) {
    //     if (strcmp(s,suffix)==0) {
    //         // res = 1;
    //         return 1;
    //     } else {
    //         // res = 0;
    //         return 0;
    //     }
    // } else {
    //     // res = endswith(s+1, suffix);
    //     return endswith(s+1, suffix);
    // }

    // return res;
}


// int test(int* stuff) {
//     return stuff;
// }

/* test_endswith
*/
void test_endswith(char *s1, char *s2, int expected) {
    int got = endswith(s1, s2);
    assert(got == expected);
}


int main (int argc, char *argv[])
{
    test_endswith("endswith", "swith", 1);
    test_endswith("endswith", "ends", 0);
    test_endswith("endswith", "offendswith", 0);

    // what's the right answer?
    // test_endswith("endswith", "", ?);

    printf("All tests passed\n");

    // printf("%d\n", test(10));
}
