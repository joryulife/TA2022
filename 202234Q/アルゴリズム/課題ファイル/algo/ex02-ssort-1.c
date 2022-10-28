#include <stdio.h>
#define N 100

void SSort(int n,int a[]){
    int min,no,temp,done=0;
    while(done < n-1){
        min = a[done],no = done;
        for(int j = done+1;j<n;j++){
            if(min > a[j]){
                min = a[j];
                no = j;
            }
        }
        if(no != done){
            temp = a[done];
            a[done] = a[no];
            a[no] = temp;
        }
        done++;
    }
}

int main(){
    printf("Input the data\n");
    int n = 0,temp;
    int a[N];

    while(scanf("%d",&temp) != EOF){
        a[n++] = temp;
    }

    printf("\n");
    printf("Sorted data\n");

    SSort(n,a);
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}