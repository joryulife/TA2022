#include <math.h>
#include <stdio.h>

double f(double x) { return 2.0 / (1.0 + x * x); }

int main() {
    int i, j;
    int n = 1;
    
    double a, b;
    scanf("%lf %lf", &a, &b);
    
    double h = b - a;
    double T = h * (f(a) + f(b)) / 2.0;
    
    for (i = 1; i < 23; i++) {
        n *= 2;
        h /= 2.0;
        double s = 0;
        for (j = 1; j <= n - 1; j += 2) {
            s += f(a + j * h);
        }
        T = T / 2.0 + h * s;
    
        printf("%8d %12.11f\n", n, T);
    }
}