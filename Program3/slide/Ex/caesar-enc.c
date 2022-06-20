/* シーザー暗号; 暗号化 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZ  4096
#define KEY         5

/* 置き換え表 */
char table[256];

/* 置き換え表の作成 */
void make_enc_table(void)
{
  const char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int ch = 0; ch < 256; ch++) {
    table[ch] = ch;
  }
  for (int i = 0; s[i] != '\0'; i++) {
    int k = (i + KEY) % strlen(s);
    table[s[i]] = s[k];
  }
}

int main(int argc, char **argv)
{
  char plain[LINESIZ];
  make_enc_table();
  for (;;) {
    if (fgets(plain, sizeof(LINESIZ), stdin) == NULL) {
      break;
    }
    /* 暗号化 */
    for (int i = 0; plain[i] != '\0'; i++) {
      char ch = plain[i];
      printf("%c", table[ch]);
    }
  }
  return 0;
}

