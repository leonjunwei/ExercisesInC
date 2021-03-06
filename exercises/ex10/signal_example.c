/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: MIT License

Based on an example from
https://raw.githubusercontent.com/twcamper/head-first-c/master/10/math-master.c

Based on an example in Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

/* Set up a signal handler.

   sig: signal number
   handler: signal handler function
*/
int catch_signal(int sig, void (*handler) (int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}




void handle_single_question(void){
    int a, b, answer;
    char txt[4];

    // seed the random number generator
    srandom((unsigned int) time(NULL));

            // pose the question
        a = rand() % 11;
        b = rand() % 11;
        printf("\nWhat is %d times %d? ", a, b);



        // get the answer
        char *ret = fgets(txt, 4, stdin);
        answer = atoi(txt);

        // check the answer
        if (answer == a * b) {
            printf("\nRight!\n");
            score++;
        } else {
            printf("\nWrong!\n");
        }
        printf("Score: %i\n", score);
}

/* Signal handler: End the game.
 */
void end_game(int sig)
{
    printf("\nFinal score: %i\n", score);
    exit(EXIT_SUCCESS);
}

/* Signal handler: Notify the user and raise SIGINT.
*/
void times_up(int sig) {
    handle_single_question();
    puts("\nTIME'S UP!");
    raise(SIGINT);
}

int main(void) {


    // when the alarm goes off, call times_up
    catch_signal(SIGALRM, times_up);

    // if we get interrupted, end the game
    catch_signal(SIGINT, end_game);



    while(1) {

        // set (or reset) the alarm
        alarm(5);
        handle_single_question();

    }


    return 0;
}
