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
    double a[m][n], q[m][n], r[n][n];
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0.0;
        }
    }
    
    printf("\n");
    
    for(int i = 0;i<n;i++){
        double aTemp[m];
        double ad[m];
        for(int l=0;l<m;l++){
            ad[l] = a[l][i];
        }
        for(int l=0;l<=i-1;l++){
            double qTemp[m];
            for(int f=0;f<m;f++){
                qTemp[f] = q[f][l];
            }
            double dt = dot(qTemp,ad,m);
            for(int f=0;f<m;f++){
                ad[f] = ad[f] -dt*qTemp[f];
            }
        }
        for(int l=0;l<m;l++){
            q[l][i] = ad[l]/norm(ad,m);
        }
    }

    for(int i=0;i<m;i++){
        for(int j = 0;j < n;j++){
            printf("%f ",q[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<n;i++){
        double qTemp[m];
        for(int f=0;f<m;f++){
                qTemp[f] = q[f][i];
        }
        for(int j=0;j<n;j++){
            double aTemp[m];
            for(int f=0;f<m;f++){
                aTemp[f] = a[f][j];
            }
            printf("%f ",dot(qTemp,aTemp,m));
        }
        printf("\n");
    }
}