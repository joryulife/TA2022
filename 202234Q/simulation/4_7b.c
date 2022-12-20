#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
FILE *OutputFile;

//関数
void func(double x, double y, double u, double v, double *fx, double *fy, double *fu, double *fv,double I) {
    *fx = I-120.0*y*y*y*u*(x-115.0)-40.0*v*v*v*v*(x+12.0)-0.24*(x-10.613);
    *fy = ((0.1*(25.0-x))/(exp((25-x)/10.0)-1.0))*(1-y)-4.0*exp((-x)/18.0)*y;
    *fu = 0.07*exp((-x)/20.0)*(1.0-u)-1/(exp((30.0-x)/10.0)+1.0)*u;
    *fv = ((0.01*(10.0-x))/(exp((10.0-x)/10.0)-1.0))*(1.0-v)-0.125*exp(-x/80.0)*v;
}

void runge_kutta( double NT, double dt,double x0, double y0, double u0, double v0, double I0,double A, double f) {
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
        func(x             , y             , u             , v             , &kx1, &ky1, &ku1, &kv1,I);
        func(x + dt*kx1/2.0, y + dt*ky1/2.0, u + dt*ku1/2.0, v + dt*kv1/2.0, &kx2, &ky2, &ku2, &kv2,I);
        func(x + dt*kx2/2.0, y + dt*ky2/2.0, u + dt*ku2/2.0, v + dt*kv2/2.0, &kx3, &ky3, &ku3, &kv3,I);
        func(x + dt*kx3    , y + dt*ky3    , u + dt*ku3    , v + dt*kv3    , &kx4, &ky4, &ku4, &kv4,I);

        // 次の状態を計算
        x += dt*(kx1 + 2 * kx2 + 2 * kx3 + kx4)/ 6.0 ;
        y += dt*(ky1 + 2 * ky2 + 2 * ky3 + ky4)/ 6.0 ;
        u += dt*(ku1 + 2 * ku2 + 2 * ku3 + ku4)/ 6.0 ;
        v += dt*(kv1 + 2 * kv2 + 2 * kv3 + kv4)/ 6.0 ;
        t = i*dt;

        // 結果を出力
        if(t > 100){
            fprintf(OutputFile,"%f %f %f\n",x,y,u);
        }
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

    x0 = -12.0;
    y0 = 0.1;
    u0 = 0.1;
    v0 = 0.5;

    I0 = 20.0;
    A = 40.0;
    f = 0.3;
    scanf("%lf",&f);
    
    sprintf(filename,"4_7b.dat");
    OutputFile = fopen(filename,"w");
    if(OutputFile == NULL){
        printf("cannot open\n");    
        exit(1);
    }
    fprintf(OutputFile,"#x y u\n");

    runge_kutta(NT, dt, x0, y0, u0, v0, I0, A, f);

    fclose(OutputFile);

    return 0;
}