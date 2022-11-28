#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for(int i=0;i<(int)(n);i++)

int N = 8 , P = 8;
int CNT_ALL=0,CNT=0;

void printq(int q[]){
    rep(i,N){
        printf("%d ",q[i]);
    }
    printf("\n");
}

int check(int q[]){
    rep(i,N){
        rep(j,P){
            if(i != j && (q[i]==q[j] || abs(q[i]-q[j]) == abs(i-j) )){
                return 0;
            }
        }
    }
    return 1;
}

void visit(int q[],int i){
    if(i == N){
        CNT_ALL++;
        if(check(q)){
            CNT++;
            printq(q);
        }
        return;
    }
    rep(j,P){
        q[i] = j;
        visit(q,i+1);
    }
}

int main(){
    int q[N];
    rep(i,N){
        q[i] = 0;
    }
    visit(q,0);
    printf("CNT_ALL:%d,CNT:%d\n",CNT_ALL,CNT);
    return 0;
}