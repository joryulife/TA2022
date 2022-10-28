#include <math.h>
#include <stdio.h>

double f(double x) { return exp(-x * x); }

double g(double t) {
  return M_PI_2 * f(sinh(M_PI_2 * sinh(t))) * cosh(M_PI_2 * sinh(t)) * cosh(t);
}

int main() {
    int i, j;
    int n = 1;
    
    double a, b;
    scanf("%lf %lf", &a, &b);
    
    double h = b - a;
    double T = h * (g(a) + g(b)) / 2.0;
    
    for (i = 1; i < 10; i++) {
        n *= 2;
        h /= 2.0;
        double s = 0;
        for (j = 1; j <= n - 1; j += 2) {
            s += g(a + j * h);
        }
        T = T / 2.0 + h * s;
    
        printf("%8d %13.12f\n", n, T);
    }
}