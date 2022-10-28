#include <stdio.h>
#include <math.h>

#define sqr(n)  ((n) * (n))

//=== 点の座標を表す構造体 ===//
typedef struct  {
  double x;  // Ｘ座標
  double y;  // Ｙ座標
} Point;

//=== 自動車を表す構造体 ===//
typedef struct  {
  Point  pt;    // 現在位置
  double fuel;  // 残り燃料
} Car;

//--- 点p1と点p2の距離を返す---//
double distance_of(Point p1, Point p2)
{
  return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

//--- 自動車の現在位置と残り燃料を表示 ---//
void put_info(Car c)
{
  printf("現在位置：(%.2f, %.2f)\n", c.pt.x, c.pt.y);
  printf("残り燃料：%.2fリットル\n", c.fuel);
}

//--- cの指す車を目的座標destに移動 ---//
int move(Car *c, Point dest)
{
  double d = distance_of(c->pt, dest);  // 移動距離
  if (d > c->fuel)       // 移動距離が燃料を超過
    return 0;              // 移動不可
  c->pt = dest;    // 現在位置を更新（destに移動）
  c->fuel -= d;    // 燃料を更新（移動距離dの分だけ減る）
  return 1;                // 移動成功
}

int main(void)
{
  Car mycar = {{0.0, 0.0}, 90.0};
  while (1) {
    int select;
    Point dest;    // 目的地の座標
    double dx, dy;    // 移動距離(X,Y)
    double dir;       // 移動の方位  
    double dist;      // 移動距離
    put_info(mycar);  // 現在位置と残り燃料を表示
    printf("移動しますか\n【No…0/移動目的地の座標…1/X,Yの移動距離…2/方角と移動距離…3】：");
    dest.x = mycar.pt.x;
    dest.y = mycar.pt.y;
    scanf("%d", &select);
    switch (select) {
    default:
      break;
    case 0:
      return 0;
    case 1:
      printf("目的地のＸ座標：");  scanf("%lf", &dest.x);
      printf("　　　　Ｙ座標：");  scanf("%lf", &dest.y);
      break;
    case 2:
      printf("Ｘ座標の移動距離：");  scanf("%lf", &dx);
      printf("Ｙ座標の移動距離：");  scanf("%lf", &dy);
      dest.x += dx;
      dest.y += dy;
      break;
    case 3:
      printf("移動の方位（角度）：");  scanf("%lf", &dir);
      printf("　　　　　移動距離：");  scanf("%lf", &dist);
      dest.x += dist * cos(dir*M_PI/180);
      dest.y += dist * sin(dir*M_PI/180);
      break;
    }
    if (!move(&mycar, dest))
      puts("\a燃料不足で移動できません。");
  }
  return 0;
}
