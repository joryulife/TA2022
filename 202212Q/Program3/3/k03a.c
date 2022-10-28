#include <stdio.h>
#include <math.h>

double side(double area) {
    return sqrt(area);
}

int main(void) {
    double area, x;
    printf("面積：");
    scanf("%lf", &area);
    x = side(area);
    printf("一辺の長さ: %f\n", x); 
    return 0;
}