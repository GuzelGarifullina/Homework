/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
//#include "long_arithm_list_int.h" //long arithmetics based on one-way list
#include "formating_input.h"
#include <ctype.h> /* isspace*/
#include "stack_one_way_list.h"

int main(void) {
    Stack_of_Long_numbers *st_head;
    st_head = NULL;

    Long_num_list long_num, a, b, res;
    long_num.head = NULL;
    a.head = NULL;
    b.head = NULL;
    res.head = NULL;


    char ch;
     do {
         scanf("%c", &ch);
         if ((ch != ' ') && (ch !='\n')){
            if (ch == '-'){
               scanf("%c", &ch);
               if (ch == ' ' || ch == '\n'){
                   pop_head_stack_list_Int (&a, &st_head);
                   pop_head_stack_list_Int (&b, &st_head);
                   sub_Long_Int_list (&res, a, b);

                   reverse_Long_Int_list (&res);
                   push_to_stack_list_Int( &st_head, res);

                   del_Long_num_list (&a);
                   del_Long_num_list (&b);
                   del_Long_num_list (&res);
               }
               else { // digit
                   long_num.sign = negative;
                   read_Long_num_list (&long_num, ch );
                   push_to_stack_list_Int (&st_head, long_num);
                   del_Long_num_list (&long_num);
               }

            }
            else if (isdigit(ch)){
                long_num.sign = positive;
                read_Long_num_list (&long_num, ch);
                push_to_stack_list_Int (&st_head, long_num);
                del_Long_num_list (&long_num);
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
                pop_head_stack_list_Int (&a, &st_head);
                pop_head_stack_list_Int (&b, &st_head);

                switch (ch) {
                case '+':
                    sum_Long_Int_list (&res, a, b);
                    break;
                case '*':
                    mult_Long_Int_list (&res, a, b);
                    break;
                default:
                    break;
                }
                reverse_Long_Int_list (&res);
                push_to_stack_list_Int( &st_head, res);

                del_Long_num_list (&a);
                del_Long_num_list (&b);
                del_Long_num_list (&res);

            }

        }
     } while (ch != 'e');
  del_stack_list_Int (&st_head);
  return 0;

 }

