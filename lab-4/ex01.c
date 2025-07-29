#include <stdio.h>

int main()
{
    int num,result = 0;
    float avg;
    for(int i =1;i<=10;i++)
    {
        printf("%d.Enter the number : ",i);
        scanf("%d",&num);
        printf("\n");
        result += num;
    }
    printf("total sum is %d\n",result);
    avg = result/10;
    printf("Average is %.2f",avg);
}