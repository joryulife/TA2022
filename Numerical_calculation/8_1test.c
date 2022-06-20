#include <math.h>
#include <stdio.h>

double f(double x) { return 2.0 * sqrt(1.0 - x * x); }

int main() {
    int i, j;
    int n = 1;
    
    double a, b;
    scanf("%lf %lf", &a, &b);
    
    double h = b - a;
    double T;
    
    while(1) {
        n *= 2;
        //printf("n:%d\n",n);
        h /= 2.0;
        double s = 0;
        for (j = 1; j <= n - 1; j ++) {
            s += f(a + j * h);
        }
        T = (h/2.0) * (f(a) + f(b)) + h * s;
        printf("%7d %10.9f\n", n, T);
        if(n>=4194304){
            break;
        }
    }
}