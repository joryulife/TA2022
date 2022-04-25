// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 1-5

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

    for (int j = 0; j < n; j++) {
        int ans = 0;
        int temp = 1;

        for (int k = 0; k < m; k++) {
            ans += a[k] * temp;
            temp *= j;
        }

        printf("%d\n", ans);
    }
}