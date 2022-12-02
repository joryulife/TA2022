//char 64文字 => RC:128B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define N 128
typedef struct rc{
    char pc[N], add[N];
} RC;

int main(){
    RC *za;
    za = (RC*)malloc(125000*sizeof(RC));
    char key[N];
    char * p;
    FILE *fp_ipt;

    fp_ipt = fopen("./pcode-sort.dat","r");
    if(fp_ipt == NULL){
        printf("cant open\n");
        return 0;
    }

    int n = 0;
    while(fgets(za[n].pc,8,fp_ipt)&&(fgets(za[n++].add,128,fp_ipt) != NULL));
    fclose(fp_ipt);

    int tempN = n;
    while(1){
        printf("input search key (end with 'q'):");
        scanf("%s",key);
        if(strcmp(key,"q")){
            int match = 0;
            while(n--){
                if(strcmp(za[n].pc,key)){
                    match = 1;
                    printf("%s\n",za[n].add);
                }
            }
            if(!match){
                printf("該当なし\n");
            }
            n = tempN;
        }else{
            break;
        }
    }
    free(za);
    return 1;
}