#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    int n;
    scanf("%d", &n);

    printf("数列の一般項 %d", a[0]);
    for (int k = 1; k < m; k++) {
        printf(" + %d*k^%d", a[k], k);
    }
    printf("\n");

    for (int k = 0;"埋めて"; k++) {
        "埋めて sumの宣言と初期化"
        "埋めて tempの宣言と初期化"

        for (int i = 0;"埋めて"; i++) {
            "埋めて"
            "埋めて"
        }

        printf("%d\n", sum);
    }
}