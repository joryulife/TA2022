#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *fp1,*fp2;
    //fp1 = fopen("./4_7_1.dat","r");
    //fp2 = fopen("./4_7_2.dat","r");
    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"r");
    char A[128];
    char B[128];

    for(int i = 0;;i++){
        fgets(A,128,fp1);
        fgets(B,128,fp2);
        if(strcmp(A,B) !=0){
            printf("A:%s\n",A);
            printf("B:%s\n",B);
            printf("line %d\n",i);
            break;
        }
    }

    return 1;
}