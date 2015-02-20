#include "formating_input.h"
#include <stdio.h>
#include <ctype.h> /* isspace*/

#define TERM_OF_EXIT 'e'

// skip spaces
void skip_spaces (char *ch){
    while (isspace(*ch)){
        scanf("%c", ch);
    }
}

// returns first minus or digit
char read_till_minus_or_digit (void){
    char ch;
    do {
        scanf("%c",&ch);
    } while ( (ch!= '-') && !(isdigit(ch)) ); //reads till finds negative sign or digit
    return(ch);
}
