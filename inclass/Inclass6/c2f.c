#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float change(float temp){
    return (temp * 9/5)+32;
}

int main()
{
    int ttt;
    int rrr;

    printf("Enter lower limit: ");
    scanf("%d", &ttt);
    printf("Enter upper limit: ");
    scanf("%d", &rrr);

    printf("%-15s %s\n", "Celcius","Farenheit");
    printf("=========================\n");

    for(float i=ttt; i<=rrr; i=i+5){
        printf("%-15 0.0f %0.1f\n",i, change(i));
    }
    
    printf("-------------------------");
}