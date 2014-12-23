#include "formating_input.h"
#include <stdio.h>
#include <ctype.h> /* isspace*/

#define TERM_OF_EXIT 'e'

// returns first minus or digit
char read_till_minus_or_digit (void){
    char ch;
    do {
        scanf("%c",&ch);
    } while ( (ch!= '-') && !(isdigit(ch)) ); //reads till finds negative sign or digit
    return(ch);
}

// skip spaces
void skip_spaces (char *ch){
    while (isspace(*ch)){
        scanf("%c", ch);
    }
}

// returns first minus or digit
char read_till_operand_or_digit (void){
    char ch;
    do {
        scanf("%c",&ch);
    } while ( !(is_operand(ch)) && !(isdigit(ch)) ); //reads till finds negative sign or digit
    return(ch);
}

int is_operand (char ch){
    if ( (ch == '+') || (ch == '-')
         || (ch == '*') || (ch == '/')) {
        return (1);
    }
    else {
        return (0);
    }
}
