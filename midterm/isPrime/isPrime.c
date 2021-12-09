#include <stdio.h>

int IsPrime(int n) {

    if (n < 2) return 0;
    else {
        int cnt = 0;

        int i = 1;
        while (i <= n){
            if (n % i == 0){
                cnt += 1;
            }
            i++;
        }
        if (cnt == 2){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main() {
    printf("%d\n", IsPrime(97));
    printf("%d\n", IsPrime(3));
    printf("%d\n", IsPrime(14));
    printf("%d\n", IsPrime(6));
    return 0;
}