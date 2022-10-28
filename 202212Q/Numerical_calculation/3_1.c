#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    for(int i = 32; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }

    printf("\n");

    return 0;
}