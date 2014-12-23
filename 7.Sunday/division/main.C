/* Long arithmetics: division based on one-way linked list
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
#include "long_arithm_list_int.h" //long arithmetics based on one-way list
#include "formating_input.h"

int main(void) {

    printf("Введите 2 числа \n");
   Long_num_list a, b, c; // struct sign and head of list

    a.head = NULL;
    char ch = read_till_minus_or_digit();
    read_Long_num_list (&a, ch);
    a.sign = 1;

    b.head = NULL;
    ch = read_till_minus_or_digit();
    read_Long_num_list (&b, ch);
    b.sign = 1;
    c.head = NULL;
    c.sign = 1;

    div_Long_num_list( &c,a,b);
    write_Long_num_list(c);

    del_Long_num_list(&a);
    del_Long_num_list(&b);
    del_Long_num_list(&c);

return 0;
}
