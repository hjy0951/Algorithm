// 백준 1152
// strtok 사용법 익히기

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char str[1000100];

int main(){
    scanf("%[^\n]s", str);

    int cnt = 0;
    char* ptr = strtok(str," ");

    while(ptr != NULL){
        ptr = strtok(NULL," ");
        cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
