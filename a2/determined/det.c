#include <stdio.h>
#include <stdlib.h>


double compute_det(int **a, int n) {

    double ttt = 0;
    double aa = 1;
    if (n == 1) {return (double)a[0][0];}

    int j = 0;
    while (j < n){

        int **memory = malloc((n - 1) * sizeof(int*));
        int small_R = 0;

        for (int ff=1; ff < n; ff++) {

            int small_C = 0;
            memory[small_R] = malloc((n - 1) * sizeof(int));

            int cc = 0;
            while ( cc < n ){
                if (j == cc) {
                    cc++;
                }
                memory[small_R][small_C] = a[ff][cc];
                small_C++;
                cc++;
            }
            small_R++;
        }
        ttt += (aa * a[0][j] * compute_det(memory, n - 1));
        aa = aa * -1;
        free(memory);
        j++;
    }
    return ttt;
}

int main(void) {
    int ab;

    scanf("%d", &ab);
    int **num = malloc(ab * sizeof(int*));
    int i1 = 0;
    while (i1< ab){
        num[i1] = malloc(ab * sizeof(int));

        for (int i2=0; i2 < ab; i2++) {
            scanf("%d", &num[i1][i2]);
        }
        i1++;
    }
    printf("%0.5f\n", compute_det(num, ab));
    free(num);
}

