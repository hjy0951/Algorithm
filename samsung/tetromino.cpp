// 백준 14500 테트로미노
/*
    각 테트로미노는 ㅗ 모양을 제외하고 현재위치부터 4칸 안에 도달할 수 있는 경로의 합을 구해주면 된다.
*/
#include <iostream>

using namespace std;

int n,m;
int map[501][501];
int maxn;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int visit[501][501];

void tetro1(int cnt, int y, int x, int sum){ // ㅗ 모양 제외
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                if(cnt < 3) tetro1(cnt+1, ny, nx, sum + map[ny][nx]);
                else if(cnt == 3) maxn = max(maxn, sum +map[ny][nx]);
                visit[ny][nx] = 0;
            }
        }
    }
}

void tetro2(int cnt, int y, int x){ // ㅗ 모양
    if(y == 0 && x == 0) return;
    else if(y == 0 && x == m-1) return;
    else if(y == n-1 && x == 0) return;
    else if(y == n-1 && x == m-1) return;

    if(y == 0) maxn = max(maxn, map[y][x-1] + map[y][x] + map[y][x+1] + map[y+1][x]);
    else if(y == n-1) maxn = max(maxn, map[y][x-1] + map[y][x] + map[y][x+1] + map[y-1][x]);
    else if(x == 0) maxn = max(maxn, map[y-1][x] + map[y][x] + map[y+1][x] + map[y][x+1]);
    else if(x == m-1) maxn = max(maxn, map[y-1][x] + map[y][x] + map[y+1][x] + map[y][x-1]);
    else{
        maxn = max(maxn, map[y][x-1] + map[y][x] + map[y][x+1] + map[y+1][x]);
        maxn = max(maxn, map[y][x-1] + map[y][x] + map[y][x+1] + map[y-1][x]);
        maxn = max(maxn, map[y-1][x] + map[y][x] + map[y+1][x] + map[y][x+1]);
        maxn = max(maxn, map[y-1][x] + map[y][x] + map[y+1][x] + map[y][x-1]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visit[i][j] = 1;
            tetro1(1,i,j,map[i][j]);
            visit[i][j] = 0;
            tetro2(0,i,j);
        }
    }
    cout << maxn << "\n";
    return 0;
}
/*
    14:40 ~ 15:17
*/