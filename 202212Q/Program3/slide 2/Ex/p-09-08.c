#include <stdio.h>

void print_stringr(const char s[]) {
  int i;
  /*元を表示*/
  printf("%s -> ", s);  
  /* 文字列の終端(NUL)の添字を求める */
  for (i = 0; s[i] != '\0'; i++) {
    ;
  }
  /* 逆順に表示してゆく */
  for (i = i - 1; i >= 0; i--) {
    printf("%c", s[i]);
  }
  printf("\n");
}

int main(void)
{
  print_stringr("Y190123");   /* 学生番号*/
  print_stringr("Seta Taro"); /* 自分の名前*/
  print_stringr("20210510");  /*きょうの日付*/
  return 0;
}
