
#define TERM_OF_EXIT 'e'// we will read till 'e'-exit
struct NODE {
    int value;
    struct NODE *next;
};

void skip_spaces(char *ch); // read till find symbol(that not space)

void push_to_list_Int (NODE **head , int new_elem);//create new node and puts number
int pop_elem_list_Int(NODE **head);//take value and free
void del_head_elem_list_Int(NODE **head);//free head element


void remove_elem_list_Int(NODE **head, int num);
void print_list_Int (const NODE *head); //print list
void  del_list_Int(NODE **head);// delete list


// skip spaces
void skip_spaces (char *ch){
    while (isspace(*ch)){
        scanf("%c", ch);
    }
}


// find and remove first element that equals num
void remove_elem_list_Int(NODE **head, int num){
    NODE *cursor = (*head); // delete head element
    if (! cursor){
        printf("Error!Cannot find %d in the list\n", num);
        return;
    }
    if (cursor->value == num){
        del_head_elem_list_Int (&cursor);
        *head = cursor;
    }
    else {
        NODE *previous = cursor; // need to change adress
        cursor = cursor->next;  // because cursor-> value not equal num
        while (cursor && (cursor->value != num)){ //look for num
            previous = cursor;
            cursor = cursor->next;
        }
        if (cursor){    // mean that not reach the end
            previous->next = cursor->next; // change pointer to next number of previous number
                                     // cause we will delete cursor.value element
            free(cursor); // delete this node
        }
        else {
            printf("Error!Cannot find %d in the list\n", num);
        }
    }
}


// print elements of list
void print_list_Int (const NODE *head){
    while (head){
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\n");

}

// delete list
void del_list_Int(NODE **head){
    while (*head){
       del_head_elem_list_Int(head);
    }
}


// take number and pushes to the head of list
void push_to_list_Int(NODE **head , int new_elem){
    NODE *tmp =  (NODE*) malloc (sizeof (NODE)); //allocate memory
    tmp->value = new_elem; // put value to temporary node
    tmp->next =  (*head) ;
    (*head) = tmp;
}

//  delete head elem and return it's value
int pop_head_list_Int(NODE **head){
    NODE *prev = NULL;
    int val;
    if (*head == NULL) {    // case when list is empty
        exit(-1);
    }
    prev = (*head);     // to not lose head adress
    val = prev->value; // to return value
    (*head) = (*head)->next;
    free(prev); // delete ex-head and free memory
    return val;
}

// delete head element
void del_head_elem_list_Int(NODE **head){
    if (*head == NULL) { //case when list is empty
        exit(-1);
    }
    NODE *prev = (*head);
    (*head) = (*head)->next;
    free(prev); // delete ex-head and free memory
}


