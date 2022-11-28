#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define rep(i,n) for(int i = 0;i<n;i++)

double T = 2.0;
double N_t = 100.0;
double x_0;

int main(int argc,char *argv[]){
    x_0 = (double)atoi(argv[1]);
    long double dx = T/N_t;
    long double ans[(int)N_t];
    long double f_x_np1,f_x_n;
    f_x_n = x_0;
    rep(i,N_t){
        f_x_np1 = f_x_n + dx * f_x_n;
        printf("%Lf %Lf\n",dx*i,f_x_np1);
        f_x_n = f_x_np1;
    }
}