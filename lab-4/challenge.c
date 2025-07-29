#include <stdio.h>

int main()
{
    float amount = 0 , y;
    int x;
    do
    {
        printf("====== ATM MENU ======\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                printf("Current Balance: %.2f\n",amount);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f",&y);
                if (y >= 0)
                    amount += y;
                else
                    break;
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f",&y);
                if (y >= 0)
                    amount -= y;
                else
                    break;
                printf("Withdrawal successful.\n");
                break;
            case 4:
                break;
            default:
                break;
        }
        printf("\n");
    }while (x !=4 && (x>= 1 && x<= 3));
    if(x == 4)
        printf("Thank you for using the ATM.\n");
    else if (x > 4 || x < 1)
        printf("Error\n");
}