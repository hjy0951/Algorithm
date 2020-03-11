// 백준 1520 내리막길
/*
    지도는 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
    한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
    항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다
    제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하라
    M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수

    DFS/BFS 문제로 생각했는데 문제를 읽다보니 그렇게 풀면 시간초과가 날 것 같았다.
    다른 방법으로 DP를 생각하였는데 구현이 쉽지 않아 구글링하여 참고하였다. 
    DFS + DP를 통해 푸는 문제.
*/
#include <iostream>
#include <cstring>

using namespace std;

int m,n; // 세로 가로
int map[500][500];
int dp[500][500];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int dfs(int y, int x){
    if(y == m-1 && x == n-1) return 1;

    if(dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;

    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < m && nx >= 0 && nx < n){
            if(map[ny][nx] < map[y][x]){
                dp[y][x] += dfs(ny,nx);
            }
        }
    }
    
    return dp[y][x];
}

int main(){
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0) << "\n";
    return 0;
}
/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

3
*/