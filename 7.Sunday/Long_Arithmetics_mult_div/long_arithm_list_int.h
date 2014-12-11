#ifndef LONG_ARITHM_LIST_H
#define LONG_ARITHM_LIST_H
class long_arithm_h
{
public:
    long_arithm_h();
};

#endif // LONG_ARITHM_LIST_H


#include "list_Int.h" // make one-way linked list and works with it

struct Long_num_list {
    NODE * head;
    int sign;
};

//deletes list and writes to list long number
void read_Long_num_list (Long_num_list *num, char ch);// need for input first symbol of num

void write_Long_num_list (Long_num_list num); // writes number

void del_Long_num_list (Long_num_list *num); // deletes long num

// general
void sum_Long_Int_list (Long_num_list *sum, const Long_num_list augend,
                        const Long_num_list addend);
void sub_Long_Int_list (Long_num_list *c, const Long_num_list minuend,
                        const Long_num_list subtrahend);

void del_top_zeros_Int_list (Long_num_list *num);
// sum case when a and b have one sign
void sum_one_sign_Int_list (Long_num_list *res, Long_num_list augend,
                                      Long_num_list addend);

// returns head of not ended list
// changes higher and res = augend + addend (it cuts longest and sum)
// size(res) = min (sizes of augent and addend), not change sign
NODE * sum_one_length_Int_list_return_not_ended_list (NODE **res,
                                NODE *augend, NODE *addend, int *high);

//  res = res + part of longest list that was cut + higher
void add_sum_of_rest_list_and_higher_Int_list(NODE **res,
                                NODE *head, int higher);



//sub minuend and subtrahend positive
void sub_Long_pos_Int_list  (Long_num_list *diff, Long_num_list minuend,
                             Long_num_list subtrahend);
//sub minuend and subtrahend positive, minuend bigger than subtrahend
void sub_Long_pos_minuend_bigger_Int_list  (NODE **diff, NODE *minuend, NODE *subtrahend);
// changes head of not ended list (minuend)
// changes debt and difference = minuend - subtrahend (it cuts minuend to size of subtrahend)
// not change sign
void sub_subtrahend_change_debt_head_minuend_Int_list (NODE **diff,
                                NODE **minuend, NODE *subtrahend, int *debt);
// sub minuend to debt
// not change sign
void sub_minuend_debt_Int_list (NODE **diff,
                                NODE *minuend, int debt);


//compare "0" - a = b ; "1" - a > b ; "2" - a < b
int compare_Long_Int_list(Long_num_list a, Long_num_list b); // a, b const
//returns num with opposite sign, not change num sign
Long_num_list neg_elem_Long_Int_list (Long_num_list num);

