#include <stdio.h>

int main()
{
    int i,num,result= 1;
    printf("Enter a number: ");
    scanf("%d",&num);

    for (i = 1; i <= num ; i++)
        result *= i;
    printf("Factorial of %d is %d\n",num,result);
}