#include <stdio.h>

int main()
{
    char name[20],uni_name[20];
    int age;
    float height;
    printf("Enter your full name: ");
    scanf("%[^\n]",name);
    printf("Enter your age: ");
    scanf("%d",&age);
    printf("Enter your height: ");
    scanf("%f",&height);
    printf("Enter your University name: ");
    scanf("%s",uni_name);
    printf("\nHi! Everyone. This is K.%s from %s. I am %d years old and my height is %.1f cm tall.",name,uni_name,age,height);
}