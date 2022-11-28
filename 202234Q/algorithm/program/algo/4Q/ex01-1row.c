#include <stdio.h>
int N = 8;

void visit(int q[],int i){
    for(int i=0;i<N;i++){
        printf("%2d ",q[i]);
    }
    printf("\n");
    if(i == N){
        return;
    }
    q[i] = 0;
    visit(q,i+1);
}

int main(){
    int q[N];
    for(int i=0;i<N;i++){
        q[i] = -1;
    }

    visit(q,0);
    return 0;
}
