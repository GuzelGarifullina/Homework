/* Number sign
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>

int main(void)
{
    //reading n
    int number;
    printf("Введите число ");
    scanf("%d",&number);

    const unsigned int mask = 0x80000000 ; //to take top number

    int top = !! (number & mask ) ;
    int top2 = !! ((number -1)  & mask) ;
    printf("%d \n", -  top  + ((1 - top ) & (1 - top2 )));

return 0;

}
