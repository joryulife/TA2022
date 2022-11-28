#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for(int i=0;i<n;i++)

int BSearch(int n,int a[],int x){
    int i = 0,j = n-1;
    int m;
    while(i <= j){
        m = (i+j)/2;
        printf("the data to be searched\n");
        rep(k,j-i+1){
            printf("%d ",a[i+k]);
        }
        printf("\n");
        if(a[m] == x){
            return m;
        }else if(x < a[m]){
            j = m-1;
        }else if(a[m] < x){
            i = m+1;
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

    printf("Search result:%d\n",BSearch(n,a,key));
}