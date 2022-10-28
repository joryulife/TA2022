#include <math.h>
#include <stdio.h>

int main() {
    int m, n;
    double mm;
    
    scanf("%d", &n);
    double a[n][n + 1];
    
    scanf("%d", &m);
    double x[m], y[m], c[n];
    
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0.0;
            for (int k = 0; k < m; k++) {
                a[i][j] += pow(x[k], i + j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        a[i][n] = 0;
        for (int k = 0; k < m; k++) {
            a[i][n] += y[k] * pow(x[k], i);
        }
    }
    
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            mm = a[i][k] / a[k][k];
            for (int j = k + 1; j <= n; j++) {
                a[i][j] = a[i][j] - a[k][j] * mm;
            }
        }
    }
    
    for (int k = n - 1; k >= 0; k--) {
        c[k] = a[k][n];
        for (int j = k + 1; j < n; j++) {
            c[k] = c[k] - a[k][j] * c[j];
        }
        c[k] = c[k] / a[k][k];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%3.2f ", c[i]);
    }
    printf("\n");
}