/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include "stack_one_way_list.h"

//#include "long_arithm_list_int.h"
#include <stdio.h>
#include <stdlib.h>  /* malloc, free exit */
#include <ctype.h> /* isspace*/


// print elements of stack and \n between
void print_stack_list_Int  (Stack_of_Long_numbers *st_head){
    printf ("[");
    if (st_head != NULL){
        if (st_head->value.sign == -1){
            printf("-");
        }
        print_list_Int (st_head->value.head);
        st_head = st_head->next;
    }
    while (st_head != NULL){   //const
        printf ("; ");
        if (st_head->value.sign == -1){
            printf("-");
        }
        print_list_Int (st_head->value.head);
        st_head = st_head->next;
    }
   printf ("]\n");
}

// delete stack
void del_stack_list_Int (Stack_of_Long_numbers **st_head){
    while (*st_head){
       del_head_elem_stack_list_Int (st_head);
    }
}

// delete head element of stack
void del_head_elem_stack_list_Int (Stack_of_Long_numbers **st_head){
    if (*st_head == NULL) { //case when list is empty
       return;           // it stays empty
    }
    Stack_of_Long_numbers *prev = (*st_head);
    (*st_head) = (*st_head)->next;

    del_Long_num_list (& prev->value);
    free (prev); // delete ex-head and free memory
}


// take number and pushes to the head of list
void push_to_stack_list_Int (Stack_of_Long_numbers **st_head ,
                            Long_num_list new_elem){
    Stack_of_Long_numbers *tmp =  (Stack_of_Long_numbers*)
            malloc (sizeof (Stack_of_Long_numbers)); //allocates memory
    tmp->value.head = NULL;
    copy_Long_Int_list (& tmp->value, new_elem); // where then what
    tmp->next =  (*st_head) ;
    (*st_head) = tmp;
}


//  delete head elem of stack and return it's value
// if head empty function says Yes
int pop_head_stack_list_Int (Long_num_list *put_head,
                              Stack_of_Long_numbers **st_head){
    Stack_of_Long_numbers *prev = NULL;

    if (*st_head == NULL) {
        return (Yes);
    }

    prev = (*st_head);    // to not lose head of stack
    copy_Long_Int_list (put_head, prev->value );
    (*st_head) = (*st_head)->next;

    del_Long_num_list (&prev->value);
    free (prev); // delete ex-head and free memory
    return (No);
}


int is_stack_empty (Stack_of_Long_numbers  *st_head){
    if (st_head == NULL){
        return (Yes);
    }
    else {
        return (No);
    }
}
