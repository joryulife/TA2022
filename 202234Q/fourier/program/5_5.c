#include <stdio.h>
#include <math.h>
#define A -M_PI
#define B M_PI

double M = 100;
double dx = (B-A)/100.0;

double f(double x){
    return 10.0 + cos(x) + sin(x) + 2.0*cos(2.0*x) + (1.0/2.0)*sin(2.0*x) + 3.0*cos(3.0*x) + (1.0/3.0)*sin(3.0*x);  
}

int Integrate(double fx){
    
}

double a0(){
    double ans = 0;
    for(double i = 0.0;i<M;i++){
        ans +=f(A+dx*i)*dx;
    }
    
}

double ak(double x){

}

int main(){
    
    double xOld,xNew;
    double ans = 0.0;
    for(double i = 0;i < M;i++){
        xOld = A+dx*i;
        xNew = A + dx*(i+1.0);
        ans += (f(xOld)+f(xNew))*dx/2.0;
    }

    printf("|I-PI| = %lf\n",ans);
}

