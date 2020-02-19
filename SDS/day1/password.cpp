// 백준 : 1759 암호 만들기
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int l,c;
char a[15];
char ans[15];
char mo[27];
char ja[27];

void find(int idx, int n){
    if(n == l){
        int jn = 0;
        for(int i = 0 ; i < l ; i++){
            char cur = ans[i];
            if(ja[cur - 'a'] == 1) jn++;
            if(jn >= 2) break;
        }
        int mn = 0;
        for(int i = 0 ; i < l ; i++){
            char cur = ans[i];
            if(mo[cur - 'a'] == 1) mn++;
            if(mn >= 1) break;
        }
        if(jn >= 2 && mn >= 1) printf("%s\n", ans);
    }
    else{
        for(int i = idx+1 ; i < c - l + n + 1 ; i ++){
            ans[n] = a[i];
            find(i,n+1);
        }
    }
}

int main(){
    // cin >> l >> c;
    scanf("%d %d" , &l,&c);
    for(int i = 0 ; i < c ; i++){
        // cin >> a[i];
        scanf(" %c", &a[i]);
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') mo[a[i] - 'a'] = 1;
        else ja[a[i] - 'a'] = 1;
    }

    sort(a, a+c); // 알파벳 정렬

    for(int i = 0 ; i < c - l + 1 ; i++){
        ans[0] = a[i];
        find(i,1);
    }
    
    return 0;
}