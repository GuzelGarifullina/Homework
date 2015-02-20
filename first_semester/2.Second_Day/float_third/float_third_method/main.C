/* Second homework, float representation with bit fields
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
        { if (!floatnum.sign) // sign
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
      if (!floatnum.sign)
        { floatnum.sign = 1;
        }
        else
           { floatnum.sign = -1;
           }
      printf ("%d×%f×2^%d \n", floatnum.sign, (1 + ((float)(floatnum.coefficient) / 0x800000)), floatnum.exponent - 127);
      return(0);
    }

int main (void)
 { union Transfer
    { float floatnum;
     struct
        { unsigned int coef : 23;
          unsigned int exp : 8;
          unsigned int sigh : 1;
        };
    } num;
    float num1,num2;
    printf("Введите 2 числа ");
    scanf("%f %f", &num1, &num2);
    num.floatnum = num1 / num2;
    // division num
    FloatNum floatnum;
    floatnum.coefficient = num.coef;
    floatnum.exponent =  num.exp;
    floatnum.sign = num.sigh;
    print (floatnum);

    return (0);
  }
