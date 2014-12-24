/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include "list_Int.h" // make one-way linked list and works with it

#ifndef LONG_ARITHM_LIST_H
#define LONG_ARITHM_LIST_H

#define BASE  10
#define Null_division "Division by zero\n"

struct Long_num_list {
    NODE * head;
    int sign;
};

typedef enum {positive = 1, negative = -1, empty = 0} signifier;
typedef enum {more = 1, less = -1 , equal = 0} compare;


//reads list long number, not change sign, ch is first digit
// tells if number ended with illegal letter
int read_Long_num_list (Long_num_list *num, char ch);// direct -> back order

// writes with \n in the end
void write_Long_num_list (Long_num_list num);// back -> direct order

void del_Long_num_list (Long_num_list *num);

//reverse number (changes order)
void reverse_Long_Int_list (Long_num_list *num);

void copy_Long_Int_list (Long_num_list *where, Long_num_list what);//change order

//returns 1 if division imposible
// direct -> back order
int div_Long_num_list (Long_num_list *quotient,
                            Long_num_list numerator, Long_num_list denominator);
// general
//  back -> direct order
void mult_Long_Int_list (Long_num_list *product, Long_num_list multiplicand,
                    Long_num_list multiplier);
void sum_Long_Int_list (Long_num_list *sum, const Long_num_list augend,
                        const Long_num_list addend);
void sub_Long_Int_list (Long_num_list *c, const Long_num_list minuend,
                        const Long_num_list subtrahend);
//returns num with opposite sign, not change num sign
Long_num_list neg_elem_Long_Int_list (Long_num_list num);

void make_Num_Int_NULL (Long_num_list *res);

#endif // LONG_ARITHM_LIST_H



