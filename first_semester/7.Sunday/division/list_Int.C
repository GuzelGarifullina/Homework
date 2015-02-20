#include "list_Int.h" // Header file

#include <stdio.h>
#include <stdlib.h>  /* malloc, free exit */
#include <ctype.h> /* isspace*/

#define NO_elem_to_remove "Error!Cannot find %d in the list\n"


// print elements of list and \n
void print_list_Int (const NODE *head){
    while (head){
        printf("%d", head->value);
        head = head->next;
    }
    printf("\n");

}

//reverse int list
void reverse_Int_list (NODE **head){
// we move head to the end and change directions of the list
    // if list is empty
    if (*head == NULL) {
        return;     // list still NULL
    }
    NODE *tmp = NULL;   // temporary elem = new next elem = last position of head
    NODE *next ;        // next = next element of old list (need to know next position of head)
    while ((*head)->next != NULL){
        next = (*head)->next;   // next position of head
         (*head)->next= tmp; // last position of head
        tmp = *head;
        *head = next;       // move head to next element

    }
    (*head)->next= tmp; // put head->next to head elem
}


// delete list
void del_list_Int (NODE **head){
    while (*head != NULL){
       del_head_elem_list_Int (head);
    }
}

//  delete head elem and return it's value
// if list empty returns 0
int pop_head_list_Int (NODE **head){
    NODE *prev = NULL;
    int val;
    if (*head == NULL) {    // case when list is empty
        return (0);             // it stays empty
    }
    prev = (*head);     // to not lose head adress
    val = prev->value; // to return value
    (*head) = (*head)->next;
    free (prev); // delete ex-head and free memory
    return val;
}


// take number and pushes to the head of list
void push_to_list_Int(NODE **head , int new_elem){
    NODE *tmp =  (NODE*) malloc (sizeof (NODE)); //allocates memory
    tmp->value = new_elem; // put value to temporary node
    tmp->next =  (*head) ;
    (*head) = tmp;
}

// push to list another list in back order
void push_to_list_list_Int (NODE **head, NODE * pushed){
    while (pushed != NULL){
        push_to_list_Int (head , pushed->value );
        pushed = pushed->next;
    }
}



// delete head element
void del_head_elem_list_Int (NODE **head){
    if (*head == NULL) { //case when list is empty
       return;           // it stays empty
    }
    NODE *prev = (*head);
    (*head) = (*head)->next;
    free (prev); // delete ex-head and free memory
}


// find and remove first element that equals num
void remove_elem_list_Int (NODE **head, int num){
    // list empty
    if (*head == NULL){
      printf ( NO_elem_to_remove , num);
      return;
    }
    //else
    NODE *cursor = (*head);

    //head = value
    if (cursor->value == num){
        del_head_elem_list_Int (&cursor);
        *head = cursor;
    }
    else {
        NODE *previous = find_prev_for_equal_elem_Int_list (cursor, num);
        cursor = previous->next;
        if (cursor != NULL){    // mean that not reach the end
            previous->next = cursor->next; // change pointer to next number of previous number
                                     // cause we will delete cursor.value element
            free (cursor); // delete this node
        }
        else {
            printf (NO_elem_to_remove , num);
        }
    }
}

// returns adress of previous to element that equals num
// we sure that head !== num
NODE *find_prev_for_equal_elem_Int_list (NODE *cursor, const int num ){
 // cursor starting point of list (head)
 // num - elem we look for

    NODE *previous = cursor; // needs to remember previous adress
    cursor = cursor->next;  // because cursor-> value not equal num
    while (cursor && (cursor->value != num)){ //look for num
        previous = cursor;
        cursor = cursor->next;
    }
    return (previous);
}

//is list = 0 or empty
int is_List_Null (NODE *head){
    if (head == NULL){
        return (Yes);
    }
    else if ((head->value ==0) && (head->next == NULL)){
        return (Yes);
    }
    else {
        return (No);
    }
}

//push 0
void make_list_Int_NULL (NODE **res){
    del_list_Int (res);
    push_to_list_Int (res, 0);
}

// amount of digits
int length_list_Int (NODE *head){
    int amount = 0;
    while (head != NULL){
        amount++;
        head = head->next;
    }
    return (amount);
}

