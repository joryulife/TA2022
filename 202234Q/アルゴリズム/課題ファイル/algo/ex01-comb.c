#include <math.h>
#include <stdio.h>

//2<=1+-2+-3+-4<=8

int main(){
    int num[] = {1,2,3,4};
    int len = sizeof(num) / sizeof(int);
    int sum[(int)pow(2.0,len-1)];
    int sumTemp[(int)pow(2.0,len-1)];

    for(int i = 0;i<len;i++){
        sum[i] =num[i];
    }
    int n_node = 1;

    for(int i = 1; i<len; i++){
    int k = 0;
        for(int j = 0;j < n_node;j++){
            sum[k] = sumTemp[j]+num[i];
            k++;
            sum[k] = sumTemp[j]-num[i];
            k++;
        }
        n_node = k;
        for( int j = 0;j < n_node;j++){
            sumTemp[j] = sum[j];
        }
    }
    int ans = 0;

    for(int i = 0;i < pow(2.0,len-1) ;i++){
        if(sum[i] >=2 && sum[i] <=8){
            ans++;
        }
    }
    printf("There are %d combinations that satisfy the condition\n",ans);
}