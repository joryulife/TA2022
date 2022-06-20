#include <stdio.h>

int combination(int n, int r) {
  if ((r == 0) || (r == n)) {
    return 1;
  } else if (r == 1) {
    return n;
  } 
  return combination(n-1, r-1) + combination(n-1, r);
}

int main(void) {
  int n, r, cnr;
  printf("n: ");
  scanf("%d", &n);
  printf("r: ");
  scanf("%d", &r);
  cnr = combination(n, r);
  printf("C(%d,%d)=%d\n", n, r, cnr); 
  return 0;
}
