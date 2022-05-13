// 学籍番号 T22M004
// 氏名　　 福應　拓巳 
// 課題名　 4-4

#include <math.h>
#include <stdio.h>

int main() {
    double xn = 1.0, xnp1;
    int n;
    
    scanf("%d", &n);
    
    while (1) {
        xnp1 = (xn + n / xn) / 2.0;
        printf("%13.12f\n", xnp1);
        if (fabs((xnp1 - xn) / xn) < 1.0e-15){
            break;
        }
        xn = xnp1;
    }
}