/* Long arithmetics: sum and sub based on one-way linked list
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
#include "Long_Arithm_list_Int.h" //long arithmetics based on one-way list

int main(void) {

    printf("Введите 2 числа \n");
    Long_num_list a, b, c; // struct sign and head of list

    a.head = NULL;
    read_Long_num_list (&a);

    b.head = NULL;
    read_Long_num_list (&b);

    c.head = NULL;

    sum_Long_Int_list(&c,a,b);
    write_Long_num_list(c);

    del_Long_num_list(&c);
    sub_Long_Int_list(&c,a,b);
    write_Long_num_list(c);

    // free memory
    del_Long_num_list(&a);
    del_Long_num_list(&b);
    del_Long_num_list(&c);


    return (0);
}
