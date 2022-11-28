#include <stdio.h>
#define rep(i, n) for(int i=0;i<(int)(n);i++)
int N,P,CNT;

void visit(int q[],int i){
    
    if(i == N){
        rep(j,N){
            printf("(%d,%d)",j,q[j]);
        }
        printf("\n");
        CNT++;
        return;
    }
    rep(j,P){
        q[i] = j;
        visit(q,i+1);
    }
}

int main(){
    printf("NxPのN, Pを入力（20以下）:");
    scanf("%d %d",&N,&P);
    int q[N];
    rep(i,N){
        q[i] = 0;
    }
    visit(q,0);
    printf("CNT:%d\n",CNT);
    return 0;
}
