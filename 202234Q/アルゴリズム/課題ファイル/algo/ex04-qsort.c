#include <stdio.h>
#define N 100
#define swap(type,x,y) {type Temp = x;x = y;y = Temp;} //交換用

void QSort(int a[],int f,int t){
    printf("target data\n");
    for(int i = f;i <= t;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int p = a[(f+t)/2]; //pivot
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
    if(f < j){
        QSort(a,f,j);
    }
    if(i < t){
        QSort(a,i,t);
    }

}

int main(){

    int n=0;
    int a[N];
    int temp;

    printf("Input the data (end with Ctrl-D)\n");
    while(scanf("%d",&temp) != EOF){
        a[n++] = temp;
    }

    QSort(a,0,n-1);
    printf("Sorted data\n");
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}