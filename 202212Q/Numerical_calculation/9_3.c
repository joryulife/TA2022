#include <math.h>
#include <stdio.h>

double f(double x, double s) {
  return sin(s * atan(x)) /
         (pow((x * x + 1), s / 2.0) * (exp(2 * M_PI * x) - 1));
}

double g(double t, double s) {
  return M_PI_2 * f(exp(M_PI_2 * sinh(t)), s) * exp(M_PI_2 * sinh(t)) * cosh(t);
}

int main() {
    int i, j;
    int n;//2,4,16,32,64,128,256,512
    double s, a,b;
    scanf("%lf", &s);
    int N[9] = {2,4,8,16,32,64,128,256,512};
    double AB[22] = {1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0};
    for(int nn = 0;nn<9;nn++){
        for(int ab=0;ab<22;ab++){
            n = N[nn];
            a = -AB[ab];
            b = AB[ab];
            double h = (b - a) / n;
            double S = 0;
            for (j = 0; j < n; j++) {
                S += (g(a + j * h, s) + g(a + (j + 1) * h, s)) / 2;
            }
            S = S * h;
            S = 0.5 + 1.0 / (s - 1) + 2 * S;
            printf("n:%d ab:%f %10.9f 誤差:%10.9f\n", n,a,S,S-1.644934067);
            
        }
    }
    /*int n = 256;//2,4,16,32,64,128,256,512
    double s, a = -3.8, b = 3.8;

    
    scanf("%lf", &s);
    
    double h = (b - a) / n;
    
    double S = 0;
    for (j = 0; j < n; j++) {
        S += (g(a + j * h, s) + g(a + (j + 1) * h, s)) / 2;
    }
    S = S * h;
    S = 0.5 + 1.0 / (s - 1) + 2 * S;
    printf("%10.9f\n", S);*/
}