#include "polish_notation.h"

#include <stdio.h>
#include <ctype.h> /* isspace*/

#define Error "\nError!Stack ended! \n"

void calculate_polish_notation_Int_list (void) {
    Stack_of_Long_numbers *st_head;
    st_head = NULL;
    int sign;

    char ch;
     do {
         scanf("%c", &ch);
         if ((ch != ' ') && (ch !='\n')){
            if (ch == '-'){
               scanf("%c", &ch);
               if (ch == ' ' || ch == '\n'){
                   operations_polish_notat_stack_list_Int (&st_head, '-');
               }
               else { // digit
                   sign = negative;
                   read_push_stack_number_Int_list (&st_head, sign, ch);
               }
            }
            else if (isdigit(ch)){
                sign = positive;
                read_push_stack_number_Int_list (&st_head, sign, ch);
            }
            else if ( isalpha (ch)){
                if (ch == 'p'){
                    print_stack_list_Int (st_head);
                }
                else if (ch == 'e'){
                    break;
                }
            }
            else {// operand
                operations_polish_notat_stack_list_Int (&st_head, ch);
            }
        }
     } while (ch != 'e');
  del_stack_list_Int (&st_head);
 }

//read digits unites to long number
// push long number to stack
void read_push_stack_number_Int_list
        (Stack_of_Long_numbers **st_head, const int sign, char ch){
    Long_num_list long_num;
    long_num.head = NULL;
    long_num.sign = sign;

    read_Long_num_list (&long_num, ch );
    push_to_stack_list_Int (st_head, long_num);
    del_Long_num_list (&long_num);
}

// writes to stack result of operation
// ch is operator
// if there isn't enough numbers writes terminal message
void operations_polish_notat_stack_list_Int
            (Stack_of_Long_numbers **st_head, const char ch){
    Long_num_list a, b, res;
    a.head = NULL;
    b.head = NULL;
    res.head = NULL;

    int indicator;
    indicator = pop_head_stack_list_Int (&a, st_head);
    if (indicator){
        indicator = pop_head_stack_list_Int (&b, st_head);
        if (! indicator){
            printf ("%s", Error);
            push_to_stack_list_Int (st_head, a);
            del_Long_num_list (&a);
            return;
        }
    }
    else { // stack empty
        return;
    }

    switch (ch) {
    case '+':
        sum_Long_Int_list (&res, a, b);
        break;
    case '-':
        sub_Long_Int_list (&res, a, b);
        break;
    case '*':
        mult_Long_Int_list (&res, a, b);
        break;
    default:
        break;
    }
    reverse_Long_Int_list (&res);
    push_to_stack_list_Int( st_head, res);

    del_Long_num_list (&a);
    del_Long_num_list (&b);
    del_Long_num_list (&res);
}
