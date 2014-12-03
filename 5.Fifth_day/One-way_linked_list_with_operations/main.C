/* One-way linked list reading numbers and operators
 * "a" - add, "r" - remove, "p" - print, "e" -exit
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
#include <stdlib.h>  /* malloc, free exit */
#include <ctype.h> /* isspace*/

#include "list_Int.h"



int main(void) {
    NODE *head = NULL; // head of Node

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
                    push_to_list_Int(&head, num);
                    break;
                case 'r':
                    scanf("%d",&num) ;
                    remove_elem_list_Int(&head, num);//delete first element that equals to num
                     break;
                case 'p':
                    print_list_Int (head);
                    break;
            default:
                printf("Error!\n");    // stop reading and program
                ch = TERM_OF_EXIT;
                break;
            }
        }

    } while (ch !=  TERM_OF_EXIT ) ;     // read  until operator "e" - exit


    del_list_Int(&head);
    return (0);
};
