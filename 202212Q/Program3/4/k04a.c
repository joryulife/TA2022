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