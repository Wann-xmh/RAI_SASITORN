#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter the first value : ");
    scanf("%d",&a);
    printf("Enter the second value : ");
    scanf("%d",&b);
    printf("Enter the third value : ");
    scanf("%d",&c);
    d = a+b+c;
    printf("%d = %d + %d + %d\n",d,a,b,c);
    return 0 ;
    // printf("My name is : %s\n","Sasitornja");
    // printf("My ID : %d\n",101);
    // printf("My score : %d\n",30+39+90);
    // printf("Expected Grade : %c\n",'A');
    // printf("Expected GPA of 1/2025 : %f",4.00);

    // printf("Name = %s,ID=%s\n","PROGRAM","68011509");
    // printf("Department : %s","Robotics and AI");
    // printf("\nAge = %d ,GPA = %f\n",18,4.00);
    // printf("CPrograming : %.1f\nRobotics : %.2f\n",4.0,3.99);

    return 0 ;
}