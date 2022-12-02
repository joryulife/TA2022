//char 64文字 => RC:128B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define swap(type,x,y) {type Temp = *x;*x = *y;*y = Temp;} //交換用
#define N 128


//用途を考えるならpc[8](7桁+'\0')が望ましい。
typedef struct rc{
    char pc[N], add[N];
} RC;

void BSort(int n,RC za[]);
void QSort(RC za[],int f,int t);

//講義資料手順版
int main(){
    char key[N];
    char * p;
    char line[N];
    FILE *fp_ipt,*fp_opt;

    fp_ipt = fopen("./pcode.dat","r");
    if(fp_ipt == NULL){
        printf("cant open\n");
        return 0;
    }
    while(1){
        printf("input search key (end with 'q'):");
        scanf("%s",key);
        if(!strcmp(key,"q")){
            break;
        }
        while(fgets(line, sizeof(line), fp_ipt) != NULL){
            p = strstr(line,key);
            if(p != NULL){
                if(p == line){
                    printf("%s",line+8);
                }else{
                    line[7]='\0';
                    printf("%s\n",line);
                }
            }
        }
        rewind(fp_ipt);
    }
    fclose(fp_ipt);
    return 1;
}

//M2向け ・fscanfを使い ・構造体を使わず ・読み分ける ver
/*
int main(void)
{
	FILE *fp_ipt;
	char pc[N];
    char add[N];
    char key[N];

	fp_ipt=fopen("./pcode.dat", "r");
    if(fp_ipt == NULL){
        printf("cant open\n");
        return 0;
    }
    while(1){
        printf("input postal code (end with q):");
        scanf("%s" , key);
        if(!strcmp(key,"q")){
            break;
        }
        while(fscanf(fp_ipt, "%s %s", pc, add) != EOF){
            switch (strstr(pc,key)==NULL?strstr(add,key)==NULL?0:1:2){
                case 1:printf("%s\n",pc);break;
                case 2:printf("%s\n",add);break;
                default:break;
            }
        }
        rewind(fp_ipt);
    }
	fclose(fp_ipt);
	return 0;
}
*/

//空白 , " ' 対応ver
/*
int main(){
    char key[N];    //検索word
    char line[N];   //一括読み込み用
    char pc[N];
    char add[N];
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
        if(!strcmp(key,"q")){
            break;
        }
        while(fgets(line,sizeof(line),fp_ipt)!= NULL){
            int i = 0;
            p = line;
            while(p!=NULL){
                switch(strstr(line,",")==NULL?strstr(line," ")==NULL?strstr(line,"\"")==NULL?strstr(line,"\'")==NULL?4:3:2:1:0){
                case 0:p = strstr(line,",");break;
                case 1:p = strstr(line," ");break;
                case 2:p = strstr(line,"\"");break;
                case 3:p = strstr(line,"\'");break;
                default:p = NULL;break;
                }
                if(p!=NULL){
                    char temp[N];
                    strcpy(temp,p+1);
                    strcpy(p,temp);
                }
            }
            strncpy(pc,line,7);
            pc[7] = '\0';
            strcpy(add,line+7);
            switch (strstr(pc,key)==NULL?strstr(add,key)==NULL?0:1:2){
                case 1:printf("%s\n",pc);break;
                case 2:printf("%s",add);break;
                default:break;
            }
        }
        rewind(fp_ipt);
    }
    fclose(fp_ipt);
    return 1;
}
*/


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