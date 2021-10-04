#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ttt=0;

    for(int i=0; i<argc; i++)
    {
        ttt=ttt+atoi(argv[i]);
    }
    printf("%d\n", ttt);
}