#include <stdio.h>

void swap(int *px, int *py)
{
  int temp = *px;
  *px = *py;
  *py = temp;
}

void sort4(int *n1, int *n2, int *n3, int *n4) {
  /* *n1, *n2, *n3, *n4  の最小値が *n1 となるよう交換 */
  if (*n3 > *n4)
    swap(n3, n4);
  if (*n2 > *n3)
    swap(n2, n3);
  if (*n1 > *n2)
    swap(n1, n2);
  /* *n2, *n3, *n4  の最小値が *n2 となるよう交換 */
  if (*n3 > *n4)
    swap(n3, n4);
  if (*n2 > *n3)
    swap(n2, n3);
  /* *n3, *n4 の最小値が *n3 となるよう交換 */
  if (*n3 > *n4)
    swap(n3, n4);
}

int main(void) {
  int na, nb, nc, nd;
  printf("整数A: "); scanf("%d", &na);
  printf("整数B: "); scanf("%d", &nb);
  printf("整数C: "); scanf("%d", &nc);
  printf("整数D: "); scanf("%d", &nd);
  sort4(&na, &nb, &nc, &nd);
  printf("%d,%d,%d,%d\n", na, nb, nc, nd);
  return 0;
}
