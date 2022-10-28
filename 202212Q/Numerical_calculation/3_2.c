// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 3-2

#include <stdio.h>

int main() {
    long i;
    double x;

    union {
        double f;
        long i;
    } a;

    scanf("%lf", &x);
    a.f = x;
    /*printf("%lf\n",a.f);
    printf("%ld\n",a.i);
    for(int i = 63; i >= 0; i--) {
        printf("%ld", (a.i >> i) & 1);
    }
    printf("\n");*/

    printf("%ld / ", (a.i >> 63) & 1);

    for (i = 62; i >= 52; i--) {
        printf("%ld", (a.i >> i) & 1);
    }

    printf(" / ");

    for (i = 51; i >= 0; i--) {
        printf("%ld", (a.i >> i) & 1);
    }

    printf("\n");

    return 0;
}