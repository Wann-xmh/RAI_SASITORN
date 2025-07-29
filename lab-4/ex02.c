#include <stdio.h>

int main()
{
    int i=1 , result = 0,num;
    while (i <= 10)
    {
        printf("%d.Enter the number : ",i);
        scanf("%d",&num);
        printf("\n");
        result += num;
        i++;
    }
    printf("Total sum is %d\n",result);
}