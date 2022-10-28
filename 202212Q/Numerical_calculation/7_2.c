#include <math.h>
#include <stdio.h>

int main() {
    double a;
    double sn, snp1;
    double eps = 1.0e-15;
    int n = 0;
    int N;
    
    double x;
    scanf("%lf", &x);
    a = x;
    sn = x;
    
    while (1) {
        N = (2.0*(n+1.0) + 1.0);
        a = -a * (x * x / (N * (N - 1.0)));
        snp1 = sn + a;
        printf("%15.14f\n", snp1);
        if (fabs(snp1 - sn) < eps) {
            break;
        }
        n++;
        sn = snp1;
    }
    return 0;
}