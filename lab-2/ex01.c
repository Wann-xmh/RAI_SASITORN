#include <stdio.h>

int main()
{
    int a;
    float b;
    char c;
    printf("%s","Please enter an integer value: ");
    scanf("%d",&a);
    printf("You entered %d\n",a);
    printf("%s","Please enter an float value: ");
    scanf("%f",&b);
    printf("You entered %f\n",b);
    printf("%s","Please enter a character: ");
    scanf(" %c",&c);
    printf("You entered %c\n",c);
}