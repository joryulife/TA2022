#include <stdio.h>

int str_length(const char s[]){
    int len = 0;

    while(s[len]){
        len++;
    }
    return len;
}

int main(){
    char str[128];
    printf("文字列を入力せよ:");
    scanf("%s",str);
    printf("文字列\"%s\"の長さは%dです。\n",str,str_length(str));

    return 0;
}