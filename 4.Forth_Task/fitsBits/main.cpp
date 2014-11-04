#include <stdio.h>

int main(void) {
    //reading n
    int n,k;
    printf("Проверка вхождения n в k бит \n");
    printf(" Введите числа n и k ");
    scanf("%d %d",&n, &k);

    int numOfBinDigits = sizeof(n)*8;

    int shift = numOfBinDigits - k ; //first numbers that can overload k bits

    printf("%d", !( (n << shift) >>shift ^ n  ));

    printf("\n");

return 0;

}
