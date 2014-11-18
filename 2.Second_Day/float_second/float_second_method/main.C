/* Second homework, float representation with union
 * Author: Garifullina Guzel, 171 group */
#include <stdio.h>

struct FloatNum
    { int sign;
      int exponent;
      int coefficient;
    };

int print (FloatNum floatnum)
    { printf ("The float number is ");
      const int maxEXP = 255; // 2^8 - 1

      //NULL
      if ((floatnum.exponent == 0) && (floatnum.coefficient == 0))
        { printf ("0\n");
          return (0);
        }

      // Infinity
      if ((floatnum.exponent == maxEXP) && (floatnum.coefficient == 0))
        { if (floatnum.sign) // sign
            printf ("+∞ \n");
          else  printf ("-∞ \n");
          return (0);
        }

      //NaN
      if ((floatnum.exponent == maxEXP) && (floatnum.coefficient != 0))
        { printf (" NaN \n");
          return (0);
        }

      // Normal number
      printf ("%d×%f×2^%d \n", floatnum.sign, (1 + ((float)(floatnum.coefficient) / 0x800000)), floatnum.exponent - 127);
      return(0);
    }
void division (int num)
    { FloatNum floatnum;
      floatnum.sign = - (num >> 31 & 1);
      if (! floatnum.sign)
        { floatnum.sign = 1;
        }
      const int mask = 0xff ; // to take only last 8 numbers (size of exponent is 8 bits)
      floatnum.exponent = (num >> 23) & mask;
      const int mask2 = 0x7fffff; //last 23 bits
      floatnum.coefficient = num & mask2;
      print (floatnum);
    }

int main (void)
 {  union
       { int  IntNum ;
         float FloatNum;
       } num;
    float num1, num2;
    printf("Введите число ");
    scanf("%d %f", &num.IntNum, &num2);
    //num1 = num1 / num2;
    //num.IntNum = num1;
    printf ("%d", num.IntNum);
   // division(num.IntNum );


       return (0);
  }
