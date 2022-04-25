// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 1-1

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        printf("%d\n",2*i-1);
    }
    return 0;
}