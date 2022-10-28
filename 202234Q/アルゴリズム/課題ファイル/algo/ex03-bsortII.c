#include <stdio.h>
#define N 100
#define swap(type,x,y) {type Temp = x;x = y;y = Temp;} //交換用

int Comp_Count = 0; //比較回数
int Operation_Count = 0; //交換操作回数

void Check(int n,int a[]);

void BSortII(int n,int a[]){
    int last = n-1; //ソート必要区間位置:これより後はソート済

    while(last > 0){
        int new_last = 0;
        for(int i = 0;i < last;i++){
            Comp_Count++;
            if(a[i] > a[i+1]){
                swap(int,a[i],a[i+1]);
                Operation_Count++;
                new_last = i;
            }
        }
        last = new_last;
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

    BSortII(n,a);
    Check(n,a);

    return 0;
}


/*
3_1 2 5: 0:0
1 3_2 5: 1:1
1 2 3_5: 2:2
1_2: 3 5 3:2
1 2:_3 5 4:2
*/

