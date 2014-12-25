/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include "long_arithm_list_int.h"
#include <stdio.h>
#include <ctype.h> /* isspace*/

void copy_Int_list (NODE **where, NODE *what );

// multiply long number and digit
void mult_num_to_digit_Long_Int_list (NODE **result, NODE *list,
                                      const int digit);// back->direct order
// shifted sum
void sum_one_sign_first_list_shifted_Int_Long (NODE **res,
            NODE *shifted, NODE *staticList, int shift);// back -> direct order
// sum case when a and b have one sign
void sum_one_sign_Int_list (Long_num_list *res, Long_num_list augend,
                                      Long_num_list addend);// back -> direct order
void sum_one_sign_no_change_sign_Int_list (NODE **res,
            NODE *augend, NODE *addend);// back -> direct order
// returns head of not ended list
// changes jump and res = augend + addend (it cuts longest and sum)
// size(res) = min (sizes of augent and addend), not change sign
NODE * sum_one_length_Int_list_return_not_ended_list (NODE **res,
                                NODE *augend, NODE *addend, int *jumper);
//  res = res + part of longest list that was cut + jump
void add_sum_of_rest_list_and_jump_Int_list(NODE **res,
                                NODE *head, int jump);
//sub minuend and subtrahend positive
void sub_Long_pos_Int_list  (Long_num_list *diff, Long_num_list minuend,
                             Long_num_list subtrahend);// back -> direct order
//sub minuend and subtrahend positive, minuend bigger than subtrahend
void sub_Long_pos_minuend_bigger_Int_list  (NODE **diff, NODE *minuend,
                                            NODE *subtrahend);// back -> direct order
// changes head of not ended list (minuend)
// changes debt and difference = minuend - subtrahend (it cuts minuend to size of subtrahend)
// not change sign
void sub_subtrahend_change_debt_head_minuend_Int_list (NODE **diff,
                                NODE **minuend, NODE *subtrahend, int *debt);
// sub minuend to debt
// not change sign
void sub_minuend_debt_Int_list (NODE **diff,
                                NODE *minuend, int debt);
void del_top_zeros_Int_list (Long_num_list *num);//in direct ord

//compare "0" - a = b ; "1" - a > b ; "-1" - a < b
int compare_pos_direct_Long_Int_list(Long_num_list a, Long_num_list b);

//compare "0" - a = b ; "1" - a > b ; "-1" - a < b
int compare_direct_Int_list (NODE *a, NODE *b);
int compare_direct_one_length_Int_list (NODE *a, NODE *b);

//amount of digits in long num
int length_Long_Int_list (Long_num_list a);

int compare_short_num (int a, int b);

int compare_pos_back_Long_Int_list(Long_num_list a, Long_num_list b); // a, b in back ord
int compare_back_Int_list (NODE *a, NODE *b);

void make_Num_Int_ONE (Long_num_list *res);

// direct -> back order
//returns qoutient nd remainder
int div_mod_Long_num_list (Long_num_list *quotient, Long_num_list *remainder,
                            Long_num_list numerator, Long_num_list denominator);
// main part finds quotint and reminder
void div_mod_main_Long_num_list (Long_num_list *quotient, Long_num_list *remainder,
                            Long_num_list numerator, Long_num_list denominator);
// finds first digits of divident, that equatly more than divisor
// if there isn't returns (1)
int minuend_init_Long_Int (NODE **minuend, NODE **divident, NODE *divisor_back);

// cut from second list n first digits and puts it to first
// if there isn't enogth digits returns 1
int cut_to_puted_cuted_length_Int_list(NODE **put, NODE **cuted, int leng);


//reads list long number, not change sign, ch is first digit
// direct -> back order
int read_Long_num_list (Long_num_list *num, char *ch){

    do {
        push_to_list_Int (&(num->head), *ch - '0');
        scanf ("%c",ch); // next elem
    } while  (isdigit(*ch));
    int illegal_letter = (! iscntrl (*ch) && (*ch != ' ') && (*ch !='e'));
    return (illegal_letter);
}


// writes with \n in the end
// back -> direct order
 void write_Long_num_list ( Long_num_list num){ // num const
    if (num.sign == negative){
        printf ("-");
    }
    else if (num.sign == empty){
        printf ("Doesn'exist\n");
        return;
    }
    if  (num.head == NULL){
        printf ("0 \n");
    }
    else {
        print_list_Int (num.head);
    }
}


// deletes and frees list of digits, sign = 0
void del_Long_num_list (Long_num_list (*num)){
    del_list_Int (&(num->head));
    num->sign = empty;
}


//reverse number (changes order)
void reverse_Long_Int_list (Long_num_list *num){
    reverse_Int_list(& num->head );
}


void copy_Long_Int_list (Long_num_list *where, Long_num_list what){//change order
    copy_Int_list (&where->head, what.head);
    where->sign = what.sign;
}

void copy_Int_list (NODE **where, NODE *what ){
    if (*where != NULL){
        del_list_Int (where);
    }
    while (what != NULL){
        push_to_list_Int (where , what->value );
        what = what->next;
    }
}

//returns 1 if division imposible, make sure that remainder not negative
// direct -> back order
int div_Long_num_list (Long_num_list *quotient,
                            Long_num_list numerator, Long_num_list denominator){
    Long_num_list remainder, one_list;
    remainder.head = NULL;
    one_list.head = NULL;

    int ind =  div_mod_Long_num_list (quotient, &remainder, numerator,
                                                 denominator);
    if (ind){
        return (Yes);
    }

    if ((numerator.sign == negative) && (! is_List_Null (remainder.head))){
        if (is_List_Null(quotient->head)){
            make_Num_Int_ONE (quotient);
            quotient->sign = remainder.sign;
        }
        else {
            make_Num_Int_ONE (&one_list);
            reverse_Long_Int_list (quotient);
            sum_one_sign_Int_list (quotient, *quotient, one_list);
        }
    }
    del_Long_num_list (&one_list);
    del_Long_num_list (&remainder);
    return (No);
}



//returns 1 if division imposible
// direct -> back order
int div_round_Long_num_list (Long_num_list *quotient,
                            Long_num_list numerator, Long_num_list denominator){
    Long_num_list remainder, remainder_copy;
    remainder.head = NULL;
    remainder_copy.head = NULL;

    int ind =  div_mod_Long_num_list (quotient, &remainder, numerator,
                                                 denominator);
    if (ind){
        return (Yes);
    }
    copy_Long_Int_list (&remainder_copy, remainder );
    reverse_Long_Int_list (&remainder);
    sum_one_sign_Int_list (&remainder, remainder, remainder_copy);
    int indicator = compare_pos_direct_Long_Int_list (denominator, remainder);
    if (indicator < more){
        if (is_List_Null (quotient->head)){
            make_Num_Int_ONE (quotient);
            quotient->sign = remainder.sign;
        }
        else {
            make_Num_Int_ONE (&remainder);
            reverse_Long_Int_list (quotient);
            sum_one_sign_Int_list (quotient, *quotient, remainder);
        }
    }
    del_Long_num_list (&remainder);
    del_Long_num_list (&remainder_copy);
    return (No);
}

// direct -> back order
//returns qoutient nd remainder
int div_mod_Long_num_list (Long_num_list *quotient, Long_num_list *remainder,
                            Long_num_list numerator, Long_num_list denominator){
    if (is_List_Null (denominator.head)){
        printf ("%s", Null_division);
        return (Yes);
    }
    int sign = numerator.sign * denominator.sign;
    quotient->sign = sign;
    remainder->sign = sign;
    div_mod_main_Long_num_list (quotient, remainder, numerator, denominator);

    del_top_zeros_Int_list (remainder);
    del_top_zeros_Int_list (quotient);
    return (No);
}

// main part finds quotint and reminder
void div_mod_main_Long_num_list (Long_num_list *quotient, Long_num_list *remainder,
                            Long_num_list numerator, Long_num_list denominator) {
    NODE *divident = NULL;
    NODE *divisor_back = NULL;

    copy_Int_list (&divident, numerator.head); // direct ord
    copy_Int_list (&divisor_back, denominator.head);
    reverse_Int_list (&divisor_back); // back ord

    NODE * minuend = NULL;
    int div_ended = minuend_init_Long_Int (&minuend, &divident, divisor_back);

    int first = Yes;
    int indicator;

    while (! div_ended){
        if (first){
            first = No;
            indicator = compare_back_Int_list (minuend, divisor_back);
        }
        else {
            int digit = pop_head_list_Int (&divident);
            push_to_list_Int (&minuend, digit );

            indicator = compare_back_Int_list (minuend, divisor_back);

            while ((indicator == less) && (divident)) {
                digit = pop_head_list_Int (&divident);
                push_to_list_Int (&minuend, digit );
                push_to_list_Int (&quotient->head, 0);
                indicator = compare_back_Int_list (minuend, divisor_back);
            }
       }
        int amt = 0;
        while (indicator == more){
            sub_Long_pos_minuend_bigger_Int_list (&minuend , minuend,
                             divisor_back); // minuend direct
            while (minuend && (minuend->value == 0)){
                del_head_elem_list_Int (&minuend);
            }
            reverse_Int_list (&minuend); // minuend  back
            indicator = compare_back_Int_list (minuend, divisor_back);
            amt ++;
        }
        if (indicator == equal){
            amt ++;
            del_list_Int (&minuend);
        }
        push_to_list_Int (&quotient->head, amt);
        div_ended = (divident == NULL);
    }

    reverse_Long_Int_list (quotient); // direct
    copy_Int_list (&remainder->head, minuend); // remainder direct

    del_list_Int (&minuend);
    del_list_Int (&divisor_back);
}

// finds first digits of divident, that equatly more than divisor
// if there isn't returns (1)
int minuend_init_Long_Int (NODE **minuend, NODE **divident, NODE *divisor_back){
    int length = length_list_Int (divisor_back);
    int divident_ended  =
                    cut_to_puted_cuted_length_Int_list (minuend, divident, length);
    // minuend back ord
    if (divident_ended == Yes){
        return (Yes);
    }
    int indicator = compare_back_Int_list (*minuend, divisor_back);

    if (indicator == less){
        if (*divident == NULL){
            return (Yes);
        }
        else {
            int digit = pop_head_list_Int (divident);
            push_to_list_Int (minuend, digit );
        }
    }
    return (No);
}

// cut from second list n first digits and puts it to first
// if there isn't enogth digits returns 1
int cut_to_puted_cuted_length_Int_list(NODE **put, NODE **cuted, int leng){
    int digit ;
    while ((*cuted != NULL) && (leng != 0)){
        digit = pop_head_list_Int (cuted);
        push_to_list_Int (put, digit );
        leng --;
    }
    if ((*cuted == NULL) && (leng != 0)){
        return (Yes);
    }
    else {
        return (No);
    }
}


// general multiplication
//  back -> direct order
void mult_Long_Int_list (Long_num_list *product, Long_num_list multiplicand,
                    Long_num_list multiplier){
    if (is_List_Null(multiplicand.head) || is_List_Null(multiplier.head)){
        make_Num_Int_NULL (product);
        return;
    }
    Long_num_list res;
    res.head = NULL;
    res.sign = multiplicand.sign * multiplier.sign;

    int digit;
    NODE *sum;
    int shift = 0;

    while (multiplier.head){
        digit = multiplier.head->value;
        sum = NULL;
        mult_num_to_digit_Long_Int_list (&sum, multiplicand.head, digit);
        //sum
        reverse_Int_list (&sum);//sum in back order

        reverse_Long_Int_list(&res);//  to back
        sum_one_sign_first_list_shifted_Int_Long (& res.head, sum, res.head, shift);
        // res in

        shift ++;
        del_list_Int (&sum);
        multiplier.head = multiplier.head->next;
    }

    del_Long_num_list (product);
    *product= res; //res in
}

// multiply long number and digit
// back -> direct order
void mult_num_to_digit_Long_Int_list
(NODE **result, NODE *list, const int digit){
    if (digit == 0){
        make_list_Int_NULL(result);
        return;
    }
    int jump = 0;
    int product;
    while (list){
        product =  digit * list->value + jump;
        push_to_list_Int (result, product % BASE );
        jump = product / BASE ;
        list = list->next;
    }
    if (jump){
        push_to_list_Int (result, jump);
    }
}

void sum_one_sign_first_list_shifted_Int_Long (NODE **res,
            NODE *shifted, NODE *staticList, int shift){// back -> direct order
    int shift_note = shift;
    while (shift != 0) {
        push_to_list_Int (&shifted, 0);
        shift --;
    }

    sum_one_sign_no_change_sign_Int_list (res, shifted, staticList);

    while (shift_note) {
        del_head_elem_list_Int (&shifted);
        shift_note --;
    }
}


// general sum
// back -> direct order
void sum_Long_Int_list (Long_num_list *sum, const Long_num_list augend,
                        const Long_num_list addend){
    if (augend.sign*addend.sign == positive){
        sum_one_sign_Int_list (sum,augend,addend);
    }
    else if (augend.sign == positive){// addend.sign = negative
        sub_Long_pos_Int_list  (sum, augend, neg_elem_Long_Int_list (addend));
        // in sub all elements positive
    }
    else {// augend.sign = neg , addend.sign = pos (-augend +addend)
        sub_Long_pos_Int_list  (sum, neg_elem_Long_Int_list (augend), addend);
        sum->sign = -sum->sign; // value = augend - addend
    }
    if (is_List_Null (sum->head)){
        sum->sign = positive;
    }
}

// general sub
// back -> direct order
void sub_Long_Int_list (Long_num_list (*res),const Long_num_list minuend,
                        const Long_num_list subtrahend){
    sum_Long_Int_list (res,minuend, neg_elem_Long_Int_list (subtrahend));
}


// res = augend + addend when summends have one sign
// back -> direct order
void sum_one_sign_Int_list (Long_num_list *res, Long_num_list augend,
                            Long_num_list addend){ // const augend, addend
    res->sign = augend.sign;

    sum_one_sign_no_change_sign_Int_list (&res->head, augend.head, addend.head);
}

void sum_one_sign_no_change_sign_Int_list (NODE **res, NODE *augend,
                            NODE *addend){ // back -> direct order
    int jump = 0; // jumps to next rank
    NODE *sum = NULL;

    NODE *head = sum_one_length_Int_list_return_not_ended_list (&sum,  augend,
                                                                addend, &jump);
    // head = head of not ended list, changes jump and res = augent + addend,
    // size(res) = min (sizes of augent and addend), not change sign

    add_sum_of_rest_list_and_jump_Int_list (& sum, head, jump);

    del_list_Int (res);
    *res = sum;
}

// returns head of not ended list
// changes jump and res = augend + addend (it cuts longest and sum)
// size(res) = min (sizes of augent and addend), not change sign
NODE * sum_one_length_Int_list_return_not_ended_list (NODE **res,
                                NODE *augend,NODE *addend, int *jumper){
    int jump = *jumper;
    int sum; //sum = augend + addend + jump
    while (augend && addend){
        sum =  augend->value + addend->value + jump;
        push_to_list_Int (res, sum % BASE ); // res = sum %BASE
        jump = sum / BASE ;
        augend = augend->next;
        addend = addend->next;
    }
    *jumper = jump;
    if (augend != NULL){
        return (augend);
    }
    else{
        return (addend);
    }
}

//add to res sum of the rest of list and jump
void add_sum_of_rest_list_and_jump_Int_list (NODE **res,
                                NODE *head, int jump){
    int sum;
    while (head != NULL){ // head is one of summands heads that not ended
        sum =  head->value + jump;
        push_to_list_Int (res, sum % BASE  ); // res = sum %BASE
        jump = sum / BASE ;
        head = head->next;
    }
    if (jump){
        push_to_list_Int (res , jump);
    }
}


// difference = minuend - subtrahend when minuend and subtrahend positive
// back -> direct order
void sub_Long_pos_Int_list  (Long_num_list *diff, Long_num_list minuend,
                             Long_num_list subtrahend){
    int indicator = compare_pos_back_Long_Int_list(minuend,subtrahend);
    if (indicator == equal){
       make_Num_Int_NULL (diff);
    }
    else if (indicator == more){
        sub_Long_pos_minuend_bigger_Int_list (&diff->head ,minuend.head ,
                                              subtrahend.head);
        diff->sign = positive;
    }
    else  {// less
        sub_Long_pos_minuend_bigger_Int_list (&diff->head ,subtrahend.head ,
                                              minuend.head);
        diff->sign = negative;
    }

    del_top_zeros_Int_list (diff);
}

// when num in direct ord
void del_top_zeros_Int_list (Long_num_list *num){
    while (num->head && (num->head->value == 0) ){
            del_head_elem_list_Int (& num->head);
        }
    if (num->head == NULL){
        push_to_list_Int(& num->head, 0);
        num->sign = positive;
    }
}



// difference = minuend - subtrahend  when minuend and subtrahend positive
// and minuend bigger than subtrahend
// back -> direct order
void sub_Long_pos_minuend_bigger_Int_list (NODE **diff, NODE *minuend,
                                            NODE * subtrahend){
    int debt = 0;
    NODE *res = NULL;

    sub_subtrahend_change_debt_head_minuend_Int_list (&res,&minuend, subtrahend,
                                                      &debt);
    sub_minuend_debt_Int_list (&res, minuend, debt);

    del_list_Int (diff);
    *diff= res;

}


// changes head of not ended list (minuend)
// changes debt and difference = minuend - subtrahend (it cuts minuend to size of subtrahend)
// not change sign
void sub_subtrahend_change_debt_head_minuend_Int_list (NODE **diff,
                                NODE **minuend, NODE *subtrahend, int *debt){
    int value;
    while (subtrahend != NULL){
      value = (*minuend)->value - subtrahend->value - *debt;
      if (value >= 0){
          *debt = 0;
          push_to_list_Int (diff, value );
      }
      else{
          *debt = 1;
          push_to_list_Int (diff, value + BASE );
      }
      *minuend = (*minuend)->next;
      subtrahend = subtrahend->next;
    }
}

// sub minuend to debt
// not change sign
void sub_minuend_debt_Int_list (NODE **diff,
                                NODE *minuend, int debt){
    int value;
    while (minuend){
        value = (minuend->value) - debt;
        if (value >= 0){
            debt = 0;
            push_to_list_Int (diff, value );
        }
        else{
            debt = 1;
            push_to_list_Int (diff, value + BASE );
        }
        minuend = minuend->next;
    }
}

//compare "0" - a = b ; "1" - a > b ; "-1" - a < b
int compare_pos_direct_Long_Int_list(Long_num_list a, Long_num_list b){
    return (compare_direct_Int_list (a.head, b.head ));
}

//compare "0" - a = b ; "1" - a > b ; "-1" - a < b
int compare_direct_Int_list (NODE *a, NODE *b){
    int length_a = length_list_Int (a);
    int length_b = length_list_Int (b);
    int indicator = compare_short_num (length_a, length_b);

    if (indicator != equal){
        return (indicator);
    }
    return (compare_direct_one_length_Int_list (a,b));
}

int compare_direct_one_length_Int_list (NODE *a, NODE *b){
    while (a && (a->value == b->value) ){
        a = a->next;
        b = b->next;
    }
    if (a == NULL){
        return (equal);
    }
    return (compare_short_num (a->value, b->value ));
}


//amount of digits in long num
int length_Long_Int_list (Long_num_list a){
    return (length_list_Int (a.head));
}

int compare_short_num (int a, int b){
    if (a > b){
        return (more);
    }
    if (a < b){
        return (less);
    }
    return (equal);
}

// "0" - a = b ; "1" - a > b ; "-1" - a < b
// when a, b in back order
int compare_pos_back_Long_Int_list (Long_num_list a, Long_num_list b){ // a, b const
   return (compare_back_Int_list (a.head, b.head));

}

int compare_back_Int_list (NODE *a, NODE *b){ // a, b const
    int indicator = equal;
    while (a && b){
        if (a->value > b->value) {
            indicator = more;
        }
        else if (a->value < b->value) { // it will compare highest digits
            indicator = less;                     // and remember which number bigger
        }                                         // if highest digits equal
        a = a->next;
        b = b->next;
    }
    if (a){ // a longer b
        while ((a != NULL) && (a->value == 0)){
            a = a->next;
        }
        if (a) {
            return (more);
        }

    }
    if (b){ // a longer b
        while ((b != NULL) && (b->value == 0)){
            b = b->next;
        }
        if (b) {
            return (less);
        }
    }
    return (indicator); // compare values as a and b have one length

}

//returns num with opposite sign
Long_num_list neg_elem_Long_Int_list ( Long_num_list num){ // const num
    num.sign = - num.sign;
    return (num);
}

// push 0
void make_Num_Int_NULL (Long_num_list *res){
    make_list_Int_NULL (& res->head);
    res->sign = positive;
}
void make_Num_Int_ONE (Long_num_list *res){
    make_list_Int_NULL (& res->head);
    del_head_elem_list_Int (&res->head);
    push_to_list_Int (&res->head, 1);
    res->sign = positive;
}









