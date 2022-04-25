#include <stdio.h>

int main() {
    long x;

    scanf("%ld", &x);

    for(int i = 63; i >= 0; i--) {
        printf("%ld", (x >> i) & 1);
    }

    printf("\n");

    return 0;
}