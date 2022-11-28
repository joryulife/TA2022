#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for(int i=0;i<n;i++)

int BSearch(int i,int j,int a[],int x){
    int m = (i+j)/2;
    printf("the data to be searched\n");
    rep(k,j-i+1){
        printf("%d ",a[i+k]);
    }
    printf("\n");
    if(a[m] == x){
        return m;
    }else if(x < a[m]){
        return BSearch(i,m-1,a,x);
    }else if(a[m] < x){
        return BSearch(m+1,j,a,x);
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

    printf("Search result:%d\n",BSearch(0,n-1,a,key));
}