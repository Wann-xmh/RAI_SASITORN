#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(num >= 1 && num <= 100)
    {
        if(num % 2 == 0)
            printf("%d is even\n",num);
        else
            printf("%d is odd\n",num);
    }
    else{
        printf("%d is out of range\n",num);
    }
}