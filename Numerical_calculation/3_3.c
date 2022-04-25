// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 3-3

#include <stdio.h>

void binary64(double x) {
    int i;

    union {
        double f;
        long i;
    } a;

    a.f = x;

    printf("%ld / ", (a.i >> 63) & 1);

    for(i = 62; i >= 52; i--) {
        printf("%ld", (a.i >> i) & 1);
    }

    printf(" / ");

    for(i = 51; i >= 0; i--) {
        printf("%ld", (a.i >> i) & 1);
    }

    printf("\n");
}

int main() {
    double x = 1;

    while(x != 0) {
        printf("%12g   ", x);
        binary64(x);
        x /= 2;
    }

    printf("%12g   ", x);
    binary64(x);
}