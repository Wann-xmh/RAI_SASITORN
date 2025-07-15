#include <stdio.h>

int check_max(int num_1,int num_2,int num_3)
{
    int max;
    if(num_1>num_2 && num_1>num_3)
    {
        max = num_1;
    }
    else if(num_2>num_1 && num_2>num_3)
    {
        max = num_2;
    }
    else if(num_3>num_1 && num_3>num_2)
    {
        max = num_3;
    }
    return (max);
}

int check_min(int num_1,int num_2,int num_3)
{
    int min;
    if(num_1<num_2 && num_1<num_3)
    {
        min = num_1;
    }
    else if(num_2<num_1 && num_2<num_3)
    {
        min = num_2;
    }
    else if(num_3<num_1 && num_3<num_2)
    {
        min = num_3;
    }
    return (min);
}

int main()
{
    int num_1, num_2,num_3;
    float avg;

    printf("Enter integer #1: ");
    scanf("%d",&num_1);
    printf("Enter integer #2: ");
    scanf("%d",&num_2);
    printf("Enter integer #3: ");
    scanf("%d",&num_3);
    printf("Result:\n");
    printf("Minimum: %d\n" ,check_min(num_1,num_2,num_3));
    printf("Maximum: %d\n" ,check_max(num_1,num_2,num_3));
    printf("Sum: %d\n",num_1+num_2+num_3);
    avg = (num_1+num_2+num_3)/3;
    printf("Average: %.2f\n",avg);


}