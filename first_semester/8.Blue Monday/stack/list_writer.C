/* One-way linked list reading numbers and operators
 * "a" - add, "r" - remove, "p" - print, "f" - reverse, "e" -exit
 * Author: Garifullina Guzel, 171 group */


#include "list_writer.h"

#define TERM_OF_EXIT 'e'

#include <stdio.h>
#include "list_Int.h"
#include "formating_input.h"

void concole_Int_list(void) {
    NODE *head = NULL; //create null list

    printf("Начните ввод\n");
    char ch;
    int num;

    do {
        scanf("%c",&ch);
        skip_spaces(&ch);
        if (ch != 'e'){ //else exit
            switch (ch) {
                case 'a':
                    scanf("%d",&num) ;
                    push_to_list_Int(&head, num);// pushes num to the head of list
                    break;
                case 'r':
                    scanf("%d",&num) ;
                    remove_elem_list_Int(&head, num);//delete first element that equals to num
                     break;
                case 'p':
                    print_list_Int (head);// print list from head to the last element
                    break;
                case 'f':// reverse
                    reverse_Int_list (&head);
                    break;
            default:
                printf("Error! Illegal symbol\n");    // stop reading and program
                ch = TERM_OF_EXIT;
                break;
            }
        }

    } while (ch !=  TERM_OF_EXIT  ) ;     // read  until operator "e" - exit


    del_list_Int(&head); // free memory
}

