 #include <stdio.h>

 int main(void) {
    int base, power;
    printf("Введите число и степень(в которую вы хотите возвести) \n");
    scanf("%d%d",&base,&power);

    printf("\n Число %d в %d -ой степени ", base, power);
    //case when number=0
    if (base==0)
    {   printf ("%d" , 0);
        return(0);
    }


    double sum=1;
    int currentnumber=base;

    //case with negative power
    bool negative=(power<0);
    if (negative)
    {    power=-power;
    }

    // find the sum for positive numbers
    for (;power>0; power=power>>1)
    {    if ((power&1) == 1)
         {   sum=sum*currentnumber;
         }
        currentnumber=currentnumber*currentnumber;

    }



    //check if power was negative, and in that case change it to inverse number
    if (negative)
        {   printf ("%e" , 1/sum);
        }

    else
    {   printf("%e" , sum );
    }
 printf("\n");
 return 0;
}
