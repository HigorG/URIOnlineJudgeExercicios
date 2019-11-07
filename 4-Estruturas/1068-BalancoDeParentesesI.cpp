#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(){
   char a;
    while(scanf(" %c", &a)!=EOF){
        int cor = 1 ,par=0, clospar=0;
        while(1){
            if (a=='(') par++;
            else if (a==')') clospar++;
            if (clospar > par) cor = 0;
            a=getchar();
            if(a=='\n'){
                break;
            }
        }
        if(par == clospar && cor) printf("correct\n");
        else printf("incorrect\n");

    }

    return 0;
}
