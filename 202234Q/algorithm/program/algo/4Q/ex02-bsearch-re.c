#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for(int i=0;i<n;i++)

int BSearch(int i,int j,int a[],int x){
    printf("the data to be searched\n");
    rep(k,j-i+1){
        printf("%d ",a[i+k]);
    }
    printf("\n");
    int m = (i+j)/2;
    return i>j ? -1 : a[m] == x ? m : x < a[m] ? BSearch(i,m-1,a,x) : a[m] < x ? BSearch(m+1,j,a,x) : -1;
}

int main(){
    int n;
    printf("Input the number of  data:");
    scanf("%d",&n);

    printf("Input the data\n");
    int a[n];
    rep(i,n){
        scanf("%d",&a[i++]);
    }
    int key;
    printf("Input the search key:");
    scanf("%d",&key);

    printf("Search result:%d\n",BSearch(0,n-1,a,key));
}