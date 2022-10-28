// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 3-4

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
}

int main() {
    double x = 1;

    while(1 + x != 1) {
        printf("%56.55f  %56.55f ", x, 1 + x);
        binary64(x);
        printf(" ");
        binary64(1 + x);
        printf("\n");
        x /= 2;
    }

    printf("%56.55f  %56.55f ", x, 1 + x);
    binary64(x);
    printf(" ");
    binary64(1 + x);
    printf("\n");
}