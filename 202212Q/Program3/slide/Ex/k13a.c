#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  FILE *sfp; /* コピー元 */
  FILE *dfp; /* コピー先 */
  char sname[FILENAME_MAX]; /* コピー元 */
  char dname[FILENAME_MAX]; /* コピー先 */
  printf("コピー元ファイル名："); scanf("%s", sname);
  printf("コピー先ファイル名："); scanf("%s", dname);

  if ((sfp = fopen(sname, "r")) == NULL) {
    printf("\aコピー元ファイルをオープンできません。\n");
    return 1;
  }

  if ((dfp = fopen(dname, "w")) == NULL) { /* コピー先 */
    printf("\aコピー先ファイルをオープンできません。\n");
    return 1;
  }

  while ((ch = fgetc(sfp)) != EOF) {
    if (islower(ch)) {
      fputc(toupper(ch), dfp);
    } else if (isupper(ch)) {
      fputc(tolower(ch), dfp);
    } else if (isdigit(ch)) {
      fputc('*', dfp);
    } else {
      fputc(ch, dfp);
    }
  }
  fclose(sfp); 
  fclose(dfp); 
  return 0;
}
