#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NHASH_LIM 125003

int n = 100000;
int a[100000];
int t[125003];
int m = 125003;
int hashSum = 0;


int MakeHashTable(int n, int m, int a[], int t[]){
    int nhash_max = 0;
    int nhash;
    int v;
    for(int i = 0;i<n;i++){
        v = (a[i])%m;
        nhash = 1;
        while(t[v] && nhash<NHASH_LIM){
            v = ((a[i])%m + nhash)%m;
            nhash++;
        }
        t[v] = a[i];
        if(nhash_max < nhash){
            nhash_max = nhash;
        }
        hashSum += nhash;
    }
    return nhash_max;
}

int main(){
    int nhash_max;
    FILE *fp_ipt,*fp_opt;
    fp_ipt = fopen("./ex04-a.dat","r");
    fp_opt = fopen("./ex04-t.dat","w");
    if((fp_ipt == NULL) || (fp_opt == NULL)){
        printf("can't open\n");
        exit(1);
    }
    int i = 0;
    while(fscanf(fp_ipt,"%d",&a[i++]) != EOF);
    fclose(fp_ipt);
    nhash_max = MakeHashTable(n,m,a,t);
    fprintf(fp_opt,"%d\n",m);
    rep(i,n){
        fprintf(fp_opt,"%d\n",t[i]);
    }
    printf("m:%d\navg.nhash:%3.1lf\nnhash_max:%d\n",m,(double)hashSum/(double)n,nhash_max);
    fclose(fp_opt);
}