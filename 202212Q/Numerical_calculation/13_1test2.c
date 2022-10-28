#include<stdio.h>
#include<math.h>

long double dot(double a[], double b[], int n){
    double v=0;
    for(int j=0; j<n;j++){
        v+=a[j]*b[j];
    }
    return v;
}

long double norm(double a[], int n){
    double v=0;
    for(int i=0; i<n;i++){
        v+=a[i]*a[i];
    }
    return sqrt(v);
}

int main(){
    int n, m;
    //m×n行列
    scanf("%d%d", &m, &n);

    double A[m][n], Q[m][n], R[n][n],tmp[m],tmp2[m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &A[i][j]);
        }
    }
    
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

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.7f ", Q[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.7f ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}