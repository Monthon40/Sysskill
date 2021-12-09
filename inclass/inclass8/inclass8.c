#include<stdio.h>
#include<stdlib.h>

void typed(int **b, int sizex, int sizey){

    for(int ff=0; ff < sizex; ff++){
        printf("| ");
        int bb = 0;
        while (bb < sizey){
            printf("%d",*(*(b + ff) + bb));
            if(bb == sizey - 1){
                printf(" | \n");
            }
            else{
                printf(", ");
            }
            bb++;
        }
    }
}

void transpose (int **a, int **b, int sizex, int sizey){

    for(int i =0;i<sizex;i++){
        int j = 0;
        while ( j < sizey){
            *(*(b+j)+i) = *(*(a+i)+j);
            j++;
        }
    }
}

int main(){

    int **xx = malloc(sizeof(int*) * 2);
    int **yy = malloc(sizeof(int*) * 3);

    for(int a = 0; a < 2; a++){
        *(xx + a) = malloc(sizeof(int) * 3);
        int b = 0;
        while ( b < 3){
            *(*(xx + a) + b) = b + a + b;
            b++;
        }
    }
    for(int i = 0; i< 3;i++){
        *(yy + i) = malloc(sizeof(int) * 2);
        int j = 0;
        while ( j < 2){
            *(*(yy + i) + j) = 0;
            j++;
        }
    }

    transpose(xx, yy, 2, 3);
    typed(xx, 2, 3);
    typed(yy, 3, 2);

}