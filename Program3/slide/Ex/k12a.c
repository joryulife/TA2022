#include <stdio.h>
#include <math.h>

#define FNAME "k12a-out.txt"
#define X_FROM  1
#define X_TO    100

int main(void) {
  FILE *fp = NULL;
  if ((fp = fopen(FNAME, "w")) == NULL) {
    fprintf(stderr, "CANNOT OPEN TO WRITE: %s\n", FNAME);
    return 1;
  }
  for (int x = X_FROM; x < X_TO; x++) {
    fprintf(fp, "%8.5f %8.5f %8.5f %10.4e %10.4e\n",
            log(x), sqrt(x), (double)x, pow(x, 1.2), pow(x, 2.0));
  }
  fclose(fp);
  return 0;
}
