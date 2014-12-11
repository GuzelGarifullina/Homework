/* Long arithmetics: multilication and devision based on one-way linked list
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
//#include "list_writer.h"
#include "long_arithm_list_int.h" //long arithmetics based on one-way list
//#define TERM_OF_EXIT 'e'

//#include "mult_long.h"//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "formating_input.h"


int main(void) {

    printf("Введите 2 числа \n");
   Long_num_list a, b, c; // struct sign and head of list

    a.head = NULL;
   // char ch = read_till_minus_or_digit();
  //  read_Long_num_list (&a, ch);

    b.head = NULL;
   char ch = read_till_minus_or_digit();
    read_Long_num_list (&b, ch);
     c.head = NULL;

    sum_Long_Int_list (&b, b, b);
   // reverse_Long_Num_Int_list(&b);
   // c.sign = 1;
    write_Long_num_list(b);
  //  write_Long_num_list(a);
   // write_Long_num_list(b);

return 1;
}

   /* sum_Long_Int_list(&c,a,b);
    write_Long_num_list(c);

    del_Long_num_list(&c);
    sub_Long_Int_list(&c,a,b);
    write_Long_num_list(c);

    // free memory
    del_Long_num_list(&a);
    del_Long_num_list(&b);
    del_Long_num_list(&c);


    return (0);
}*/

