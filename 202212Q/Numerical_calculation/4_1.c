// 学籍番号 T22M004
// 氏名　　 福應　拓巳 
// 課題名　 4-1

#include <math.h>
#include <stdio.h>
#define N 50

int main() {
    int n;
    double xn, xnp1;
    
    scanf("%lf", &xn);
    
    for (n = 0; n < N; n++) {
        xnp1 = 1.0 + 1.0 / xn;
        printf("%14.13f\n", xnp1);
        if (fabs((xnp1 - xn) / xn) < 1.0e-14){
            break;
        }
        xn = xnp1;
    }
}