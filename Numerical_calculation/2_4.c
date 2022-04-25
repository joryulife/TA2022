// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 2-5

#include <stdio.h>
#include <stdlib.h>

long gcd(long x, long y) {
    if(y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}
long fac(int n) {
    return (n == 0) ? 1 : n * fac(n - 1);
}

long b(int k, int m, int n) {
    if(k == 0) {
        return fac(n) / m;
    } else {
        return m * (b(k - 1, m, n) - b(k - 1, m + 1, n));
    }
}

int main() {
    int n;
    long g;
    scanf("%d", &n);

    for(int k = 0; k < n; k++) {
        g = labs(gcd(b(k, 1, n - 1), fac(n - 1)));
        printf("%ld %ld\n", b(k, 1, n - 1) / g, fac(n - 1) / g);
    }
    return 0;
}