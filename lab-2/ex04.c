#include <stdio.h>

int main()
{
    char name[20],id[9];
    float pro,phy,cal,GPA;

    printf("Enter your Name: ");
    scanf("%s",name);
    printf("Enter your student ID: ");
    scanf("%s",id);
    printf("Enter your Programming score: ");
    scanf("%f",&pro);
    printf("Enter your Physics score: ");
    scanf("%f",&phy);
    printf("Enter your Calculus score: ");
    scanf("%f",&cal);
    GPA = (pro + phy + cal)/3;
    printf("Hi %s(%s)! Your GPA is %.2f\n",name,id,GPA);
}