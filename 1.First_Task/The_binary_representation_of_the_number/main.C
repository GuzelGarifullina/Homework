/* The binary representation of the number
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>


int main(void) {
    //reading n
    int number;
    printf("Введите число ");
    scanf("%d",&number);

    const int numOfBinDigits = sizeof( int )*8;
    int unsigned mask = 0x80000000;


    //writing
    printf ( "Двоичная запись числа %d = ", number );

    for ( int i = numOfBinDigits - 1 ; i >= 0 ; --i )
    {   printf("%d" , !! (mask & number) );
        mask >>= 1;
    }
    printf("\n");


return 0;

}
