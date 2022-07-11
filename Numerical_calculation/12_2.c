#include <math.h>
#include <stdio.h>

int main() {
    int m, n;
    
    scanf("%d", &n);
    double a[n][n];
    double b[n];
    
    scanf("%d", &m);
    double x[m], y[m], c[n];
    
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    
    //printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0.0;
            for (int k = 0; k < m; k++) {
                a[i][j] += pow(x[k], i + j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int k = 0; k < m; k++) {
            b[i] += y[k] * pow(x[k], i);
        }
    }
    /*for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            printf("%f ",a[i][j]);
        }
        printf("%f\n",b[i]);
    }
    printf("\n");*/
    
    int i, j, k, p;
    double mm;
    
    for (k = 0; k < n - 1; k++) {
        /*double max = fabs(a[k][k]);
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
        b[p] = tmp;*/

        /*for(int i = 0;i<n;i++){
            for(int j= 0;j<n;j++){
                printf("%f ",a[i][j]);
            }
            printf("%f\n",b[i]);
        }
        printf("\n");*/
    
        for (i = k + 1; i < n; i++) {
            mm = a[i][k] / a[k][k];
            for (j = 0; j <= n; j++) {
                a[i][j] = a[i][j] - a[k][j] * mm;
            }
            b[i] = b[i] - b[k]*mm;
        }

        /*for(int i = 0;i<n;i++){
            for(int j= 0;j<n;j++){
                printf("%f ",a[i][j]);
            }
            printf("%f\n",b[i]);
        }
        printf("\n");*/
    }

    for (k = n - 1; k >= 0; k--) {
        c[k] = b[k];
        for (j = k + 1; j < n; j++) {
            c[k] = c[k] - a[k][j] * c[j];
        }
        c[k] = c[k] / a[k][k];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%3.2f ", c[i]);
    }
    printf("\n");
}