#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *inData(FILE *fp, size_t amount) {

    int as;
    size_t bb = 0;
    char *string;
    string = realloc(NULL, sizeof(*string) * amount);//amount is start amount
    if (!string){
        return string;
    }
    while (as != '\n' && EOF != (as = fgetc(fp))) {
        string[bb++] = as;
        if (bb == amount) {
            string = realloc(string, sizeof(*string) * (amount += 16));
            if (!string){
                return string;
            }
        }
    }
    string[bb++] = '\0';
    return realloc(string, sizeof(*string) * bb);
}


void spacePlace(char *c, int empty) {
    int num = 0;
    char tb = '\t';

    for(int f = 0; c[f] != '\0'; f++){

        if (c[f] == ' ') {
            num += 1;
            if (num == empty) {
                printf("%c", tb);
                num = 0;
            }
        } else {
            if (num > 0) {
                int b = 0;
                while ( b < num){
                    printf(" ");
                    b++;
                }
            }
            num = 0;
            printf("%c", c[f]);
        }
    }
}

void change(char *c, int empty) {
    char sp = ' ';
    for( int i = 0; c[i] != '\0'; i++){
        if (c[i] != '\t') {
            printf("%c", c[i]);
        } else {
            int j = 0;
            while ( j < empty){
                printf("%c", sp);
                j++;
            }
        }
    }
}

int main(int argc, char *ttt[]) {
    char *bigData;
    if ( strcmp(ttt[1], "-e") == 0 || strcmp(ttt[1], "-d") == 0){

        int num = atoi(ttt[2]);
        bigData = inData(stdin, 10);

        if (strcmp(ttt[1], "-d") != 0) {
            spacePlace(bigData, num);
        } else {
            change(bigData, num);
        }
        free(bigData);
    } else {
        printf("error");
    }
    return 0;
}