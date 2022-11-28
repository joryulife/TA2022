#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for(int i=0;i<n;i++)

int LSearch(int n,int a[],int x){
    rep(i,n){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Input the number of  data:");
    scanf("%d",&n);

    printf("Input the data\n");
    int a[n],i=0,temp;
    int N=n;
    while(N--){
        scanf("%d",&a[i++]);
    }
    int key;
    printf("Input the search key:");
    scanf("%d",&key);
    printf("%d\n",key);

    printf("Search result:%d\n",LSearch(n,a,key));
}