#include <stdio.h>

int main()
{
    int r,h;
    float volume;
    printf("Enter cone hight: ");
    scanf("%d",&h);
    printf("Enter cone base radius: ");
    scanf("%d",&r);

    volume = 3.14*r*r*h/3;
    printf("Cone volume = %.1f\n\n",volume);
    if(volume > 260)
        printf("This cone is perfect for Supun project\n");
    else
        printf("This cone is not fit for this project\n");

}