#include <stdio.h>

int main()
{
    char name[20];
    int age,weight;
    float height;
    char gender[10];
    char edu[20];
    printf("%s","Enter your Name: ");
    scanf("%s",name);
    printf("%s","Enter your Age: ");
    scanf("%d",&age);
    printf("%s","Enter your height: ");
    scanf("%f",&height);
    printf("%s","Enter your weight: ");
    scanf("%d",&weight);
    printf("%s","Enter your gender: ");
    scanf("%s",gender);
    printf("%s","Enter your Education Qualification: ");
    scanf("%s",edu);

    printf("\nName: %s\t Age: %d\t Gender:%s\n",name,age,gender);
    printf("Height: %f\t Weight: %d\n",height,weight);
    printf("Education: %s\n",edu);
}