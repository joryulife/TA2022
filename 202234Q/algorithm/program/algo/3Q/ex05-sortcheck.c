#include <stdio.h>
#include <limits.h>

int main(){
    int item;
    int old = INT_MIN;
    while(scanf("%d",&item) != EOF){
        if(item < old){
            printf("Sorted data NOT in ascending order!!\n");
            return 0;
        }else{
            old = item;
        }
    }
    printf("Sorted data in ascending order\n");
    return 0;
}