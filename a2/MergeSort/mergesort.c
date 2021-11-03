#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int aa,bb = 0;
    for( int ff = 0; ff < nL + nR; ff++){
//    while (ff < nL + nR){
        if (nR <= bb || (L[aa].data < R[bb].data && nL > aa)){
//        if ((aa < nL && L[aa].data < R[bb].data) || bb >= nR ){
            output[ff] = L[aa];
            aa++;
        } else{
            output[ff] = R[bb];
            bb++;
        }
    }
}

void merge_sort(Entry *entries, int n) {
    if (n > 1){
        int mid = n / 2;
        int left, right = 0;
        Entry * L = malloc(n*sizeof(Entry));
        Entry * R = malloc(n*sizeof(Entry));
        int j = 0;
        while ( j < mid ){
//        for(int i = 0; i < mid; i++){
            L[j] = entries[j];
            left++;
            j++;
        }
        int t = mid;
        while ( t < n ){
//        for(int i = mid; i < n; i++){
            R[right] = entries[t];
            right++;
            t++;
        }
        merge_sort(L, left);
        merge_sort(R, right);

        Entry * ttt = malloc(n * sizeof(Entry));
        merge(ttt, L, left, R, right);
        int i = 0;
        while( i < n) {
            entries[i] = ttt[i];
            i++;
        }

        free(ttt);
        free(L);
        free(R);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int size,var;

    scanf("%d", &size);
    Entry* varIn = malloc;  //malloc, free at size 123
    malloc(size * sizeof (Entry));

    char string1[MAX_NAME_LENGTH];
    int i = 0;
    while ( i < size){
//    for(int i = 0; i < size; ++i){
        scanf("%d %s", &var, string1);
        varIn[i].data = var;
        varIn[i].name = malloc(MAX_NAME_LENGTH); //malloc, free at 119-121
        strcpy(varIn[i].name, string1);
        ++i;
    }
    merge_sort(varIn, size);
    for(int r = 0; r < size ; ++r){
        printf("%d %s\n", varIn[r].data, varIn[r].name);
    }
    int f = 0;
    while ( f < size ){
//    for(int i =0; i < size ; ++i){
        free(varIn[i].name);
        ++i;
    }
    free(varIn);
    return 0;
}