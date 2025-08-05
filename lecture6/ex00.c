#include <stdio.h>

int main()
{
    int i=0,x=0,size;
    printf("Enter your size of a square : ");
    scanf("%d",&size);

    for (i=0;i<size;i++)
    {
        for(x=0;x<size;x++)
            printf("0");
        printf("\n");
    }
}