#include <stdio.h>
#include <ctype.h>

void prvword(const char s[]) {
    int i = 0;
    for (;;) {
        if (s[i] == '\0') {
            break;
        }
        while(isspace(s[i])){
            putchar(s[i]);
            i++;
        }
        /* 単語の終わり j を見つける */
        int j = i;
        while(!isspace(s[j]) && (s[j] != '\0')){
            j++;
        }
        /* 単語を逆順で表示 */
        for (int k = j-1; k >= i; k--) {
            putchar(s[k]);
        }
        /* 単語の次の文字から表示 */
        i = j;
    }
}

void test(const char s[]) {
    /*元を表示*/
    printf("\"%s\"  ->  \"", s);  
    prvword(s);
    printf("\"\n");
}  
void test2(const char *s) {
    /*元を表示*/
    printf("\"%s\"  ->  \"", s);  
    prvword(s);
    printf("\"\n");
}  
void test3(const char s[]) {
    /*元を表示*/
    printf("\"%s\"  ->  \"", &s[0]);  
    prvword(s);
    printf("\"\n");
}  
void test4(const char *s) {
    /*元を表示*/
    printf("\"%s\"  ->  \"", &s[0]);  
    prvword(s);
    printf("\"\n");
}  
void test5(const char *s) {
    /*元を表示*/
    printf("\"%s\"  ->  \"", &s[1]);  
    prvword(s);
    printf("\"\n");
} 

int main(void)
{
    test("12345"); 
    test2("   ABC  DEF  GHI  "); 
    test3("Hello World Login Incorrect"); 
    test4("OHMI MAIKO");         /*(自分の) 名前 */
    test5("Y190123 OHMI MAIKO"); /*(自分の) 学籍 名前 */
    return 0;
}