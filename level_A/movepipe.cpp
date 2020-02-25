// 백준 17070 파이프 옮기기 1
#include <iostream>

using namespace std;

int n;
int map[20][20];
int way;

void dfs(int y, int x, int dir){ // dir = 1: 가로 | 2 : 세로 | 3 : 대각선
    if(map[y][x] == 1) return;
    else if(y == n-1 && x == n-1){
        way++;
        return;
    }
    else{
        if(dir == 1){ // 가로
            if(x+1 < n && map[y][x+1] == 0) dfs(y, x+1, 1);
            if(y+1 < n && x+1 < n && map[y+1][x] == 0 && map[y+1][x+1] == 0 && map[y][x+1] == 0)
                dfs(y+1, x+1, 3);
        }
        else if(dir == 2){ // 세로
            if(y+1 < n && x+1 < n && map[y+1][x] == 0 && map[y+1][x+1] == 0 && map[y][x+1] == 0)
                dfs(y+1, x+1, 3);
            if(y+1 < n && map[y+1][x] == 0) dfs(y+1, x, 2);
        }
        else{ // 대각선
            if(x+1 < n && map[y][x+1] == 0) dfs(y, x+1, 1);
            if(y+1 < n && x+1 < n && map[y+1][x] == 0 && map[y+1][x+1] == 0 && map[y][x+1] == 0)
                dfs(y+1, x+1, 3);
            if(y+1 < n && map[y+1][x] == 0) dfs(y+1, x, 2);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    dfs(0, 1, 1); // 가로 시작

    cout << way << "\n";
    return 0;
}
