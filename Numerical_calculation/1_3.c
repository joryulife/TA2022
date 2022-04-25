// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 1-3

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int k = 1;k <= n;k++){
        int ans = 1;
        for(int i = 1;i <= k;i++){
            ans *= i;
        }
        printf("%d\n",ans);
    }
    return 0;
}