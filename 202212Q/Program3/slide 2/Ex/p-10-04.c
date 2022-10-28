#include <stdio.h>

int set_idx(int *v, int n) {
  int i;
  for (i = 0; i < n; i++) {
    v[i] = i;
  }
}

#define N 8

int main(void) {
  int x[N], i;
  set_idx(x, N);
  for (i = 0; i < N; i++) {
    printf("x[%d]=%d\n", i, x[i]);
  }
  return 0;
}
