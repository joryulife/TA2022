#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int seed,n;
    //printf("Input the seed: ");
    scanf("%u",&seed);
    srand(seed);
    //printf("Input the data number: ");
    scanf("%u",&n);

    do{
        printf("%d\n", rand() % n);
    }while(--n);
    //printf("%d",EOF);
}