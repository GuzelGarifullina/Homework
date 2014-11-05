#include <stdio.h>

int main(void) {
    //reading n
    int number;
    printf("Введите число ");
    scanf("%d",&number);

    int numOfBinDigits = sizeof(number)*8;

    //writing
    printf ( "Двоичная запись числа %d", number );
    printf (" = ");

    // the case when number=0
    if (number == 0)
    {   printf("0");
        return(0);
    }

    //skip nulls
    int i=1;
    for ( ; (number >> ( numOfBinDigits - 1 ) & 1) ==0; number = number << 1 )
    {   i=i+1;
    }
    for (; i<=numOfBinDigits ; ++i )
    {   printf("%d", number >> ( numOfBinDigits - 1 ) & 1);
        number = number << 1;
    }
    printf("\n");

return 0;

}
