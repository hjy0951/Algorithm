// 백준 3085 사탕 게임
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
char map[51][51];
int maxcandy;

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void check(int y, int x){
    char cur = map[y][x];
    int cy = y;
    int cx = x-1;
    int cnt = 1;
    
    while(1){
        if(cx < 0) break;
        if(map[cy][cx] != cur) break;

        cnt++;
        cx--;
    }
    cx = x+1;
    while(1){
        if(cx >= n) break;
        if(map[cy][cx] != cur) break;

        cnt++;
        cx++;
    }

    maxcandy = max(maxcandy, cnt);

    cy = y-1;
    cx = x;
    cnt = 1;

    while(1){
        if(cy < 0) break;
        if(map[cy][cx] != cur) break;

        cnt++;
        cy--;
    }
    cy = y+1;
    while(1){
        if(cy >= n) break;
        if(map[cy][cx] != cur) break;

        cnt++;
        cy++;
    }

    maxcandy = max(maxcandy, cnt);
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < n ; j++){
            map[i][j] = str[j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            char temp = map[i][j];
            map[i][j] = map[i][j-1];
            map[i][j-1] = temp;

            check(i,j);
            check(i,j-1);

            temp = map[i][j];
            map[i][j] = map[i][j-1];
            map[i][j-1] = temp;
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp = map[i][j];
            map[i][j] = map[i-1][j];
            map[i-1][j] = temp;

            check(i,j);
            check(i-1,j);

            temp = map[i][j];
            map[i][j] = map[i-1][j];
            map[i-1][j] = temp;
        }
    }

    cout << maxcandy << '\n';
    
    return 0;
}