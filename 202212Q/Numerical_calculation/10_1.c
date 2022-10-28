#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    double x[n], a[n][n],b[n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
        x[i] = 0;
    }
    
    for (int k = 0; k < 20; k++) {
        for (int i = 0; i < n; i++) {
            double s = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    s += a[i][j] * x[j];
                }
            }
            x[i] = (b[i]-s) / a[i][i];
            printf("%10.9f ", x[i]);
        }
        printf("\n");
    }
    return 0;
}