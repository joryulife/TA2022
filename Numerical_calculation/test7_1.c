#include <math.h>
#include <stdio.h>

int main() {
    double a = 1;
    double s = a, ss = -1.0;
    double eps = 1.0e-15;
    int n = 1;
    
    double x;
    scanf("%lf", &x);
    
    while (1) {
        a = a * x / n;
        ss = s;
        s += a;
        printf("%15.14f\n", s);
        if (fabs((ss - s) / s) < eps) {
            break;
        }
        n++;
    }
    return 0;
}