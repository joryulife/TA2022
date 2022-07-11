#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    double a[n][n + 1];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    int i, j, k;
    double m;
    
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            m = a[i][k] / a[k][k];
            for (j = 0; j <= n; j++) {
                a[i][j] = a[i][j] - a[k][j] * m;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                printf("%10.6f ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}