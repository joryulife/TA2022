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
    
    scanf("%d", &n);
    double a[n][n], lambda[n], q[n][n], r[n][n], err;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    /*for(int k = 0;k<n;k++){
        for(int r = 0;r < n;r++){
            printf("%10.7f ",a[k][r]);
        }
        printf("\n");
    }*/
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0.0;
        }
    }
    
    printf("\n");
    
    //int w = 0;
    while (1) {
        for (int j = 0; j < n; j++) {
            r[j][j] = norm(a[j], n);
            for (int i = 0; i < n; i++) {
                q[j][i] = a[j][i] / r[j][j];
            }
            for (int k = j + 1; k < n; k++) {
                r[j][k] = dot(q[j], a[k], n);
                for (int i = 0; i < n; i++) {
                    a[k][i] = a[k][i] - q[j][i] * r[j][k];
                }
            }
        }

        
    
        for (int i = 0; i < n; i++) {
            lambda[i] = a[i][i];
            for (int j = 0; j < n; j++) {
                a[j][i] = 0;
                for (int k = 0; k < n; k++) {
                    a[j][i] += r[i][k] * q[j][k];
                }
            }
        }

        /*for(int k = 0;k<n;k++){
            for(int r = 0;r < n;r++){
                printf("%20.17f ",a[k][r]);
            }
            printf("\n");
        }
        printf("\n");*/
    
        err = 0;
        for (int i = 0; i < n; i++) {
            err += fabs(a[i][i] - lambda[i]);
        }
        
        //printf("%11.9f\n",err);
        if (err < 1.0e-8) {
            
            /*for(int k = 0;k<n;k++){
                for(int r = 0;r < n;r++){
                    printf("%20.17f ",a[k][r]);
                }
                printf("\n");
            }*/
            //printf("err %20.17f ",err);
            for (int i = 0; i < n; i++) {
                printf("%f ", a[i][i]);
            }
            break;
        }
        //w++;
    }

    //printf("%d\n",w);
    printf("\n");
}