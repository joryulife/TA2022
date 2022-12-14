#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i = 0;i < n;i++)

double A[] = { 1, 2,-1, 1,-1, 1, 0, 0, 0, 1, 0,-1, 1, 0,-1};
double B[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
double C[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1};
double D[] = { 2, 1,-2, 1,-1,-1, 1,-1, 0, 1, 0,-1, 1, 0,-1};

FILE *OutputFile;
double a,b,c,d;

// LDE の右辺を表す関数
void f(double x, double y, double *fx, double *fy) {
    *fx = a*x + b*y;
    *fy = c*x + d*y;
}

// Runge-Kutta 法により、LDE を解く
void runge_kutta(double x0, double y0, double T, double dt) {
    int i;
    double t, x, y, kx1, kx2, kx3, kx4, ky1, ky2, ky3, ky4;

    // 初期値を設定
    t = 0;
    x = x0;
    y = y0;

    // Runge-Kutta 法の計算
    rep(i,(int)(T / dt)){
        // 各 Runge-Kutta の係数を計算
        f(x           , y           , &kx1, &ky1);
        f(x + dt/2*kx1, y + dt/2*ky1, &kx2, &ky2);
        f(x + dt/2*kx2, y + dt/2*ky2, &kx3, &ky3);
        f(x + dt*kx3  , y + dt*ky3  , &kx4, &ky4);

        // 次の状態を計算
        x += dt / 6 * (kx1 + 2 * kx2 + 2 * kx3 + kx4);
        y += dt / 6 * (ky1 + 2 * ky2 + 2 * ky3 + ky4);
        t += dt;

        // 結果を出力
        fprintf(OutputFile,"%f %f\n",x,y);
    }
}

int main(int argc, char **argv) {
    int i, j;
    double T, dt, r, Nx, x0, y0;

    // 変数の初期値を設定
    T = 1;
    dt = 0.01;
    r = 10;
    Nx = 8;

    // 初期値を変化させながら Runge-Kutta 法を実行
    rep(k,12){
        a=A[k],b=B[k],c=C[k],d=D[k];
        char filename[64];
        sprintf(filename,"3_4_%d.dat",k);
        OutputFile = fopen(filename,"w");
        if(OutputFile == NULL){
            printf("cannot open\n");    
            exit(1);
        }
        rep(i,Nx+1) {
            rep(j,Nx+1) {
                x0 = -r + 2*r*i/ Nx;
                y0 = -r + 2*r*j/ Nx;
                runge_kutta(x0, y0, T, dt);
                fprintf(OutputFile,"\n");
            }
        }
        fclose(OutputFile);
    }

    return 0;
}