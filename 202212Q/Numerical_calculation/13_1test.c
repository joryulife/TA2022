#include <math.h>
#include <stdio.h>

double norm(double a[], int m) {
    double s = 0.0;
    for (int i = 0; i < m; i++) {
        s += a[i] * a[i];
    }
    return sqrt(s);
}

double dot(double a[],double b[], int m) {
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
    double aTemp[m];
    double ad[m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    //QとRの初期化
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            q[i][j]=a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0.0;
        }
    }
    
    printf("\n");
    
    for(int j = 0;j<n;j++){
        for(int i=0;i<m;i++){
            ad[i] = a[i][j];
        }
        for(int l=0;l<=j-1;l++){
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
            q[l][j] = ad[l]/norm(ad,m);
        }
    }

//Qの出力
    for(int i=0;i<m;i++){
        for(int j = 0;j < n;j++){
            printf("%10.7f ",q[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<n;i++){
        double qTemp[m];
        for(int f=0;f<m;f++){
                qTemp[f] = q[f][i];
        }

        for(int j=i;j<n;j++){
            double aTemp[m];
            for(int f=0;f<m;f++){
                aTemp[f] = a[f][j];
            }
            r[i][j] = dot(qTemp,aTemp,m);
        }
        //printf("%20.17f ",dot(qTemp,aTemp,m));
        //printf("\n");
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%10.7f ",r[i][j]);
        }
        printf("\n");
    }
}