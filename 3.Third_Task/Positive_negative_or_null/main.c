#include <stdio.h>

int main(void) {
    //reading n
    int number;
    printf("Введите число ");
    scanf("%d",&number);

    int numOfBinDigits = sizeof(number)*8;

    int heap = number >> ( numOfBinDigits-1);
    int heap2= (number -1)  >> ( numOfBinDigits-1);


    printf("%d", heap + (heap + 1) * (heap2 + 1));

    printf("\n");

return 0;

}
