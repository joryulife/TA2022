#include <stdio.h>

int main(){
    /*int a,b;
    char c,d;
    int* pa,pb,pc,pd;
    int **ppa;
    a =20;

    a = 10;
    printf("a = %d  \n",a);
    pa = &a;
    printf("*pa = &a\n");
    printf("*pa = %d\n",*pa);
    printf("&a = %p\n",&a);
    *pa = 20;
    printf("a = %d  \n",a);
    printf("pa = %p \n",pa);
    printf("&*pa = %p \n",&*pa);
    printf("&pa = %p \n",&pa);
    ppa = &pa;
    **ppa = 30;
    printf("a = %d  \n",a);*/
    int a,*b,*c,*d;
    printf("&pa = %p \n",&a);
    printf("&pb = %p \n",b);
    printf("&pc = %p \n",c);
    printf("&pd = %p \n",d);
    printf("size of (int *)   : %lu\n", sizeof(int *));
}