#include <math.h>
#include <stdio.h>

int main() {
    double a;
    double sn, snp1;
    double eps = 1.0e-15;
    int n = 0;
    int No = 1;
    int Nn;
    
    double t, x;
    scanf("%lf", &t);
    
    x = (t - 1.0) / (t + 1.0);
    a = 2 * x;
    sn = a;
    
    while (1) {
        Nn = 2.0*(n+1.0) + 1.0 ;
        a = a * x * x * No/Nn;
        snp1 = sn + a;
        printf("%15.14f\n", snp1);
        if (fabs(snp1 - sn) < eps) {
            break;
        }
        sn = snp1;
        No = Nn;
        n++;
    }
    return 0;
}