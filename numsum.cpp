#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char num[110];
int n;

int main(){
    memset(num,0,sizeof(num));
    scanf("%d", &n);
    
    scanf("%s", num);
    // for(int i = 0 ; i < n ; i++){
    //     scanf("%1c", &num[i]);
    // }

    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += (num[i] - '0');
    }

    printf("%d\n", sum);

    return 0;
}