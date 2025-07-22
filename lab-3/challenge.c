#include <stdio.h>

char G(int avg)
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

float num_G(int avg)
{
    if(avg >= 80)
        return(4.0);
    else if (avg >= 70 && avg < 80)
        return(3.0);
    else if (avg >= 60 && avg < 70)
        return(2.0);
    else if (avg >= 50 && avg < 60)
        return(1.0);
    else if (avg < 50)
        return(0.0);
}

float grade(int num_sub)
{
    int i = 0;
    float avg;
    char subject[11][15];
    int score[11];
    while(i < num_sub)
    {
        printf("Enter subject %d: ",i+1);
        scanf("%s",subject[i]);

        printf("Enter %s score: ",subject[i]);
        scanf("%d",&score[i]);

        printf("\n");

        i++;
    }
    i = 0;
    int sum = 0;
    while(i < num_sub)
    {
        sum = sum + score[i];
        i++;
    }
    avg = sum/num_sub;

    printf("Subject        Score     Grade     Grade\n");
    printf("------------------------------------------\n");
    i=0;
    while(i < num_sub)
    {
        printf("%s          %d        %c        %.2f\n", subject[i] , score[i], G(score[i]) , num_G(score[i]));
        i++;
    }
    printf("\n%.2f",avg);
    

}

int main()
{
    int num_sub;
    printf("Enter number of subjects (max 10): ");
    scanf("%d",&num_sub);
    if (num_sub >= 1 && num_sub <=10)
        printf("%f",grade(num_sub));

}