// 백준 2589 보물섬
/*
    보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.
    육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다.

    = 재채점 되어 틀린 문제.
      출발 지점을 여러 군데로 잡고, 매번 visit 배열을 초기화하면서 한 육지 내에 가장 먼 거리를 업데이트하여 풀었다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int map[50][50]; // 육지(L) = 1 | 바다(W) = 0
int visit[50][50];
int n,m;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int maxdist;

void print(int arr[][50]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int  x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(visit[ny][nx] == 0 && map[ny][nx] == 1){
                    visit[ny][nx] = visit[cy][cx] + 1;
                    q.push(make_pair(ny,nx));

                    maxdist = max(maxdist, visit[ny][nx]);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < str.size() ; j++){
            if(str[j] == 'L') map[i][j] = 1;
            else map[i][j] = 0;
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visit[i][j] == 0 && map[i][j] == 1){
                bfs(i,j);
                memset(visit,0,sizeof(visit));
            }
        }
    }

    cout << maxdist - 1 << "\n";
    return 0;
}