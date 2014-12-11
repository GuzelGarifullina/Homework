#include "long_arithm_list_int.h"
#include <stdio.h>
#include <ctype.h> /* isspace*/


#define BASE  10
typedef enum {positive = 1, negative = -1, empty = 0} signifier;
typedef enum {more = 1, less = 2 , equal = 0} compare;

//deletes list and writes to list long number
void read_Long_num_list (Long_num_list *num, char ch){// need for input first symbol of num

    del_Long_num_list (num); // make list empty

    // sets the sign
    if (ch == '-') {
        num->sign = negative;
    }
    else {
        num->sign = positive;
        push_to_list_Int (&(num->head) , ch - '0'); // puts first digit of num
    }

    scanf ("%c",&ch); // next elem

    // puts number to list
    while  (isdigit(ch)) {
        push_to_list_Int (&(num->head) , ch - '0');
        scanf ("%c",&ch); // next elem
    }
}

// writes with \n in the end
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
    num->sign = 0;
}


// general sum
void sum_Long_Int_list (Long_num_list *sum, const Long_num_list augend,
                        const Long_num_list addend){
    Long_num_list res;
    if (augend.sign*addend.sign == positive){
        sum_one_sign_Int_list (&res,augend,addend); // in sum elements have one sign
    }
    else if (augend.sign == positive){// addend.sign = negative
        sub_Long_pos_Int_list  (&res, augend, neg_elem_Long_Int_list (addend));
        // in sub all elements positive
    }
    else {// augend.sign = neg , addend.sign = pos (-augend +addend)
        sub_Long_pos_Int_list  (&res, neg_elem_Long_Int_list (augend), addend);
        res.sign = -res.sign; // value = augend - addend
    }
    del_top_zeros_Int_list (&res);

    del_Long_num_list (sum);
    *sum = res;
}
// general
void sub_Long_Int_list (Long_num_list (*res),const Long_num_list minuend,
                        const Long_num_list subtrahend){
    sum_Long_Int_list (res,minuend, neg_elem_Long_Int_list(subtrahend));
}


void del_top_zeros_Int_list (Long_num_list *num){
    while (num->head && (num->head->value == 0) ){
            del_head_elem_list_Int (& num->head);
        }
    if (num->head == NULL){
        push_to_list_Int(& num->head, 0);
        num->sign = positive;
    }
}

// res = augend + addend when summends have one sign
void sum_one_sign_Int_list (Long_num_list *res, Long_num_list augend,
                            Long_num_list addend){ // const augend, addend
    int higher = 0; // jumps to next rank
    res->sign = augend.sign;

    NODE *head = sum_one_length_Int_list_return_not_ended_list (&(res->head),  augend.head,
                                                                addend.head, &higher);
    // head = head of not ended list, changes higher and res = augent + addend,
    // size(res) = min (sizes of augent and addend), not change sign

    add_sum_of_rest_list_and_higher_Int_list (& res->head, head, higher);
}

// returns head of not ended list
// changes higher and res = augend + addend (it cuts longest and sum)
// size(res) = min (sizes of augent and addend), not change sign
NODE * sum_one_length_Int_list_return_not_ended_list (NODE **res,
                                NODE *augend,NODE *addend, int *high){
    int higher = *high;
    int sum; //sum = augend + addend + higher
    while (augend && addend){
        sum =  augend->value + addend->value + higher;
        push_to_list_Int (res, sum % BASE ); // res = sum %BASE
        higher = sum / BASE ;
        augend = augend->next;
        addend = addend->next;
    }
    *high = higher;
    if (augend != NULL){
        return (augend);
    }
    else{
        return(addend);
    }
}

//add to res sum of the rest of list and higher
void add_sum_of_rest_list_and_higher_Int_list (NODE **res,
                                NODE *head, int higher){
    int sum;
    while (head != NULL){ // head is one of summands heads that not ended
        sum =  head->value + higher;
        push_to_list_Int (res, sum % BASE  ); // res = sum %BASE
        higher = sum / BASE ;
        head = head->next;
    }
    if (higher){
        push_to_list_Int (res , higher);
    }
}


// difference = minuend - subtrahend when minuend and subtrahend positive
void sub_Long_pos_Int_list  (Long_num_list *diff, Long_num_list minuend,
                             Long_num_list subtrahend){
    int indicator = compare_Long_Int_list(minuend,subtrahend);
    if (indicator == equal){
       push_to_list_Int (& diff->head, 0 );
       diff->sign = positive;
    }
    else if (indicator == more){
        sub_Long_pos_minuend_bigger_Int_list (&diff->head ,minuend.head ,subtrahend.head);
        diff->sign = positive;
    }
    else  {// less
        sub_Long_pos_minuend_bigger_Int_list (&diff->head ,subtrahend.head ,minuend.head);
        diff->sign = negative;
    }
}

// difference = minuend - subtrahend  when minuend and subtrahend positive
// and minuend bigger than subtrahend
void sub_Long_pos_minuend_bigger_Int_list  (NODE **diff, NODE *minuend, NODE * subtrahend){
    int debt = 0;
    sub_subtrahend_change_debt_head_minuend_Int_list (diff,&minuend, subtrahend, &debt);
    sub_minuend_debt_Int_list (diff, minuend, debt);
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


// "0" - a = b ; "1" - a > b ; "2" - a < b
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





