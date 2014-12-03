/* One-way linked list reading numbers
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
#include <stdlib.h>     /* malloc, free exit */

#define TERM_OF_EXIT 0 // we will read till null

struct NODE {
    int value;
    struct NODE *next;
};

void push_to_list_Int (NODE **head , int new_elem);//malloc
int pop_list_Int(NODE **head);//take value and free

int main(void) {
    NODE *head = NULL; // head of Node

    //reading n
    int num;
    printf("Введите числа ");

    scanf("%d",&num);
    while (num !=  TERM_OF_EXIT ) {         // read numbers to list until 0
        push_to_list_Int(&head, num);
        scanf("%d",&num);
    }

    while (head)  {

        printf("%d ", pop_list_Int(&head));
    }
     printf("\n ");
    return (0);
};

    // take number and pushes to the head of list
    void push_to_list_Int(NODE **head , int new_elem){
        NODE *tmp =  (NODE*) malloc (sizeof (NODE)); //allocate memory
        tmp->value = new_elem; // put value to temporary node
        tmp->next =  (*head) ;
        (*head) = tmp;
   };
    int pop_list_Int(NODE **head){
        NODE *prev = NULL;
        int val;
        if (*head == NULL) {
            exit(-1);
        }
        prev = (*head);
        val = prev->value;
        (*head) = (*head)->next;
        free(prev);
        return val;
    };


