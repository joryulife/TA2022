#include<stdio.h>
#include<math.h>

double dot(double a[], double b[], int n){
    double v=0;
    for(int j=0; j<n;j++){
        v+=a[j]*b[j];
    }
    return v;
}

double norm(double a[], int n){
    double v=0;
    for(int i=0; i<n;i++){
        v+=a[i]*a[i];
    }
    return sqrt(v);
}

int main(){
    int n=3, m;
    //データ数m
    scanf("%d", &m);
    double x[m],y[m];

    for(int i=0;i<m;i++)
        scanf("%lf%lf", &x[i], &y[i]);

    double A[m][n];
    for (int i = 0; i < m; i++) {
            A[i][0] = 1;
            A[i][1] = sin(4 * M_PI * x[i]);
            A[i][2] = cos(4 * M_PI * x[i]);
    }

    double Q[m][n], R[n][n],tmp[m],tmp2[m],b[n];
    
    //QとRの初期化
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Q[i][j]=A[i][j];
        }
    }
    
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            R[i][j]=0.0;
        }
    }

    for (int j = 0; j < n; j++) {
        //Qのベクトルを取り出す
        for(int i=0; i<m;i++)
            tmp[i]=A[i][j];
        R[j][j] = norm(tmp, m);

        for (int i = 0; i < m; i++) {
            Q[i][j] = A[i][j] / R[j][j];
        }

        for (int k = j + 1; k < n; k++) {
            //Qのベクトルを取り出す
            for(int i=0; i<m;i++)
                tmp[i]=Q[i][j];
            //Aのベクトルを取り出す
            for(int i=0; i<m;i++)
                tmp2[i]=A[i][k];
            R[j][k] = dot(tmp, tmp2, m);
            for (int i = 0; i < m; i++) {
                A[i][k] = A[i][k] - Q[i][j] * R[j][k];
            }
        }
    }

    //QTy
    for(int i=0;i<n;i++){
        b[i]=0.0;
        for(int j=0;j<m;j++){
            b[i]+=Q[j][i]*y[j];
        }
    }

    //後退代入
    double p;
    for(int k=n-1; k>0; k--){
        for(int i=k-1; i>=0; i--){
            p = R[i][k] / R[k][k];
            for(int j=0; j<n; j++){
                R[i][j] -= p * R[k][j];
            }
            b[i]-=p*b[k];
        }
    }

    for (int i = 0; i < n; i++) {
        b[i]=b[i]/R[i][i];
        printf("%5.4f ", b[i]);
    }
    printf("\n");

    return 0;
}