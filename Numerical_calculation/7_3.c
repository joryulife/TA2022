#include <math.h>
#include <stdio.h>

int main() {
    double a;
    double sn, snp1;
    double eps = 1.0e-15;
    int n = 1;
    
    double x;
    scanf("%lf", &x);
    a = x;
    sn = x;
    
    while (1) {
        a = a*n * -x/(n+1.0);
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