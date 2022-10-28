#include <math.h>
#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    double x[n], a[n][n],b[n];
    
    for (int i = 0; i < n + 1; i++) {
        x[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }
    
    int i, j, k, p;
    double m;
    
    for (k = 0; k < n - 1; k++) {
        double max = fabs(a[k][k]);
        p = k;
    
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > max) {
                p = i;
                max = a[p][k];
            }
        }
    
        double tmp;
        for (j = k; j < n; j++) {
            tmp = a[k][j];
            a[k][j] = a[p][j];
            a[p][j] = tmp;
        }
        tmp = b[k];
        b[k] = b[p];
        b[p] = tmp;
    
        for (i = k + 1; i < n; i++) {
            m = a[i][k] / a[k][k];
            for (j = 0; j <=n; j++) {
                a[i][j] = a[i][j] - a[k][j] * m;
            }
            b[i] = b[i] - b[k] * m;
        }
    }
    for (k = n - 1; k >= 0; k--) {
        x[k] = b[k];
        for (j = k + 1; j < n; j++) {
            x[k] = x[k] - a[k][j] * x[j];
        }
        x[k] = x[k] / a[k][k];
    }
    
    for (i = 0; i < n; i++) {
        printf("%10.9f ", x[i]);
    }
    printf("\n");
}