#include <stdio.h>
#include <stdbool.h>

// 2からMAXまでの素数を求める
void sieve(bool prime[],int MAX) {
    for (int i = 2; i <= MAX; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]){
            for (int j=2*i; j<=MAX; j+=i) {
                prime[j] = false;
            }
        }
    }
}

// 2からMAXまでの素数を表示する
void print_prime(bool prime[],int MAX) {
    for (int i=2; i<=MAX; i++) {
        if (prime[i]) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int MAX;
    printf("input a number:");
    scanf("%d",&MAX);
    bool prime[MAX + 1];
    sieve(prime,MAX);
    print_prime(prime,MAX);

    return 0;
}

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