#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
double A = 40.0;
FILE *OutputFile;

//関数
void func(double x, double y, double u, double v, double *fx, double *fy, double *fu, double *fv,double I) {
    *fx = I - 120.0*pow(y,3)*u*(x-115.0)-40.0*pow(v,4)*(x+12.0)-0.24*(x-10.613);
    *fy = (0.1*(25.0-x)/(exp((25.0-x)/10.0)-1.0))*(1.0-y)-4.0*exp(-x/18.0)*y;
    *fu = (0.07*exp((-x/20.0)))*(1.0-u)-(1.0/(exp((30.0-x)/10)+1))*u;
    *fv = (0.01*(10.0-x)/(exp((10.0-x)/10.0)-1.0))*(1.0-v)-0.125*exp(-x/80.0)*v;
}

// Runge-Kutta 法により、LDE を解く
void runge_kutta(double x0, double y0, double u0, double v0, double I0, double f, double NT, double dt) {
    double t, x, y, u, v,I;
    double kx1, kx2, kx3, kx4;
    double ky1, ky2, ky3, ky4;
    double ku1, ku2, ku3, ku4;
    double kv1, kv2, kv3, kv4;

    // 初期値を設定
    t = 0;
    x = x0;
    y = y0;
    u = u0;
    v = v0;

    // Runge-Kutta 法の計算
    rep(i,NT){
        // 各 Runge-Kutta の係数を計算
        I = I0 + A*sin(2.0*M_PI*f*t);
        printf("I:%f t:%f\n",I,t);
        func(x           , y           ,            u,            v, &kx1, &ky1, &ku1, &kv1,I);
        func(x + dt/2*kx1, y + dt/2*ky1, u + dt/2*ku1, v + dt/2*kv1, &kx2, &ky2, &ku2, &kv2,I);
        func(x + dt/2*kx2, y + dt/2*ky2, u + dt/2*ku2, v + dt/2*kv2, &kx3, &ky3, &ku3, &kv3,I);
        func(x + dt*kx3  , y + dt*ky3  , u + dt*ku3  , v + dt*kv3  , &kx4, &ky4, &ku4, &kv4,I);

        // 次の状態を計算
        x += dt / 6 * (kx1 + 2 * kx2 + 2 * kx3 + kx4);
        y += dt / 6 * (ky1 + 2 * ky2 + 2 * ky3 + ky4);
        u += dt / 6 * (ku1 + 2 * ku2 + 2 * ku3 + ku4);
        v += dt / 6 * (kv1 + 2 * kv2 + 2 * kv3 + kv4);
        t += dt;

        // 結果を出力
        if(i > 100){
            fprintf(OutputFile,"%f %f %f\n",x,y,u);
        }
    }
}

int main(int argc, char **argv) {
    int i, j;
    double NT, dt, r, Nx, x0, y0, u0, v0,I0,f;

    // 変数の初期値を設定
    dt = 0.01;
    NT = 100000;
    x0 = -12.0;
    y0 = 0.1;
    u0 = 0.1;
    v0 = 0.5;
    f = 0.3;

    OutputFile = fopen("4_7.dat","w");
    if(OutputFile == NULL){
        printf("cannot open\n");    
        exit(1);
    }
    fprintf(OutputFile,"#x y u\n");
    runge_kutta(x0, y0, u0, v0, I0, f, NT, dt);
    fclose(OutputFile);

    return 0;
}