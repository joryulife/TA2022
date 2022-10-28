#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_mblen(const char *str) {
    int value;

    if ((*str & 0xFE) == 0xFC) {
        value = 6;
    // fprintf(stdout, "%dバイト文字の先頭\n", value);
    } else if ((*str & 0xFC) == 0xF8) {
        value = 5;
    // fprintf(stdout, "%dバイト文字の先頭\n", value);
    } else if ((*str & 0xF8) == 0xF0) {
        value = 4;
    // fprintf(stdout, "%dバイト文字の先頭\n", value);
    } else if ((*str & 0xF0) == 0xE0) {
        value = 3;
    // fprintf(stdout, "%dバイト文字の先頭\n", value);
    } else if ((*str & 0xE0) == 0xC0) {
        value = 2;
    // fprintf(stdout, "%dバイト文字の先頭\n", value);
    } else if ((*str & 0xC0) == 0x80) {
        value = -1;
    // fprintf(stdout, "マルチバイト文字の2バイト目以降\n");
    } else if ((*str & 0x80) == 0x00) {
        value = 1;
    // fprintf(stdout, "%dバイト文字\n", value);
    } else {
        value = 0;
        fprintf(stderr, "エラー：非対応文字\n");
    }

    return value;
}

void my_strrev(char str[]) {
    printf("%s -> ",str);
    char *new_text;
    new_text = (char *)calloc(strlen(str) + 1, sizeof(char));
    // 文末から文頭に向けて1バイトずつ確認
    for (int i = (strlen(str) - 1); i >= 0; i--) {
        int count = my_mblen(str + i);

        // 1バイト以上の文字の先頭
        if (count > 0) {
            char *chr;
            chr = (char *)calloc(count + 1, sizeof(char));
            // 複数バイトをまとめて1文字文コピー
            for (int j = 0; j < count; j++) {
                chr[j + 0] = str[i + j];
                chr[j + 1] = '\0';
            }
            // コピーした1文字を新文字列に追加
            strcat(new_text, chr);
            free(chr);
        }
        // マルチバイト文字の2バイト目以降
        else if (count == -1) {
            ;
        }
        // エラー
        else {
            free(new_text);
            exit(1);
        }
    }
    printf("%s\n",new_text);
    return ;
}

void print_stringr(const char s[]) {
    int i = 0;
    /*元を表示*/
    printf("%s -> ", s);  
    /* 文字列の終端(NUL)の添字を求める */
    /*for (i = 0; s[i] != '\0'; i++) {
        ;
    }*/
    while(s[i]){
        i++;
    }
    /* 逆順に表示してゆく */
    for (i = i - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main(void)
{
    my_strrev("T22M004");   /* 学生番号*/    
    my_strrev("福應    拓巳");/* 自分の名前*/
    my_strrev("20210513");  /*きょうの日付*/
    return 0;
}



