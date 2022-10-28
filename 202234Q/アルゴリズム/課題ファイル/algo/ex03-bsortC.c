#include <stdio.h>
#define N 100
#define swap(type,x,y) {type Temp = x;x = y;y = Temp;}

int Comp_Count = 0;
int Operation_Count = 0;

void BSort(int n,int a[]){

    for(int i = 0; i < n-1;i++){
        for(int j = 0; j < n-1-i; j++){
            Comp_Count++;
            if(a[j] > a[j+1]){
                Operation_Count++;
                swap(int,a[j],a[j+1]);
            }
        }
    }
}

void Check(int n,int a[]){
    printf("Sorted data\n");
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Number of Comparing: %d \n",Comp_Count);
    printf("Number of Exchanging: %d \n",Operation_Count);
}

int main(){
    int n=0;
    int a[N];
    int temp;

    printf("Input the data (end with Ctrl-D)\n");
    while(scanf("%d",&temp) != EOF){
        a[n++] = temp;
    }

    BSort(n,a);
    Check(n,a);

    return 0;
}