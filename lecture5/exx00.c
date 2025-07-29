#include <stdio.h>

int main()
{
    char name[22];
    int i , result , num = 0;
    // printf("Enter final number : ");
    // scanf("%d",&num);
    // do
    // {
    //     result += num;
    //     num++;
    // }while(num <= 100);
    // printf("%d \n",result);
    for(i=0;i<=100;i+=2)
        result += i;
    printf("%d\n",result);
}