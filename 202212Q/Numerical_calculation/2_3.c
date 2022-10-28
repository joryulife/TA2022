// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 2-3

#include <stdio.h>

int delta(int i,int j){
        if(i==j){
            return 1;
        }else{
            return 0;
        }
    }

long funcT(int n,int k){
        if(n == 0){
            return 0;
        }else{
            return (n == 1) ? (k-1)*delta(1,k-1)+(k+1)*delta(1,k+1) : (k-1)*funcT(n-1,k-1) + (k+1)*funcT(n-1,k+1);
        }
    }

int main() {


    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        printf("%ld\n",funcT(i,0));
    }
    return 0;
}
