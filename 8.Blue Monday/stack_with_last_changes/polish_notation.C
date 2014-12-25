/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */
#include "polish_notation.h"

#include <stdio.h>
#include <ctype.h> /* isspace*/

#define Not_enogh_argument "Not enough arguments\n"
#define unknown "Unknown command\n"

// checks is it if it +, -, *, /
// else returns no
int is_operand (char ch);


int calculate_polish_notation_Int_list(void) {
    Stack_of_Long_numbers *st_head;
    st_head = NULL;
    int sign;
    int leave = 0;

    char ch ;
    scanf("%c", &ch);
    while (ch != 'e')  {
        if (! iscntrl (ch) && (ch !=' ')) {
           if (ch == '-'){
              scanf("%c", &ch);
              if (iscntrl (ch) || (ch == ' ')){
                leave = operations_polish_notat_stack_list_Int (&st_head, '-');
              }
              else { // digit
                sign = negative;
                leave = read_push_stack_number_Int_list (&st_head, sign, &ch);
              }
           }
           else if (isdigit(ch)){
               sign = positive;
               leave = read_push_stack_number_Int_list (&st_head, sign, &ch);
           }

           else if (ch == '='){
               leave = print_head_elem_stack_list_Int (&st_head);
           }
           else if (is_operand(ch)){// operand
               leave = operations_polish_notat_stack_list_Int (&st_head, ch);
           }
           else {
               printf (unknown);
               leave = Yes;
           }
       }

     if (leave){
         del_stack_list_Int (&st_head);
         return (Yes);
     }
     if (ch == 'e'){
         break;
     }
     scanf("%c", &ch);
   }

   print_stack_list_Int (st_head);
   del_stack_list_Int (&st_head);
   return (No);
 }

//read digits unites to long number
// push long number to stack
int read_push_stack_number_Int_list
        (Stack_of_Long_numbers **st_head, const int sign, char *ch){
    Long_num_list long_num;
    long_num.head = NULL;
    long_num.sign = sign;

    int illigal_letter = read_Long_num_list (&long_num, ch );
    push_to_stack_list_Int (st_head, long_num);
    del_Long_num_list (&long_num);
    if (illigal_letter){
        printf (unknown );
    }
    return (illigal_letter);
}

// writes to stack result of operation
// ch is operator
// if there isn't enough numbers writes terminal message
int operations_polish_notat_stack_list_Int
            (Stack_of_Long_numbers **st_head, const char ch){
    Long_num_list a, b, res;
    a.head = NULL;
    b.head = NULL;
    res.head = NULL;

    int no_elem;
    no_elem = pop_head_stack_list_Int (&a, st_head);
    if (! no_elem){
        no_elem = pop_head_stack_list_Int (&b, st_head);
        if (no_elem){
            printf (Not_enogh_argument);
            push_to_stack_list_Int (st_head, a);
            del_Long_num_list (&a);
            return (Yes);
        }
    }
    else { // stack empty
        return (Yes);
    }
    int div_bad = No;

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
    case '/':
        div_bad = div_Long_num_list (&res, a, b);
        break;
    default:
        break;
    }
    reverse_Long_Int_list (&res);
    push_to_stack_list_Int( st_head, res);

    del_Long_num_list (&a);
    del_Long_num_list (&b);
    del_Long_num_list (&res);
    return (div_bad);
}


int print_head_elem_stack_list_Int
            (Stack_of_Long_numbers **st_head){
    Long_num_list a;
    a.head = NULL;

    int no_elem;
    no_elem = pop_head_stack_list_Int (&a, st_head);
    if (no_elem){
        printf ( Not_enogh_argument);
        }
    else {
        reverse_Long_Int_list (&a);
        write_Long_num_list (a);
        printf ("\n");
    }
    reverse_Long_Int_list (&a);
    push_to_stack_list_Int (st_head, a);
    del_Long_num_list (&a);
    return (no_elem);
}

// checks is it if it +, -, *, /
// else returns no
int is_operand (char ch){
    if ( (ch == '+') || (ch == '-')
         || (ch == '*') || (ch == '/')) {
        return (Yes);
    }
    else {
        return (No);
    }
}
