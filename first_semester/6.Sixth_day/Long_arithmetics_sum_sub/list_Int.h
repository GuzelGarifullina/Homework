#ifndef LIST_INT_H
#define LIST_INT_H

struct NODE {
    int value;
    struct NODE *next;
};

void reverse_Int_list (NODE **head);//reverse int list
void print_list_Int (const NODE *head); //print list
void  del_list_Int (NODE **head);// delete list

void push_to_list_Int (NODE **head , int new_elem);//create new node and puts number
int pop_head_list_Int (NODE **head);//take value and free, if list empty returns 0
void del_head_elem_list_Int (NODE **head);//free head element
void remove_elem_list_Int (NODE **head, int num);

// returns adress of previous to element that equals num
// we sure that head !== num
NODE *find_prev_for_equal_elem_Int_list (NODE *cursor, const int num );




#endif // LIST_INT_H
