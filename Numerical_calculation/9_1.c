#include <math.h>
#include <stdio.h>

double f(double x) { return 2.0 / (1 + x * x); }

int main() {
    int i, j;
    int n = 1;
    double a, b;
    
    scanf("%lf %lf", &a, &b);
    
    double h = b - a;
    
    for (i = 1; i < 10; i++) {
        n *= 2;
        h /= 2.0;
        double S = 0;
        for (j = 0; j < n; j = j + 2) {
            S += (f(a + j * h) + 4.0 * f(a + (j + 1) * h) + f(a + (j + 2) * h)) / 3;
        }
        S = S * h;
        printf("%3d %13.12f\n", n, S);
    }
}