/*
This file helps people cheat in casinos.

Written by Leon Lam
25 Jan 2018
*/


#include <stdio.h>
#include <stdlib.h>


char * get_card(){
    /*
    Prompts the user for a card name and returns it as an array (I think that's what the asterisk means, this was mainly trial and error).
    */
    static char card_name[3];
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    return card_name;
}


int print_count(char *card_name, int count){ 
    /* 
    Takes in a character array *card_name and the current count as an integer, updates the new count and prints it. 
    */
    int val = 0;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            val = -100;
            break;
        default:
            val = atoi(card_name);
            if(val<=1 || val>10){
                puts("I don't understand that value");
                return count;
            }
    }
    if((val>=2) && (val<=7)) {
        count++;
    } else if (val >= 10) {
        count--;
    }
    printf("Current count: %i\n", count);
    return count;
}


int play_game(){ 
/* Does the actual card-counting with get_card and print_count.*/
    int count = 0;

    while(1){
        char * card_name;
        card_name = get_card();
        if (card_name[0] == 'X') {
            return 0;
        }
        count = print_count(card_name, count);
    }
    


}



int main()
    {
    return play_game();
    }