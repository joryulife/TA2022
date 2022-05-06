#include <stdio.h>

int main(void){
    char name[48];

    printf("お名前は:");
    scanf("%s",name);
    //scanf("%s",&name[0]);
    printf("こんにちは、%sさん!!\n",name);
    //printf("こんにちは、%sさん!!\n",&name[0]);
    return 0;
}