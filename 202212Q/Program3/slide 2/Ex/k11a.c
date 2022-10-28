#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
  double x;
  double y;
};

int get_n(void);
struct point *alloc_array(int n);
void read_data(int n, struct point *p);
void compute(int n, struct point *p);

int main(void) {
  int n = 0;        /*データ数*/
  struct point *p = NULL; /*データ記憶用の配列(動的割当)*/
  /*データ数を得る*/
  n = get_n();
  /*配列のメモリを確保*/
  p = alloc_array(n);
  /*データを配列に読み込む*/
  read_data(n, p); 
  /*計算処理を行う*/
  compute(n, p);
  return 0;
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

struct point *alloc_array(int n) {
  struct point *p = NULL;
  p = malloc(n * sizeof(struct point));
  if (p == NULL) {
    printf("NO MEMORY\n"); 
    exit(1);
  }
  return p;
}

void read_data(int n,  struct point *p) {
  for (int i = 0; i < n; i++) {
    char s[1024];
    printf("点%dの座標 x y : ", i);
    if (fgets(s, sizeof(s), stdin) == NULL) {
      exit(0);
    }
    sscanf(s, "%lf%lf", &p[i].x, &p[i].y);
  }
}

void compute(int n, struct point *p) {
  int max_i1 = -1;
  int max_i2 = -1;
  double max_d = -1;
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
  printf("2点間の最大距離=%f\n", max_d);
  printf("(%lf,%lf) <-> (%lf,%lf)\n",
         p[max_i1].x, p[max_i1].y, p[max_i2].x, p[max_i2].y); 
}
