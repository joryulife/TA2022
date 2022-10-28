#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i;
  double *v;
  printf("データ数 N : "); scanf("%d", &n);
  v = malloc(sizeof(double) * n);
  if (v == NULL) {
    printf("mallocエラー");
    exit(1);
  }
  for (i = 0; i < n; i++) {
    v[i] = (double) i / n;
  }
  for (i = 0; i < n; i++) {
    printf("v[%d] = %f\n", i, v[i]);
  }
  return 0;
}
