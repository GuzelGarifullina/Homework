/* Reverse Polish notation with stack (Long arithmetics based on one-way linked list)
 * Author: Garifullina Guzel, 171 group */

#include "polish_notation.h"
#include <stdlib.h>
#include <stdio.h>
FILE *input;


int main (int argc, char **argv){
    input = NULL;
    input = freopen (argv[1], "r", stdin);
    int res = calculate_polish_notation_Int_list();

    return (res);
}
