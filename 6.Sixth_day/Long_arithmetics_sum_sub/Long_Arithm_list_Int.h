
#define BASE  10
#include <stdlib.h>  /* malloc, free exit */
#include <ctype.h> /* isspace*/

#include "list_Int.h" // make one-way linked list and works with it

typedef enum {positive = 1, negative = -1, empty = 0} signifier;

struct Long_num_list {
    NODE *head;
    int sign;
};

void read_Long_num_list (Long_num_list *num);//skips till finds sigh  or digit
                                          // reads to list long number
void write_Long_num_list (Long_num_list num); // writes number

void del_Long_num_list (Long_num_list *num); // deletes long num

// general
void sum_Long_Int_list (Long_num_list *c, const Long_num_list a, const Long_num_list b);
void sub_Long_Int_list (Long_num_list *c, const Long_num_list a, const Long_num_list b);


// sum case when a and b have one sign
void sum_Long(Long_num_list *c, Long_num_list a, Long_num_list b);


//sub a and b positive
void sub_Long_pos (Long_num_list *c, Long_num_list a, Long_num_list b); // const a, b
//sub  a and b positive, b bigger than a
void sub_Long_pos_firstnum_bigger (Long_num_list *c, Long_num_list a, Long_num_list b); // const a, b

//compare "0" - a = b ; "1" - a > b ; "2" - a < b
int compare_Long_Int_list(Long_num_list a, Long_num_list b); // a, b const
//returns num with opposite sign, not change num sign
Long_num_list neg_Long_Num_list (Long_num_list num);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// skips trash and reads to list long number(at first make it empty)
void read_Long_num_list (Long_num_list *num){
    char ch;

    do {
        scanf("%c",&ch);
    } while ( (ch!= '-') && !(isdigit(ch)) ); //reads till finds negative sign or digit

    del_Long_num_list(num);

   // num->head = NULL; //ensures that head is empty

    // sets the sign
    if (ch == '-') {
        num->sign = -1;
    }
    else {
        num->sign = 1;
        push_to_list_Int (&(num->head) , ch - '0'); // puts first digit of num
    }

    scanf("%c",&ch); // next elem

    // puts number to list
    while  (isdigit(ch)) {
        push_to_list_Int (&(num->head) , ch - '0');
        scanf("%c",&ch); // next elem

    }


}

// writes with \n in the end
void write_Long_num_list ( Long_num_list num){ // num const
    if (num.sign == -1){    // sign
        printf("-");
    }
    else if (!num.sign){// sign = 0
        printf("Doesn'exist\n");
        return;
    }
    while (num.head && (num.head->value == 0) ){   // don't write first nulls
        num.head = num.head->next;
    }
    if  (! num.head){      // case with null
        printf("0 \n");
    }
    else {
        print_list_Int (num.head);
    }
}

// deletes and frees list of digits, sign = 0
void del_Long_num_list (Long_num_list (*num)){
    del_list_Int(&(num->head));
    num->sign = 0;
}


// general
void sum_Long_Int_list (Long_num_list *c, const Long_num_list a, const Long_num_list b){
    if (a.sign*b.sign == positive){
        sum_Long (c,a,b); // in sum elements have one sign
    }
    else if (a.sign == positive){// b.sign = -1
        sub_Long_pos(c, a, neg_Long_Num_list(b)); // in sub all elements positive
    }
    else {// a.sign = -1 , b.sign = 1 (-a +b)
        sub_Long_pos( c, neg_Long_Num_list(a), b);// value = a - b
        c->sign = -c->sign;
    }
}
// general
void sub_Long_Int_list (Long_num_list (*c),const Long_num_list a,const Long_num_list b){
    sum_Long_Int_list(c,a, neg_Long_Num_list(b));
}

// c = a + b when a and b have one sign
void sum_Long(Long_num_list *c, Long_num_list a, Long_num_list b){ // const a, b
    int higher = 0; // jumps to next rank
    c->sign = a.sign;

    int sum; //sum = a + b + higher
    while (a.head && b.head){
        sum =  a.head->value + b.head->value + higher;
        push_to_list_Int (& c->head, sum % BASE ); // c = sum %BASE
        higher = sum / BASE ;
        a.head = a.head->next;
        b.head = b.head->next;
    }
    while (a.head){ // if b ended
        sum =  a.head->value + higher;
        push_to_list_Int (& c->head, sum % BASE  ); // c = sum %BASE
        higher = sum / BASE ;
        a.head = a.head->next;
    }
    while (b.head){ // if a ended
        sum =  b.head->value + higher;
        push_to_list_Int (& c->head, sum % BASE  ); // c = sum %BASE
        higher = sum / BASE ;
        b.head = b.head->next;
    }

    if (higher){
        push_to_list_Int (& c->head , higher);
    }
}


// c = a - b when a and b positive
void sub_Long_pos (Long_num_list *c, Long_num_list a, Long_num_list b){ // const a, b
    int indicator = compare_Long_Int_list(a,b);
    if (indicator == 0){
       push_to_list_Int (& c->head, 0 );
       c->sign = 1;
    }
    else if (indicator == 1){ // a > b
        sub_Long_pos_firstnum_bigger(c,a,b);
        c->sign = 1;
    }
    else  {// b>a
        sub_Long_pos_firstnum_bigger(c,b,a);
        c->sign = -1;
    }
}

// c = a - b when a and b positive and a bigger than b
void sub_Long_pos_firstnum_bigger (Long_num_list *c, Long_num_list a, Long_num_list b){ // const a, b
    int debt = 0;
    int value;
    while (b.head){
      value = (a.head->value) - b.head->value - debt;
      if (value >= 0){
          debt = 0;
          push_to_list_Int (& c->head, value );
      }
      else{
          debt = 1;
          push_to_list_Int (& c->head, value + BASE );
      }
      a.head = a.head->next;
      b.head = b.head->next;
    }
    while (a.head){
        value = (a.head->value) - debt;
        if (value >= 0){
            debt = 0;
            push_to_list_Int (& c->head, value );
        }
        else{
            debt = 1;
            push_to_list_Int (& c->head, value + BASE );
        }
        a.head = a.head->next;
    }
}



// "0" - a = b ; "1" - a > b ; "2" - a < b
int compare_Long_Int_list(Long_num_list a, Long_num_list b){ // a, b const
    int indicator = 0;
    while (a.head && b.head){
        if (a.head->value > b.head->value) {
            indicator = 1;
        }
        else if (a.head->value < b.head->value) { // it will compare highest digits
            indicator = 2;                         // and remember which number bigger
        }                                           // if highest digits equal
        a.head = a.head->next;
        b.head = b.head->next;
    }
    if (a.head){ // a longer b
        return(1);
    }
    else if (b.head){// b longer a
        return(2);
    }
    else return(indicator); // compare values as a and b have one length

}

//returns num with opposite sign
Long_num_list neg_Long_Num_list ( Long_num_list num){ // const num
    num.sign = - num.sign;
    return(num);
}






