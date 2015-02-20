#include "stack_one_way_list.h"

#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

void calculate_polish_notation_Int_list (void);

//read digits unites to long number
// push long number to stack
void read_push_stack_number_Int_list
        (Stack_of_Long_numbers **st_head, const int sign,  char ch);

// writes to stack result of operation
// ch is operator
// if there isn't enough numbers writes terminal message
void operations_polish_notat_stack_list_Int
    (Stack_of_Long_numbers **st_head,const char ch);


#endif // POLISH_NOTATION_H
