/* Integer power
 * Author: Garifullina Guzel, 171 group */


#include <stdio.h>

int main(void) {
   int base, power;
   printf("Введите число и степень(в которую вы хотите возвести) \n");
   scanf("%d%d",&base,&power);

   printf("Число %d в %d -ой степени ", base, power);
   //case when number=0
   if (base == 0)
   {   printf ( "0 \n" );
       return(0);
   }


   double product = 1 ;
   int current = base;

   //case with negative power
   int negative = (power<0);
   if (negative)
   {    power = -power;
   }

   // find the product for positive numbers using binary exponentiation
   for ( ; power > 0 ; power = power >> 1)
   {    if ((power & 1) == 1)
        {   product = product * current ;
        }
       current = current * current ;

   }



   //check if power was negative, and in that case change it to inverse number
   if (negative)
       {   printf ("%e \n" , 1 / product );
       }

   else
   {   printf("%e \n" , product );
   }
return 0;
}
