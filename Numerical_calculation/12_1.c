#include <stdio.h>
#include <math.h>

int main() {
    int m;
    double a[2][2], c[2],b[2];
    
    scanf("%d", &m);
    double x[m], y[m];
    
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    
    for (int i = 0; i < m; i++) {
        //a[0][0] = m;
        a[0][1] += x[i];
        //a[1][0] += x[i];
        a[1][1] += x[i] * x[i];
        b[0] += y[i];
        b[1] += y[i] * x[i];
    }
    
    a[0][0] = m;
    a[1][0] = a[0][1];
    
    int i, j, k, p;
    double mm;
    int n = 2;
    
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
            mm = a[i][k] / a[k][k];
            for (j = 0; j <= n; j++) {
                a[i][j] = a[i][j] - a[k][j] * mm;
            }
            b[i] = b[i] - b[k]*mm;
        }
    }

    /*printf("%5.3f ",a[0][0]);
    printf("%5.3f ",a[0][1]);
    printf("%5.3f\n",b[0]);
    printf("%5.3f ",a[1][0]);
    printf("%5.3f ",a[1][1]);
    printf("%5.3f\n",b[1]);*/
    for (k = n - 1; k >= 0; k--) {
        c[k] = b[k];
        for (j = k + 1; j < n; j++) {
            c[k] = c[k] - a[k][j] * c[j];
        }
        c[k] = c[k] / a[k][k];
    }
    
    for (i = 0; i < n; i++) {
        printf("%3.2f ", c[i]);
    }
    printf("\n");
}