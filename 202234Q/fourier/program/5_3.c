#include <stdio.h>
#include <math.h>
#define A -1.0
#define B 1.0

double M = 1600;

double f(double x){
    return 2.0*sqrt(1.0-x*x);
}

int main(){
    double dx = (B-A)/M;
    double xOld,xNew;
    double ans = 0.0;
    for(int i = 0;i < M;i++){
        xOld = A+dx*i;
        xNew = A + dx*(i+1.0);
        ans += (f(xOld)+f(xNew))*dx/2.0;
    }

    printf("|I-PI| = %lf\n",ans);
}

