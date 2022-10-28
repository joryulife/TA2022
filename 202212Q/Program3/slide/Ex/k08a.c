#include <stdio.h>

void set_sum(int n, int a[]) {
  if (n > 0) {
    a[0] = 0;
  }
  for (int i = 1; i < n; i++) {
    a[i] = a[i-1] + i;
  }
}

int main(void) {
  int a[20];
  int n = sizeof(a)/sizeof(a[0]);
  set_sum(n, a);
  for (int i = 0; i < n; i++) {
    printf("a[%d]=%d\n", i, a[i]);
  }
  return 0;
}
