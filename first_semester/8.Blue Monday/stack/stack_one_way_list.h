#include "long_arithm_list_int.h"

#ifndef STACK_ONE_WAY_LIST_H
#define STACK_ONE_WAY_LIST_H

struct  Stack_of_Long_numbers {
    Long_num_list value;
    Stack_of_Long_numbers  *next;
};

void print_stack_list_Int  (Stack_of_Long_numbers *st_head);

void del_stack_list_Int (Stack_of_Long_numbers **st_head);
void del_head_elem_stack_list_Int (Stack_of_Long_numbers **st_head);

// take number and pushes to the head of list
void push_to_stack_list_Int (Stack_of_Long_numbers **st_head ,
                            Long_num_list new_elem);
int pop_head_stack_list_Int (Long_num_list *put_head,
                              Stack_of_Long_numbers **st_head);

int is_stack_empty (Stack_of_Long_numbers  *st_head);


#endif // STACK_ONE_WAY_LIST_H
