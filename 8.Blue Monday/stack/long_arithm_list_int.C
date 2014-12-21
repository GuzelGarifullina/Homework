#include "long_arithm_list_int.h"
#include <stdio.h>
#include <ctype.h> /* isspace*/


//reads list long number, not change sign, ch is first digit
// direct -> back order
void read_Long_num_list (Long_num_list *num, char ch){

    do {
        push_to_list_Int (&(num->head), ch - '0');
        scanf ("%c",&ch); // next elem
    } while  (isdigit(ch));
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

void copy_Long_list_Int (Long_num_list *where, Long_num_list what){//change order
    if ( where->head != NULL){
        del_Long_num_list (where);
    }
    where->sign = what.sign;

    while (what.head != NULL){
        push_to_list_Int (& where->head , what.head->value );
        what.head = what.head->next;
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
    int indicator = compare_Long_Int_list(minuend,subtrahend);
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


// "0" - a = b ; "1" - a > b ; "-1" - a < b
// when a, b in back order
int compare_Long_Int_list (Long_num_list a, Long_num_list b){ // a, b const
    int indicator = equal;
    while (a.head && b.head){
        if (a.head->value > b.head->value) {
            indicator = more;
        }
        else if (a.head->value < b.head->value) { // it will compare highest digits
            indicator = less;                     // and remember which number bigger
        }                                         // if highest digits equal
        a.head = a.head->next;
        b.head = b.head->next;
    }
    if (a.head){ // a longer b
        return (more);
    }
    else if (b.head){// b longer a
        return (less);
    }
    else return (indicator); // compare values as a and b have one length

}

//returns num with opposite sign
Long_num_list neg_elem_Long_Int_list ( Long_num_list num){ // const num
    num.sign = - num.sign;
    return(num);
}

// push 0
void make_Num_Int_NULL (Long_num_list *res){
    make_list_Int_NULL (& res->head);
    res->sign = positive;
}








