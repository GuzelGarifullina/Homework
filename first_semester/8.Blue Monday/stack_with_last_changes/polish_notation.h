/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include "stack_one_way_list.h"

#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

int calculate_polish_notation_Int_list (void);
int print_head_elem_stack_list_Int
            (Stack_of_Long_numbers **st_head);

//read digits unites to long number
// push long number to stack
int read_push_stack_number_Int_list
        (Stack_of_Long_numbers **st_head, const int sign,  char *ch);

// writes to stack result of operation
// ch is operator
// if there isn't enough numbers writes terminal message
int operations_polish_notat_stack_list_Int
    (Stack_of_Long_numbers **st_head,const char ch);

#endif // POLISH_NOTATION_H
