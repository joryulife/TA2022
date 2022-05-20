#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    scanf("%lf", &x);
    scanf("%lf", &y);

    int i;
    double xx, yy, f, g, fx, fy, gx, gy;

    for(i=0; i<100; i++) {
        f = x*x + y*y -atan(2.0*x+3.0*y);
        g = 2.0*sin(x)-tanh(y);
        fx = 2.0*x - 2.0/((3.0*y + 2.0*x)*(3.0*y + 2.0*x)+1.0);
        fy = 2.0*y - 3.0/((3.0*y + 2.0*x)*(3.0*y + 2.0*x)+1.0);
        gx = 2.0*cos(x);
        gy = -1.0/(cosh(y)*cosh(y));
        xx = x + (-f*gy + fy*g)/(fx*gy-fy*gx);
        yy = y + (-fx*g+f*gx)/(fx*gy-fy*gx);
        printf("%14.13f %14.13f\n", xx,yy);
        if(fabs((xx-x)/x)<1.0e-15&&fabs((yy-y)/y)<1.0e-15){
            break;
        }
        x = xx;
        y = yy;
    }

    return 0;

}