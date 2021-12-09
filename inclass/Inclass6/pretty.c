#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ttt=fopen("C:\\Users\\uSeR\\Desktop\\sysskill\\input .txt","r");

    int num;
    printf("================================\n");
    char c[10];
    while((fscanf(ttt, "%s\t %d", c, &num))!=EOF)
    {
        if(num>=10 && num<=100)
        {
            printf("%-15s %d%d\n", c, 0, num);
        }
        else
        {
            printf("%-15s %d\n", c, num);
        }
    }
    printf("================================\n");

}