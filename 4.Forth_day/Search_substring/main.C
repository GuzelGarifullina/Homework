/* The forth task, count the amount of occurance one string in another
 * Author: Garifullina Guzel, 171 group */

#include <stdio.h>
#include <string.h>

struct String
{ char STR[2000];
  int Length;
};


int main(void) {
    //reading n
    String origin, sub;
    printf("Введите стороку и построку \n");
    fgets (origin.STR, 2000, stdin );
    fgets (sub.STR, 2000, stdin);

    // Fix origin and sub
    origin.Length = strlen( origin.STR ) - 1; //cause here will be additional elem = "/n"
    origin.STR [origin.Length] = '\0';
    //sub
    sub.Length = strlen( sub.STR ) - 1; //cause here will be additional elem = "/n"
    sub.STR [sub.Length] = '\0';
    printf("Количество вхождений строки '%s' в строку '%s'' = ", sub.STR, origin.STR);

    //main part
    //case with empty lines
    if ( (origin.Length == 0) || (sub.Length == 0) )
    {   printf("0\n");
        return(0);
    }

    int amt = 0; //amout of occurance
    const int boarder = origin.Length - sub.Length;
    sub.Length --; //without /0
    const char firstchar = sub.STR[0]; // of subline
    int indicator = 1;

    for ( int i = 0; i<= boarder; i++)
    {   if (origin.STR[i] == firstchar) //if first symbols the same then continue comparing
        {   for ( int j = 1; j <= sub.Length; j++ )
            {   if (origin.STR[i+j] != sub.STR[j])
                {   indicator = 0;
                    break;
                }
             }
            if (indicator) //mean that cycle ended without break (i.e. subline of origin = sub)
            {   amt++;
            }
                else
                {   indicator = 1;
                }
        }
    }

    printf("%d\n", amt);
    return (0);

}










