#include <stdio.h>

int count_bits(unsigned x){
    int bits = 0;
    while(x){
        if(x & 1U){ //1U = 0001　
            bits++;
        }
        x >>=1; //x=x>>1 1111 0111 0011 0001 0000
    }
    return bits;
}

int int_bits(void){
    return count_bits(~0U); //U:変数設備語　符号なし ~0U ~(0000)=1111
}

void print_bits(unsigned x){
    for(int i = int_bits() -1;i >= 0;i--){
        putchar(((x>>i)&1U)?'1':'0');
    }
}

int main(void){
    unsigned a,b;
    printf("非負の整数を二つ入力せよ。\n");
    printf("a:"); scanf("%u",&a);
    printf("b:"); scanf("%u",&b);

    putchar('\n');
    printf("a     = ");     print_bits(a);      putchar('\n');
    printf("b     = ");     print_bits(b);      putchar('\n');
    printf("a & b = ");     print_bits(a&b);    putchar('\n');
    printf("a | b = ");     print_bits(a|b);    putchar('\n');
    printf("a ^ b = ");     print_bits(a^b);    putchar('\n');
    printf("~a    = ");     print_bits(~a);     putchar('\n');
    printf("~b    = ");     print_bits(~b);     putchar('\n');

    return 0;
}