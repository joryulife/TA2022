#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define N 64

int main(){
    char key[N];
    char line[N];
    char * p;
    FILE *fp_ipt;

    fp_ipt = fopen("./pcode.dat","r");
    if(fp_ipt == NULL){
        printf("cant open\n");
        return 0;
    }

    while(1){
        printf("input search key (end with 'q'):");
        scanf("%s",key);
        if(strcasecmp(key,"q")){
            while(fgets(line, N, fp_ipt) != NULL){
                p = strstr(line,key);
                if(p != NULL){
                    printf("%s",line);
                }
            }
            rewind(fp_ipt);
        }else{
            break;
        }
    }

    fclose(fp_ipt);
    return 1;
}