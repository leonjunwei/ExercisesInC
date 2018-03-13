/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}



void free_node(Node* node) {
    free(node);
}

/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node* head = *list;
    int retval = head->val;
    
    free_node(*list);
    *list = head->next;
    
    if (list == NULL) {
        return -1;
    } else {
    return retval;
    }
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node* new_first = make_node(val, *list);
    *list = new_first;
    // FILL THIS IN!
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    int count = 0;
    Node *current = *list;
    Node *nextNode = current->next; 

    if(current->val == val) {
        pop(list);
        count++;
    }

    while (nextNode != NULL) {
        if (nextNode->val == val) {
            current->next = nextNode->next;
            free_node(nextNode);
            count++;
        }
        else {
        current = nextNode;
        nextNode = nextNode->next;
        }
    }
    return count;

}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
Node* reverseHelper(Node* node1, Node* node2) {
    Node * retval = node2->next;
    node2->next = node1;
    return retval;
}

void reverse(Node **list) { /*Looked up an implementation on the internet for non-recursive version*/
    // FILL THIS IN!
    Node* current = *list;
    Node* prev = NULL;
    Node* next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);
    head->next->next->next->next = make_node(3, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    int num_removed = remove_by_value(list, 3);
    printf("num_removed: %i\n", num_removed);
    print_list(list);

    num_removed = remove_by_value(list, 7);
    printf("num_removed: %i\n", num_removed);
    print_list(list);

    reverse(list);
    print_list(list);
}
