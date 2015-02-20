/* Buffer overflow
Author: Garifullina Guzel, 171 group */

#include <stdio.h>

void prog1 (void) ;
int prog2 (void) ;

void prog1(void) {
    char buff[2];
    printf("prog2 %p \n", &prog2);
    scanf("%s", buff);
}

int prog2(void) {
    printf("Success");
    return (1);
}

int main() {
  //  printf("prog1: 0x%X\nprog2: 0x%X\nmain: 0x%X\n", &prog1, &prog2, &main);
    prog1();
    printf ("return to main\n");
    return 0;
}
//123456789012345678901234
