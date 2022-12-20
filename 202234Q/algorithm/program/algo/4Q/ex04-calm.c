#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i <= (int)sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int CaLM(int n,double alpha){
    int k = ceil(n*alpha);
    while(!is_prime(k++));
    return k-1;
}

int main() {
    int n;
    double alpha;
    printf("input a number n alpha:");
    scanf("%d %lf",&n,&alpha);
    printf("m = :%d\n",CaLM(n,alpha));
    return 0;
}