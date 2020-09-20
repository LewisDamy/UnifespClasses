// Make a Program that asks for a date in the format dd / mm / yyyy and determine if it is a valid date.

#include <stdio.h>

int main(void)
{
    int day, month, year;
    
    printf("Type a date in the format dd mm yyyy: ");
    scanf("%i %i %i", &day, &month, &year);
    
    if(month == 2.0) //Prar o mes de fevereiro(2)
    {
        // veja se e bissexto e se nao e maior que 29
        
        if(year % 4 ==0) // se for bissexto
        {
            if(day < 30) // termina em 29
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
        else // se nao for bissexto 
        {
            if(day < 29) // termina em 28
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
    }
    else if(month > 1 || month != 2.0 || month < 9) //para meses de Janeiro(1), Marco(3), Abril(4), Maio(5),  Junho(6), Julho(7), Agosto(8)
    {
        // Se os meses forem 04, 06 terminam no dia 30, se for 01, 03, 05, 07, 08 termina no dia 31
        
        if(month % 2 == 0 % month != 8) // se o mes for 04, 06
        {
            if(day < 31)
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
        else // se o mes for 01, 03, 05, 07, e 08
        {
            if(day < 32) // termimnar em 30
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
        else //se o mes for 01, 03, 05, 07 e 08
        {
            if(day < 32) // terminar em 31
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
    }
    
    else if(month > 8 && month < 13) // para meses de Setembro(9), Outubro(10), Novembro(11), Dezembro(12)
    {
        // se os meses forem Setembro(09), Novembro(11) terminamno dia 30 e se forem Outubro(10), Dezembro(12) termina no dia 31
        
        if(month % 4 == 0) // se o mes for 10, 12
        {
            if(day < 32) // terminar no dia 31
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
        else // se o mes for 09, 11
        {
            if(day < 31) // terminar no dia 30
            {
                printf("Valid Date\n");
            }
            else
            {
                printf("Invalid Date\n");
            }
        }
    }
    else
    {
        printf("Invalid Date\n");
    }
}