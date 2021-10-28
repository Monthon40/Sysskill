#include <stdio.h>
#include <malloc.h>

void dotProduct(int *a, int *b, int size, int *result)
{
    int* ttt = malloc(sizeof(int) * size);
    int all=0;

    int i = 0;
    while (i < size){
        ttt[i] = a[i] * b[i];
        i++;
    }
    int j = 0;
    while ( j < size){
        all+= ttt[j];
        j++;
    }
    *result = all;
    free(ttt);
}

void main(){
    void (*pFunction)(int *, int *, int , int *) = &dotProduct;
    int a[3] = {3, -4, 7};
    int b[3] = {-2, -6, 10};
    int c;

    int *aa = &a; int *bb = &b; int cc = &c;
    (pFunction)(aa, bb, 3, cc);
    printf("%d", c);
}
