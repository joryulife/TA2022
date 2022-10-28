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
    int m, n;
    
    scanf("%d", &m);
    scanf("%d", &n);
    double a[n][m], q[n][m], r[n][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[j][i]);
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j = 0;j < m;j++){
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    
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
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.7f ", q[j][i]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.7f ", r[i][j]);
        }
        printf("\n");
    }
}