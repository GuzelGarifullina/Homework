#ifndef LIST_INT_H
#define LIST_INT_H

struct NODE {
    int value;
    struct NODE *next;
};

typedef enum {Yes = 1, No = 0} check_it;

void print_list_Int (const NODE *head);

void reverse_Int_list (NODE **head);

void  del_list_Int (NODE **head);
void del_head_elem_list_Int (NODE **head);//free head element

void push_to_list_Int (NODE **head , int new_elem);//create new node and puts number
int pop_head_list_Int (NODE **head);//take value and free, if list empty returns 0
void remove_elem_list_Int (NODE **head, int num);

// returns adress of previous to element that equals num
// we sure that head !== num
NODE *find_prev_for_equal_elem_Int_list (NODE *cursor, const int num );

//is list = 0 or empty
int is_List_Null (NODE *head);
// push 0
void make_list_Int_NULL (NODE **res);

#endif // LIST_INT_H
