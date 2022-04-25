#include <stdio.h>
#include <math.h>

double hen(double menseki) {
  return sqrt(menseki);
}

int main(void) {
  double menseki, x;
  printf("面積：");
  scanf("%lf", &menseki);
  x = hen(menseki);
  printf("一辺の長さ: %f\n", x); 
  return 0;
}
