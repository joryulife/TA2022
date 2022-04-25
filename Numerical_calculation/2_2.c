// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 2-2

#include <stdio.h>

long binomial(int n, int k) {
    return (k == 0) ? 1 : binomial(n - 1, k - 1) * n / k;
}

int main() {
    int n,k;

    scanf("%d", &n);

    for(k = 0; k <= n; k++) {
        printf("%ld\n", binomial(n, k));
    }
}