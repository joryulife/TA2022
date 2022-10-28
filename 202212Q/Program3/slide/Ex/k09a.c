#include <stdio.h>

void del_chars(char *s, char *d) {
  /* p_r : 文字列 s 内での読み出し元 */
  /* p_w : 文字列 s 内での書き込み先 */
  char *p_w = s; 
  for (char *p_r = s; *p_r != '\0'; p_r++) {
    char c = *p_r; /* この文字がd内にあれば削除/なければ残す */
    char *q = d;
    for ( ; *q != '\0'; q++) {
      if (c == *q) { /* d内に発見 */
        break;
      }
    }
    if (*q == '\0') { /* d内で発見できない -> sに残す */
      *p_w = c; /* sに詰める(=残す) */
      p_w++;
    }                 /* d内に発見 -> sに残さない(=削除) */
  }
  *p_w = '\0'; 
}

void del_chars2(char *s, char *d) {
  for(char *p_d = d; *p_d != '\0';p_d++){
    char deleteChar = *p_d;
    
  }
}

void test(char *s, char *d) {
  printf("del_chars(\"%s\",\"%s\")\n", s, d);
  del_chars(s, d);
  printf("--> \"%s\"\n", s);
}

int main(void) {
  char s1[] = "AAA-BBB-CCC-111-222-333";
  char s2[] = "ABC-DEF-1234-567-XYZ";
  char s3[] = "AAABBBCCC";
  test(s1, "3A");
  test(s2, "321CBA");
  test(s3, "ABC123");
  return 0;
}

