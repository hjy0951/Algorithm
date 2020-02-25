// 백준 10809
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[110];
int check[26];
int len;

int main(){
    memset(check,0,sizeof(check));
    scanf("%s", str);

    len = strlen(str);
    
    int cnt = 1;
    for(int i = 0 ; i < len ; i++){
        int cur = str[i] - 'a';
        if(check[cur] == 0){
            check[cur] = cnt;
        }
        cnt++;
    }

    for(int i = 0 ; i < 26 ; i++){
        printf("%d ", check[i] - 1);
    }
    printf("\n");

    return 0;
}
