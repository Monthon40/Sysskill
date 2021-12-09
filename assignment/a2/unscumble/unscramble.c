#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(const void *y, const void *b) {
    return strcmp(y, b);
}


int main(int argc, char *argv[]) {

    char **dictionar = malloc(500000 * sizeof(char*));
    char **dictionar_S = malloc(500000 * sizeof(char*));
    int ttt = 50;
    char var[ttt];
    char y[ttt];

    (void) argc;

    FILE *jb;
    jb = fopen(argv[2], "r");

    FILE *dic;
    dic = fopen(argv[1], "r");


    int cap = 0;

    for(int i = 0; fgets(y,ttt,dic) ; i++){

        if (y[strlen(y) - 1] == '\n') {y[strlen(y) - 1] = '\0';}

        dictionar[i] = malloc(ttt * sizeof(char));
        dictionar_S[i] = malloc(ttt * sizeof(char));
        strcpy(dictionar[i], y);
        strcpy(dictionar_S[i], y);
        qsort(dictionar_S[i], strlen(dictionar_S[i]), sizeof(char), helper);
        cap++;
    }
    fclose(dic);

    while(fgets(var, ttt, jb)) {

        if (var[strlen(var) - 1] == '\n') { var[strlen(var) - 1] = '\0';}

        printf("%s:", var);
        qsort(var, strlen(var), sizeof(char), helper);

        int num = 0;
        int jj = 0;
        while ( jj < cap){

            if (strcmp(dictionar_S[jj], var) == 0) {
                printf(" %s", dictionar[jj]);
                num++;
            }
            jj++;
        }
        if (num == 0){
            printf(" NO MATCHES");
        }
        printf("\n");
    }
    fclose(jb);
    free(dictionar);
    free(dictionar_S);
}

