// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 2-1

#include <stdio.h>

long fac(int n) { //
    return (n == 0) ? 1 : n * fac(n - 1);
}

long binomial(int n, int k) { //
    return fac(n) / (fac(k) * fac(n - k));
}

int main() {
    int n;
    int k;

    scanf("%d", &n);

    for(k = 0; k <= n; k++) {
        printf("%ld\n", binomial(n, k)); //
    }
}