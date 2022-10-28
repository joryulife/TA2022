#include <math.h>
#include <stdio.h>

//a1+-a2+-a3+-a4>=v

int a[4];
int v;
int sign[] = {-1,1};
int v1[2],v2[4];
int ans = 0;

int main(){
    printf("a1+-a2+-a3+-a4>=v\nPlease enter a1~a4 separated by spaces.\n");
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    printf("Please enter v.\n");
    scanf("%d",&v);

    for(int i = 0;i<2;i++){
        v1[i] = a[0] + sign[i]*a[1];
        for(int j = 0;j<2;j++){
            v2[i*2+j] = sign[j]*a[2] + sign[i]*a[3];
        }
    }

    for(int i = 0;i<2;i++){
        for(int j = 0;j<4;j++){
            if(v1[i] + v2[j] >= 2) ans++;
        }
    }

    printf("There are %d combinations that satisfy the condition\n",ans);
}