#include <stdio.h>
#include <stdlib.h>

#define FILENAME  "hw.dat"
#define NAMELEN   80  /*名前の最大長*/

int main(void) {
  FILE *fp = NULL;
  fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    printf("書き込みオープン失敗: %s\n", FILENAME);
    exit(1);
  }
  printf("ファイル %s にデータを書き込みます\n", FILENAME);
  printf("EOFで入力終了です\n");
  for (;;) {
    char   name[NAMELEN];
    double weight;
    double height;
    printf("名前 体重 身長 = ");
    if (scanf("%s%lf%lf", name, &weight, &height) == 3) {
      fprintf(fp, "%s %.1f %.1f\n", name, weight, height);
    } else {
      printf("入力終了\n");
      break;
    }
  }
  fclose(fp);
  return 0;
}
