#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
FILE *OutputFile;
double V0 = 10;
double theta;
double k = 1;
double m = 1;
double g = 1;

//関数
void func(double x, double y, double u, double v, double *fx, double *fy, double *fu, double *fv, double t) {
    *fx = V0*cos(theta)*exp(-(k/m)*t);
    *fy = -(m/k)*g + ((m/k)*g + V0*cos(theta))*exp(-(k/m)*t);
    *fu = -(m/k)*V0*cos(theta)*exp(-(k/m)*t);
    *fv = (-g-(k/m)*V0*sin(theta))*exp(-(k/m)*t);
}

void runge_kutta( double NT, double dt,double x, double y, double u, double v) {
    double t;
    double kx1, kx2, kx3, kx4;
    double ky1, ky2, ky3, ky4;
    double ku1, ku2, ku3, ku4;
    double kv1, kv2, kv3, kv4;

    // 初期値を設定
    t = 0;

    // Runge-Kutta 法の計算
    rep(i,NT){
        // 各 Runge-Kutta の係数を計算
        func(x             , y             , u             , v             , &kx1, &ky1, &ku1, &kv1,t);
        func(x + dt*kx1/2.0, y + dt*ky1/2.0, u + dt*ku1/2.0, v + dt*kv1/2.0, &kx2, &ky2, &ku2, &kv2,t);
        func(x + dt*kx2/2.0, y + dt*ky2/2.0, u + dt*ku2/2.0, v + dt*kv2/2.0, &kx3, &ky3, &ku3, &kv3,t);
        func(x + dt*kx3    , y + dt*ky3    , u + dt*ku3    , v + dt*kv3    , &kx4, &ky4, &ku4, &kv4,t);

        // 次の状態を計算
        x += dt*(kx1 + 2 * kx2 + 2 * kx3 + kx4)/ 6.0 ;
        y += dt*(ky1 + 2 * ky2 + 2 * ky3 + ky4)/ 6.0 ;
        u += dt*(ku1 + 2 * ku2 + 2 * ku3 + ku4)/ 6.0 ;
        v += dt*(kv1 + 2 * kv2 + 2 * kv3 + kv4)/ 6.0 ;
        t = i*dt;

        // 結果を出力
        fprintf(OutputFile,"%f %f %f %f\n",x,y,u,v);
    }
}

int main(int argc, char **argv) {
    double dt, T, NT;
    double x0, y0, u0, v0;
    double I0, A, r, f;
    char filename[64];

    // 変数の初期値を設定
    dt = 0.01;
    T = 1000.0;
    NT = T/dt;

    x0 = 0.0;
    y0 = 0.0;
    u0 = V0 * cos(theta);
    v0 = V0 * sin(theta);

    theta = 0.3;
    scanf("%lf",&theta);
    theta = theta * M_PI /180.0;
    sprintf(filename,"5_4_1.dat");
    OutputFile = fopen(filename,"w");
    if(OutputFile == NULL){
        printf("cannot open\n");    
        exit(1);
    }
    fprintf(OutputFile,"#x y u v\n");

    runge_kutta(NT, dt, x0, y0, u0, v0);

    fclose(OutputFile);

    return 0;
}