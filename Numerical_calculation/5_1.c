#include <math.h>
#include <stdio.h>

/* 関数の宣言 */
double a;
double f(double x){ 
    return x * x - atan(2.0 * x) - 1; 
}
double df(double x){ 
    return 2.0 * x - 2.0 / (1.0 + 4.0 * x * x);
}

int main() {
    double x, new_x;
    double eps = 1.0e-15;
    
    scanf("%lf", &x);
    
    for (int i = 0; i < 100; i++) {
        new_x = x - f(x) / df(x);
        printf("%16.15f\n", new_x);
        if (fabs((new_x - x) / x) < eps)
        break;
        x = new_x;
    }
}