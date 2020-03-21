// SWEA 7699 수지의 수지 맞는 여행
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

char map[25][25];
int visit[25][25];
int alpha[27];
int r,c;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int maxcnt;

void print(){
    cout << "\n";
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void dfs(int y, int x, int cnt){
    if(visit[y][x] == 1 || alpha[map[y][x] - 'A'] == 1){
        maxcnt = max(cnt,maxcnt);
        return;
    }
    else{
        visit[y][x] = 1;
        alpha[map[y][x] - 'A'] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                dfs(ny,nx, cnt+1);
            }
        }
        alpha[map[y][x] - 'A'] = 0;
        visit[y][x] = 0;
    }
}

int main(){
    int t;
    cin >> t;
    for(int x = 1 ; x <= t ; x++){
        cin >> r >> c;
        for(int i = 0 ; i < r ; i++){
            string str;
            cin >> str;
            for(int j = 0 ; j < c ; j++){
                map[i][j] = str[j];
            }
        }

        dfs(0,0,0);

        cout << "#" << x << " " << maxcnt << "\n";
        memset(visit,0,sizeof(visit));
        memset(alpha,0,sizeof(alpha));
        maxcnt = 1;
    }
    return 0;
}
/*
3
2 4
CAAB
ADCB
3 6
HFDFFB
AJHGDH
DGAGEH
5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH
*/