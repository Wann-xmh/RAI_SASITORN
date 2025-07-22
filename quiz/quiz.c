#include <stdio.h>

float radius,Resistivity;
int L;
int main()
{
    printf("Enter radius of Resistor (m) : ");
    scanf("%f",&radius);
    printf("Enter Length of resistor (m) : ");
    scanf("%d",&L);
    printf("Enter Resistivity of Resistor : ");
    scanf("%f",&Resistivity);

    float R = (Resistivity * L) / (3.14 *radius*radius);

    printf("The value of this resistor = %f OHM\n",R);


}