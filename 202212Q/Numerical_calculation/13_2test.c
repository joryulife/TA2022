#include<stdio.h>
#include<math.h>
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

int main(){
    int n=3, m;
    //データ数m
    scanf("%d", &m);
    double x[m],y[m];

    for(int i=0;i<m;i++)
        scanf("%lf%lf", &x[i], &y[i]);

    double a[m][n];
    for (int i = 0; i < m; i++) {
            a[i][0] = 1;
            a[i][1] = sin(4 * M_PI * x[i]);
            a[i][2] = cos(4 * M_PI * x[i]);
    }

    double q[m][n], r[n][n],b[n];
    
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
            r[i][j] = dot(qTemp,aTemp,m);
            //printf("%10.7f ",dot(qTemp,aTemp,m));
        }
        //printf("\n");
    }

    //QTy
    for(int i=0;i<n;i++){
        b[i]=0.0;
        for(int j=0;j<m;j++){
            b[i]+=q[j][i]*y[j];
        }
    }

    //後退代入
    double p;
    for(int k=n-1; k>0; k--){
        for(int i=k-1; i>=0; i--){
            p = r[i][k] / r[k][k];
            for(int j=0; j<n; j++){
                r[i][j] -= p * r[k][j];
            }
            b[i]-=p*b[k];
        }
    }

    for (int i = 0; i < n; i++) {
        b[i]=b[i]/r[i][i];
        printf("%5.4f ", b[i]);
    }
    printf("\n");

    return 0;
}