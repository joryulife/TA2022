#include <stdio.h>

int main(){

    int n,i;
    double sum;
    printf("n=?\n");
    scanf("%d",&n);

    sum = 0.0;
    for(i=1;i<=n;i++){
        sum += 1.0/(i*i);
    }
    printf("summation = %lf \n",sum);

    return 0;
}