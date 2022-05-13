#include <math.h>
#include <stdio.h>
#define e 0.5

double f(double x, double l) { return x - e * sin(x) - l; }

double df(double x) { return 1 - e * cos(x); }

int main() {
    int i, j;
    double u = 0.0, new_u, l;
    double eps = 1.0e-15;
    
    for (i = 0; i < 64; i++) {
        l = 0.1 * i;
        while (1) {
            new_u = u - f(u, l) / df(u);
            if (fabs(new_u - u) < eps){
                break;
            }
            u = new_u;
        }
        printf("%9f %9f\n", 2 * (cos(u) - e), 2 * sqrt(1 - e * e) * sin(u));
    }
}