#include <stdio.h>

double dot(double a[], double b[], double n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    return s;
}

int main() {
    double alpha, alpha_d, beta, s;
    int n;
    
    scanf("%d", &n);
    
    double x[n], a[n][n] ,b[n], r[n], rr[n], p[n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }
    
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        r[i] = b[i];
        for (int j = 0; j < n; j++) {
            r[i] -= a[i][j] * x[j];
        }
        p[i] = r[i];
    }

    //ここまで初期化
    
    for (int k = 0; k < 20; k++) {
        alpha_d = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                alpha_d += a[i][j] * p[i] * p[j];
            }
        }
    
        alpha = dot(r, r, n) / alpha_d;
    
        for (int i = 0; i < n; i++) {
            x[i] += alpha * p[i];
        }
    
        for (int i = 0; i < n; i++) {
            double s = 0.0;
            for (int j = 0; j < n; j++) {
                s += a[i][j] * p[j];
            }
            rr[i] = r[i] - alpha * s;
        }
    
        beta = dot(rr, rr, n) / dot(r, r, n);
    
        for (int i = 0; i < n; i++) {
            p[i] = rr[i] + beta * p[i];
        }
    
        for (int i = 0; i < n; i++) {
            r[i] = rr[i];
        }
    
        for (int i = 0; i < n; i++) {
            printf("%10.9f ", x[i]);
        }
        printf("\n");
    }
    
    return 0;
}