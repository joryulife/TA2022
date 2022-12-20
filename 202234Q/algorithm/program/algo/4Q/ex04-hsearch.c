#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int nhash;

int HashSearch(int m, int t[], int x){
    int v;
    v = (x)%m;
    nhash = 1;
    while(t[v] && x != t[v]){
        v = (x%m + nhash)%m;
        nhash++;
    }
    printf("nhash %d\n",nhash);
    return t[v]==x?v:-1;
}

int main(){
    FILE *fp_ipt = fopen("./ex04-t.dat","r");
    if(fp_ipt == NULL){
        printf("can't open\n");
        exit(1);
    }
    int m;
    fscanf(fp_ipt,"%d",&m);
    int t[m];
    int i=0;
    while(fscanf(fp_ipt,"%d",&t[i++]) != EOF);
    fclose(fp_ipt);

    int key;
    printf("Input the search key (end with -99):");
    scanf("%d",&key);

    printf("Search result: %d\n",HashSearch(m,t,key));
}