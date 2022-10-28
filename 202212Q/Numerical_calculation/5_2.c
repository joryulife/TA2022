#include <math.h>
#include <stdio.h>

double f(double x, double y) {
  printf("%d\n",x * x + y * y - atan(2.0 * x + 3.0 * y) - 1.0);
  return x * x + y * y - atan(2.0 * x + 3.0 * y) - 1.0;
}
double g(double x, double y) { 
  printf("%d\n",tanh(y) - 2.0 * sin(x));
  return tanh(y) - 2.0 * sin(x); 
}
double fx(double x, double y) {
  printf("%d\n",2.0 * x - 2.0 / (1.0 + (2.0 * x + 3.0 * y) * (2.0 * x + 3.0 * y)));
  return 2.0 * x - 2.0 / (1.0 + (2.0 * x + 3.0 * y) * (2.0 * x + 3.0 * y));
}
double fy(double x, double y) {
  printf("%d\n",2.0 * y - 3.0 / (1.0 + (2.0 * x + 3.0 * y) * (2.0 * x + 3.0 * y)));
  return 2.0 * y - 3.0 / (1.0 + (2.0 * x + 3.0 * y) * (2.0 * x + 3.0 * y));
}
double gx(double x, double y) { 
  printf("%d\n",-2.0 * cos(x));
  return -2.0 * cos(x);
}
double gy(double x, double y) {
  printf("%d\n",1.0 / pow(cosh(y), 2.0));
  return 1.0 / pow(cosh(y), 2.0);
}

int main() {
    int i;
    double x;
    double y;
    double new_x, new_y;
    double eps = 1.0e-15;
    double D;
    
    scanf("%lf %lf", &x, &y);
    
    for (i = 0; i < 8; i++) {
      
      D = fx(x, y) * gy(x, y) - fy(x, y) * gx(x, y);
      new_x = x + (-f(x, y) * gy(x, y) + fy(x, y) * g(x, y)) / D;
      new_y = y + (-fx(x, y) * g(x, y) + f(x, y) * gx(x, y)) / D;
      if (fabs((new_x - x) / x) < eps & fabs((new_y - y) / y) < eps) {
          printf("%14.13f %14.13f\n", new_x, new_y);
          break;
      }
      x = new_x;
      y = new_y;
      printf("%14.13f %14.13f\n", x, y);
    }
}