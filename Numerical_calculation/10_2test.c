#include <stdio.h>

double dot(double a[], double b[], double n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    return s;
}

int main() {
    double alpha, beta, s;
    int n;
    
    scanf("%d", &n);
    
    double x[n], a[n][n] ,b[n], r[n], p[n],apk[n];
    
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
        for(int i = 0; i < n; i++){
            double s = 0;
            for(int j = 0; j < n; j++){
                s+= a[i][j]*p[j];
            }
            apk[i] = s;
        }

        alpha = dot(r,p,n)/dot(p,apk,n);

        for(int i = 0; i < n; i++){
            x[i] = x[i] + alpha*p[i];
        }

        for(int i = 0; i < n; i++){
            r[i] = r[i] - alpha*apk[i];
        }

        beta = -dot(r,apk,n)/dot(p,apk,n);

        for(int i = 0; i < n; i++){
            p[i] = r[i] + beta*p[i];
        }

        for (int i = 0; i < n; i++) {
            printf("%10.9f ", x[i]);
        }
        printf("\n");
    }
    return 0;
}

//[11,20,17]*[[3,2,1],[2,5,2],[1,2,3]]*[11,20,17]