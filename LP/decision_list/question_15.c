// Make a Program that asks for the 3 sides of a triangle. The program should inform if the values ​​can be a triangle. Indicate, if the sides form a triangle, if it is: equilateral, isosceles or scalene.
// Tips:
//      Three sides form a triangle when the sum of any two sides is greater than the third;
//      Equilateral Triangle: three equal sides;
//      Isosceles Triangle: any two equal sides;
//      Scalene Triangle: three different sides;




#include <stdio.h>

int main(void)
{
    float, num1, num2, num3, sum1, sum2, sum3;
    
    printf("Type 3 numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    sum1 = num2 + num3;
    sum2 = num1 + num3;
    sum3 = num1 + num2;
    
    if(sum1 > num1 || sum2 > num2 || sum3 > num3)
    {
        if(num1 < 0 && num2 < 0 && num3 < 0)
        {
            printf("These v avlues can be an triangle\n");
        }
        if(num1 == num2 && num2 == num3 && num1 == num3)
        {
            printf("These triangle with sides %.1f, %.1f and %.1f make an Equilateral Triangle\n", num1, num2, num3);
        }
        else if(num1 == num2 || num2 == num3 || num1 == num3)
        {
            printf("These triangle with sides %.1f, %.1f and %.1f make an Isosceles Triangle\n", num1, num2, num3);
        }
        else
        {
            printf("These triangle with sides %.1f, %.1f and %.1f make an Scalene Triangle\n", num1, num2, num3);
        }
    }
    else
    {
        printf("The three number typed do not make an triangle\n");
    }
}