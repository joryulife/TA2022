#include <stdio.h>
#include <ctype.h>

void prvword(const char s[]) {
  int i = 0;
  for (;;) {
    /* 空白はそのまま表示 */
    for ( ; isspace(s[i]); i++) {
      putchar(s[i]);
    }
    /* 文字列が終わりならここで終了 */
    if (s[i] == '\0') {
      break;
    }
    /* 単語の終わり j を見つける */
    int j = i;
    for ( ; !isspace(s[j]) && (s[j] != '\0'); j++) {
      ;
    }
    /* 単語を逆順で表示 */
    for (int k = j-1; k >= i; k--) {
      putchar(s[k]);
    }
    /* 文字列が終わりならここで終了 */
    if (s[j] == '\0') {
      break;
    }
    /* 単語の次の文字から表示 */
    i = j;
  }
}

void test(const char s[]) {
  /*元を表示*/
  printf("\"%s\"  ->  \"", s);  
  prvword(s);
  printf("\"\n");
}  

int main(void)
{
  test("12345"); 
  test("   ABC  DEF  GHI  "); 
  test("Hello World Login Incorrect"); 
  test("OHMI MAIKO");         /*(自分の) 名前 */
  test("Y190123 OHMI MAIKO"); /*(自分の) 学籍 名前 */
  return 0;
}
