#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
int N = 64;

int BSearch(int n,char a[][N],char x[N]){
    int i = 0,j = n-1;
    int m;
    while(i <= j){
        m = (i+j)/2;
        if(strcmp(a[m],x) == 0){
            return m;
        }else if(strcmp(a[m],x) > 0){
            j = m-1;
        }else if(strcmp(a[m],x) < 0){
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
    char a[n][N],temp[N];
    int i = 0;
    int nTemp = n;
    while(nTemp--){
        scanf("%s",a[i++]);
    }

    char key[N];
    printf("Input the search key:");
    scanf("%s",key);

    printf("Search result:%d\n",BSearch(n,a,key));
}