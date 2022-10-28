#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
5 3
1 2 4 8 16
*/

int main(int argc, char* argv[]){
    char *buf = NULL;
    char *p=NULL;
    int N=0, K=0;
    int *A = NULL;
    long long *S = NULL;
    long long sumtotal = 0;

    buf = (char*)calloc(100000+1, 10);//データサイズ10,データ数10000+1のメモリを0ブロックで確保
    printf("%s\n",buf);
    fgets(buf, 100000*10+1, stdin);
    /* fgets()
        第一引数は文字配列のポインタ
        第二引数は一行の最大文字数
        第三引数はファイルポインタ
    */
    p = strtok(buf, " ");
    printf("%p\n",p);
    N = atoi(p);
    printf("%d\n",N);
    p = strtok(NULL, " ");
    K = atoi(p);
    memset(buf, 0, (100000+1)*10);

    A = (int*)calloc(N+1, sizeof(int));
    S = (long long*)calloc(N+1, sizeof(long long));

    fgets(buf, N*10+1, stdin);
    p = strtok(buf, " ");
    A[0] = atoi(p);
    S[0] = (long long)A[0];
    for(int i=1; i<N; i++){
            p = strtok(NULL, " ");
            A[i] = atoi(p);
            S[i] = S[i-1] + A[i];
    }

    sumtotal = S[K-1];
    for(int i=1; i<N-K+1; i++){
            sumtotal += (S[i+K-1]-S[i-1]);
    }

    printf("%lld\n", sumtotal);
    return 0;
}