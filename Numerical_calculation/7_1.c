#include <math.h>
#include <stdio.h>

int main() {
    double a = 1; //S_0 = x^0/0! = 1
    double sn = a, snp1;
    double eps = 1.0e-15;
    int n = 0;
    
    double x;
    scanf("%lf", &x);
    
    while (1) {
        //printf("S_%d:",n);
        a = a * x / (n+1.0);
        snp1 = sn + a;
        printf("%15.14f\n", snp1);
        if (fabs((snp1 - sn) / sn) < eps) {
            break;
        }
        sn = snp1;
        n++;
    }
    return 0;
}