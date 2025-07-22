#include <stdio.h>

int main()
{
    int num_1,num_2;
    printf("Enter a number: ");
    scanf("%d",&num_1);
    printf("Enter a number: ");
    scanf("%d",&num_2);

    if(num_1 != num_2)
    {
        printf("Does not macth. Try again\n");
    }

    else if(num_1 == num_2)
    {
        printf("Match\n");
    }
}