/* FitsBits
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>

int main(void) {
    //reading num
    int num , kBIT;
    printf("Проверка вхождения num в k бит \n");
    printf("Введите числа num и k \n");
    scanf("%d %d",&num , &kBIT);



    int  maskPOS = 0x80000000;
    int top =  !! (maskPOS & num) ;


    const int numOfBinDigits = sizeof(num)*8;
    int shift = numOfBinDigits - kBIT  ; //first numbers that can overload k bits
    maskPOS >>= shift;// put 1 to bits that should be free
    int ansPOS =  !(maskPOS & num);//answer for positive


    int unsigned maskNEG = 0xffffffff  ;
    maskNEG <<= kBIT -1; // free bits that can be used
    int ansNEG = ! ((num | maskNEG ) ^ num);//answer for negative
    printf("%d \n", (1 + top)  * ansPOS + top * ansNEG);

return 0;

}
