#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for(int i=0;i<(int)(n);i++)

int N = 8 , P = 8;
int CNT_ALL=0,CNT=0;
int Q[100];
int board[100][100];

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
        if(!board[i][j]){
            q[i] = j;
            board[i+1][abs(j-1)] = 1;
            board[i+1][j] = 1;
            board[i+1][P-1-abs(j+2-P)] = 1;
            visit(q,i+1);
            board[i+1][abs(j-1)] = 0;
            board[i+1][j] = 0;
            board[i+1][P-1-abs(j+2-P)] = 0;
        }
    }
}

/*
    ./a.out > 8queen.lis
    =>8x8

    ./a.out N > 8queen.lis
    =>NxN 

    ./a.out N P > 8queen.lis
    =>NxP
*/
int main(int argc, char *argv[]){

    if(argc == 2){
        N = P = atoi(argv[1]);
    }else if(argc >= 3){
        N = atoi(argv[1]);
        P = atoi(argv[2]);
    }

    visit(Q,0);
    printf("CNT_ALL:%d,CNT:%d\n",CNT_ALL,CNT);
    return 0;
}