#include <stdio.h>

int decimalToBinary(int dec) {
    int num = 0;
    int yot = 1;
    int ple = 1;

    while (dec != 0) {
        yot = dec % 2;
        dec = dec / 2;
        num = num + yot * ple;
        ple = ple * 10;
    }
    return num;
}

int checkP(int x) {

    long trt = decimalToBinary(x);
    printf("%d" ,trt);
    int aa = 0;
    int i1 = 0;
    while (i1 < 4 ){
        if (trt & 1) {
            aa++;
        }
        trt >>= 1;
        i1++;
    }
    if (aa % 2 != 0) {
        return 1;
    }
    return 0;
}

void main() {

    printf("%d\n", checkP(12));
    printf("%d\n", checkP(11));
    printf("%d\n", checkP(13));
    printf("%d\n", checkP(5));
    printf("%d\n", checkP(7));
}