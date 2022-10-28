#include <math.h>
#include <stdio.h>

double f(double x) { return x * x - atan(2.0 * x) - 1; }
int main() {
    double a, b, c, fc;
    double eps = 1.0e-15;

    scanf("%lf %lf", &a, &b);

    while(1) {

        c = (a + b) / 2.0;
        printf("%16.15f %16.15f\n", a, b);
        if(fabs(b - a) < eps) {
            printf("%16.15f %16.15f\n", a, b);
            break;
        }

        if(f(a) * f(c) <= 0) {
            b = c;
        } else {
            a = c;
        }
    }
}