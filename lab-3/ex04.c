#include <stdio.h>

char grade(int avg)
{
    if(avg >= 80)
        return('A');
    else if (avg >= 70 && avg < 80)
        return('B');
    else if (avg >= 60 && avg < 70)
        return('C');
    else if (avg >= 50 && avg < 60)
        return('D');
    else if (avg < 50)
        return('F');
}

int main()
{
    char name[20];
    int Cal, Phy, Com;
    float avg;

    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your Calculus score: ");
    scanf("%d",&Cal);
    printf("Enter your Physic score: ");
    scanf("%d",&Phy);
    printf("Enter your Computer programming score: ");
    scanf("%d",&Com);

    avg = (Cal + Phy + Com) / 3.0;

    printf("%s, your average is %.2f. You got grade %c\n",name , avg , grade(avg));

}