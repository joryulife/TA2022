#include <stdio.h>

void del_chars(char *s, char *d) {
  char *p_w = s; 
  for (; *s != '\0'; s++) {
    printf("p_s:%p %c\n",s,*s);
    char deleteChar = *s;
    char *p_d = d;
    for ( ; *p_d != '\0'; p_d++) {
      if (deleteChar == *p_d) {
        break;
      }
    }
    if (*p_d == '\0') {
      *p_w = deleteChar;
      p_w++;
    }
  }
  *p_w = '\0'; 
}

void del_chars2(char *s, char *d) {
  for(char *p_d = d; *p_d != '\0';p_d++){
    char deleteChar = *p_d;
    for(char *p_s = s; *p_s != '\0';p_s++){
      if(*p_s == deleteChar){
        for(char *p_temp = p_s;*p_temp != '\0';p_temp++){
          *p_temp = *(p_temp+1);
        }
        p_s--;
      }
    }
  }
}

/*void del_chars2(char *s, char *d) {
  for(char *p_d = d; *p_d != '\0';p_d++){
    char deleteChar = *p_d;
    printf("d:%c\n",*p_d);
    for(char *p_s = s; *p_s != '\0';p_s++){
      printf("s:%p  %c\n",p_s,*p_s);
      if(*p_s == deleteChar){
        printf("At  %p %c\n",p_s,*p_s);
        for(char *p_temp = p_s;*p_temp != '\0';p_temp++){
          printf("p_temp:%p %c -->",p_temp,*p_temp);
          *p_temp = *(p_temp+1);
          printf("p_temp:%p %c\n",p_temp,*p_temp);
        }
        p_s--;
      }
    }
  }
}*/

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

