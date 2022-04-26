// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 2-5

#include <stdio.h>
#include <stdlib.h>
#define fac19 121645100408832000L

long gcd(long x, long y) {
    if(y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

long binomial(int n, int k) {
    return (k == 0) ? 1 : binomial(n - 1, k - 1) * n / k;
}

long b(int k, int m) {
    if(k == 0) {
        return fac19 / m;
    } else {
        return m * (b(k - 1, m) - b(k - 1, m + 1));
    }
}

int main() {
    int n, k;
    long g;
    long num, den;
    long bn[20], bd[20];

    for(k = 0; k < 20; k++) {
        g = gcd(labs(b(k, 1)), fac19);
        bn[k] = b(k, 1) / g;
        bd[k] = fac19 / g;
    }

    scanf("%d", &k);

    printf("1/%d ( n^%d", k + 1, k + 1);
    for(int j = 1; j <= k; j++) {
        g = gcd(labs(binomial(k + 1, j) * bn[j]), bd[j]);
        num = binomial(k + 1, j) * bn[j] / g;
        den = bd[j] / g;

        if(num != 0) {
            if(num > 0) {
                printf(" + ");
            } else if(num < 0) {
                printf(" - ");
            }

            if(den != 1) {
                printf("%ld/%ld n^%d", labs(num), den, k + 1 - j);
            } else if(num != 1) {
                printf("%ld n^%d", labs(num), k + 1 - j);
            } else {
                printf("n^%d", k + 1 - j);
            }
        }
    }
    printf(" )\n");
    return 0;
}