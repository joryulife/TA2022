#include <stdio.h>
#include <ctype.h>

void del_digit(char *str) {
  int i, j;
  j = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      str[j] = str[i];
      j = j + 1;
    }
  }
  str[j] = '\0';
}

int main(void) {
  char s1[] = "AB1C9";
  char s2[] = "You have 256 Mails.";
  char s3[] = "Failed 1024 times";
  char s4[] = "pi=3.141592, e=2.718";
  printf("%s", s1); del_digit(s1); printf(" -> %s\n", s1);
  printf("%s", s2); del_digit(s2); printf(" -> %s\n", s2);
  printf("%s", s3); del_digit(s3); printf(" -> %s\n", s3);
  printf("%s", s4); del_digit(s4); printf(" -> %s\n", s4);
  return 0;
}
