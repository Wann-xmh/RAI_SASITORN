#include <stdio.h>

int Num1, Num2 , Calculator_menu , Result;
char calculator;

int main ()
{
    printf("Enter Num1 : ");
    scanf("%d",&Num1);
    printf("Enter Num2 : ");
    scanf("%d",&Num2);
    printf("Calculator menu : \n");
    printf("1. +\n");
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");
    printf("Choose menu : ");
    scanf("%d",&Calculator_menu);

    switch(Calculator_menu)
    {
        case 1 :
            Result = Num1 + Num2;
            calculator = '+';
            break;
        case 2 :
            Result = Num1 - Num2; 
            calculator = '-';
            break;
        case 3 :
            Result = Num1 * Num2;
            calculator = '*';
            break;
        case 4 :
            Result = Num1 / Num2;
            calculator = '/';
            break;
        default:
            break;
    }
    printf("Ans : Num1 %s Num2 = %d\n",&calculator,Result);

}