#include <stdio.h>
#include <math.h>

double dist(double x1, double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main(void){
    double x1,y1;
    double x2,y2;

    printf("2点間の距離を求めます。\n");
    printf("点１・・・X座標:");    scanf("%lf",&x1);
    printf("　　　　　Y座標:");    scanf("%lf",&y1);
    printf("点２・・・X座標:");    scanf("%lf",&x2);
    printf("　　　　　X座標:");    scanf("%lf",&y2);

    printf("距離は%lfです。\n",dist(x1,y1,x2,y2));

    return 0;
}