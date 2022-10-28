// 学籍番号 T22M004
// 氏名　　 福應　拓巳
// 課題名　 1-6
// k!の出力 k_0=>n
#include <stdio.h>
#define N 140

int main() {
    int n;
    int digit[N];
    digit[0] = 1;
    for (int i = 1; i < N; i++) { //配列の初期化
        digit[i] = 0;
    }

    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < N; i++) { //N桁目までそれぞれにkをかける
            digit[i] *= k;
        }

        for (int i = 0; i < N; i++) { //kをかけた結果繰り上がりがあれば処理する
            if (digit[i] > 9) {
                digit[i + 1] += digit[i] / 10;
                digit[i] = digit[i] % 10;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            if (digit[i] != 0) { //上の桁から走査して初めてでた0でない桁から表示を開始する
                for (int j = i; j >= 0; j--) {
                    printf("%d", digit[j]);
                }
                break;
            }
        }
        printf("\n");
    }
    return 0;
}