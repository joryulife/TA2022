#include <stdio.h>

#include <ctype.h>

void prvword(const char s[]){
    //a初期化
    int a = 0;
    //文字列の長さ格納
    while(s[a]){
        a++;
    }

    //与えられた文字列をi=0->aまで走査
    for(int i=0; i<a; i++){
        //スペースならスペースを出力
        if(isspace(s[i])){
            putchar(s[i]);
        }//alphabetか数字なら
        else if(isalnum(s[i])){
            int j=i;
            //スペースじゃないときj++ ==> スペースなら止める ==>文字列の最後がスペースじゃなく'\0'ならカウントが止まらない
            while(!isspace(s[j]) && s[j] != '\0'){ 
                j++;
            }
            for(int h=j-1; h>=i; h--){
                putchar(s[h]);
            }
            i = j; 
        }
        else if(s[i] == '\0'){
            break;
        }
    }

}

void test(const char s[]){
    printf("\"%s\" -> \"", s);
    prvword(s);
    printf("\"\n");
}

int main(void){
    test("12345");
    test("   ABC  DEF  GHI  ");
    test("Hello World Login Incorrect");
    test("NUMATA MITSUKI");
    test("Y210067 NUMATA MITSUKI");
    return 0;
}