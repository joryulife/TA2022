#include <stdio.h>
#define N 100

//昇順 EX 1 2 3 ... 98 99
//降順 EX 99 98 97 ... 2 1

void SSort(int n,int a[]){
    int max,no,temp,done=n-1;
    while(done > 0){
        max = a[done],no = done;
        for(int j = done-1;j>=0;j--){
            if(max < a[j]){
                max = a[j];
                no = j;
            }
        }
        if(no != done){
            temp = a[done];
            a[done] = a[no];
            a[no] = temp;
        }
        done--;
        // for debug
        /*
        for(int i = 0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");*/
    }
}
/*
void SSort2(int n,int a[]){
    int max,no,temp,done=0;
    while(done < n-1){
        max = a[done],no = done;
        for(int j = done+1;j<n;j++){
            if(max < a[j]){
                max = a[j];
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
    int b[n];
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = b[n-1-i];
    }
}
*/

int main(){
    printf("Input the data\n");
    //Enter a sequence of numbers separated by spaces. When you have finished typing, Ctrl+D after Enter
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