#include <stdio.h>
#define N  6

void intary_rcpy(int v1[], const int v2[], int n) {
    for (int i = 0; i < n; i++) {
        v1[i] = v2[n-i-1];
    }
}


int main(void) {
    int c[N] = { 1, 9, 0, 1, 2, 3 };
    int a[N];
    intary_rcpy(a, c, N);
    printf("%d %d %d %d %d %d\n", 
            c[0],c[1],c[2],c[3],c[4],c[5]);
    printf("%d %d %d %d %d %d\n", 
            a[0],a[1],a[2],a[3],a[4],a[5]);
    return 0;
}