// 学籍番号 T22M004
// 氏名 福應 拓巳 
// 課題名 4-5

#include <math.h>
#include <stdio.h>

int main() {
    double a = 2.0 * sqrt(3), b = 3.0;
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        a = 2 * a * b / (a + b);
        b = sqrt(a * b);
        printf("%15.14f\n", a);
    }
}