#include <stdio.h>
#define N 100
#define swap(type,x,y) {type Temp = x;x = y;y = Temp;} //交換用

void part(int a[],int f,int t){
    int p = a[(f+t)/2]; //基準値
    int i = f,j = t;
    while(i<=j){
        while(a[i] < p){
            i++;
        }
        while(a[j] > p){
            j--;
        }
        if(i <= j){
            swap(int,a[i],a[j]);
            i++,j--;
        }
    }
    i = f;
    printf("left part\n");
    for(;i<=(f+t)/2;i++){
        printf("%d ",a[i]);
    }
    printf("\nright part\n");
    for(;i <= t;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){

    int n=0;
    int a[N];
    int temp;

    printf("Input the data (end with Ctrl-D)\n");
    while(scanf("%d",&temp) != EOF){
        a[n++] = temp;
    }

    part(a,0,5);

}