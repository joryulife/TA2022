//char 64文字 => RC:128B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
//#define swap(type,x,y) {type Temp = x;x = y;y = Temp;} //交換用
#define swap(type,x,y) {type Temp = *x;*x = *y;*y = Temp;} //交換用
#define N 128

typedef struct rc{
    char pc[N], add[N];
} RC;

/*void struct_swap(RC *x,RC *y){
    RC temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}*/

void BSort(int n,RC za[]){
    int last = n-1;
    while(last > 0){
        int new_last = 0;
        rep(i,last){
            if(strcmp(za[i].pc,za[i+1].pc) > 0){
                swap(RC,&za[i],&za[i+1]);
                new_last = i;
            }
        }
        last = new_last;
    }
}

void QSort(RC za[],int f,int t){
    char p[N];
    strcpy(p,za[(f+t)/2].pc);
    //char *p = za[(f+t)/2].pc; //pivot
    int i = f,j = t;
    while(i<=j){
        while(strcmp(za[i].pc,p) < 0){
            i++;
        }
        while(strcmp(za[j].pc,p) > 0){
            j--;
        }
        if(i <= j){
            swap(RC,&za[i],&za[j]);
            i++,j--;
        }
    }
    if(f < j){
        QSort(za,f,j);
    }
    if(i < t){
        QSort(za,i,t);
    }
}

int main(){
    static RC za[125000];
    //za = (RC*)malloc(125000*sizeof(RC));
    char key[N];
    char * p;
    FILE *fp_ipt,*fp_opt;

    fp_ipt = fopen("./pcode.dat","r");
    if(fp_ipt == NULL){
        printf("cant open\n");
        return 0;
    }

    int n = 0;
    //while(fgets(za[n].pc,8,fp_ipt)&&(fgets(za[n++].add,128,fp_ipt) != NULL));
    while(fscanf(fp_ipt,"%s %s",za[n].pc,za[n].add) != EOF){
        n++;
    };
    fclose(fp_ipt);
    //BSort(n,za);
    QSort(za,0,n-1);
    fp_opt = fopen("pcode-sort-new.dat","w");
    rep(i,n){
        fprintf(fp_opt,"%s %s\n",za[i].pc,za[i].add);
    }
    fclose(fp_opt);
    //free(za);
    return 1;
}