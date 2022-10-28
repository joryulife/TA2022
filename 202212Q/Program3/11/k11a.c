#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} point ;

point* alloc_array(int n) {
  point *p = NULL;
  p = malloc(n * sizeof(point));
  if (p == NULL) {
    printf("NO MEMORY\n"); 
    exit(1);
  }
  return p;
}

int get_n(void) {
  int n = 0;
  while (n <= 0) { 
    char s[1024];
    printf("データ数n : ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
      exit(0);
    }
    n = atoi(s);
  }
  return n;
}

void read_data(int n,point *p) {
  for (int i = 0; i < n; i++) {
    char s[1024];
    printf("点%dの座標 x y : ", i);
    if (fgets(s, sizeof(s), stdin) == NULL) {
      exit(0);
    }
    sscanf(s, "%lf%lf", &p[i].x, &p[i].y);
  }
}

void compute(int n,point *p) {
  int max_i1 = 0;
  int max_i2 = 0;
  double max_d = 0;
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1 + 1; i2 < n; i2++) {
      double dx = p[i1].x - p[i2].x;
      double dy = p[i1].y - p[i2].y;
      double d = sqrt(dx*dx + dy*dy);
      if (max_d < d) {
        max_i1 = i1;
        max_i2 = i2;
        max_d  = d;
      }
    }
  }
  if(2 <= n ){
    printf("2点間の最大距離=%f\n", max_d);
    printf("(%lf,%lf) <-> (%lf,%lf)\n",p[max_i1].x, p[max_i1].y, p[max_i2].x, p[max_i2].y); 
  }else{
    printf("入力された点は%d個です。二点間の距離は計れません。\n",n);
  }
}


int main(void) {
  int n;
  point *p = NULL;
  n = get_n();
  p = alloc_array(n);
  read_data(n, p); 
  compute(n, p);
  return 0;
}
