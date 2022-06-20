#include <stdio.h>
#include <math.h>
#define esp 1.0e-15

int main() {

    double ex,ans=1.0,xx,x,n;
    scanf("%lf",&x);
    n=1.0;
    ex=0.0;

    for(int i=1;i<100;i++){
        xx=ans;
        n=n*i;
        ex=pow(x,i)/n;
        ans=ans+ex;
        printf("%15.14f\n",ans);
        if(fabs((ans-xx)/xx)<esp) break;
    }
    return 0;
}