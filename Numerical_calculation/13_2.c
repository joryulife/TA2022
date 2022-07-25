#include <math.h>
#include <stdio.h>

double norm(double a[], int m) {
    double s = 0.0;
    for (int i = 0; i < m; i++) {
        s += a[i] * a[i];
    }
    return sqrt(s);
}

double dot(double a[], double b[], int m) {
    double s = 0.0;
    for (int i = 0; i < m; i++) {
        s += a[i] * b[i];
    }
    return s;
}

int main() {
    int m, n = 3;
    
    scanf("%d", &m);
    double a[n][m], q[n][m], r[n][n], x[m], y[m], b[n], c[n];
    
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    
    for (int i = 0; i < m; i++) {
        a[0][i] = 1;
        a[1][i] = sin(4 * M_PI * x[i]);
        a[2][i] = cos(4 * M_PI * x[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0.0;
        }
    }
    
    printf("\n");
    
    for (int j = 0; j < n; j++) {
        r[j][j] = norm(a[j], m);
        for (int i = 0; i < m; i++) {
            q[j][i] = a[j][i] / r[j][j];
        }
        for (int k = j + 1; k < n; k++) {
            r[j][k] = dot(q[j], a[k], m);
            for (int i = 0; i < m; i++) {
                a[k][i] = a[k][i] - q[j][i] * r[j][k];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int j = 0; j < m; j++) {
            b[i] += q[i][j] * y[j];
        }
    }
    
    for (int k = n - 1; k >= 0; k--) {
        c[k] = b[k];
        for (int j = k + 1; j < n; j++) {
            c[k] -= r[k][j] * c[j];
        }
        c[k] = c[k] / r[k][k];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%5.4f ", c[i]);
    }
    printf("\n");
}