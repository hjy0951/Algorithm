// 백준 14502 연구소
/*
    바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
    연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
    일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
    새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
    벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.
    연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int wall;
int map[10][10];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
queue<pair<int,int> > q;
int maxn;

void printmap(int arr[][10]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(int y, int x, int cnt){
    if(cnt == 2){
        int visit[10][10] = {0,};
        int num = 0;

        queue<pair<int,int> > test;
        for(int i = 0 ; i < q.size() ; i++){
            pair<int,int> temp = q.front();
            visit[temp.first][temp.second] = 1;
            q.pop();
            test.push(temp);
            q.push(temp);
        }

        while(!test.empty()){
            int cy = test.front().first;
            int cx = test.front().second;
            test.pop();

            for(int i = 0 ; i < 4 ; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                    if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                        visit[ny][nx] = 1;
                        num++;
                        test.push(make_pair(ny,nx));
                    }
                }
            }
        }
        int res = n*m - q.size() - num - wall - 3;
        if(maxn < res) maxn = res;

        return;
    }
    else{
        for(int i = y ; i < n ; i++){
            if(i == y){
                for(int j = x+1 ; j < m ; j++){
                    if(map[i][j] == 0){
                        map[i][j] = 1;
                        dfs(i,j,cnt+1);
                        map[i][j] = 0;
                    }
                }
            }
            else{
                for(int j = 0 ; j < m ; j++){
                    if(map[i][j] == 0){
                        map[i][j] = 1;
                        dfs(i,j,cnt+1);
                        map[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) q.push(make_pair(i,j));
            else if(map[i][j] == 1) wall++;
        }
    }    

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                dfs(i,j,0);
                map[i][j] = 0;
            }
        }
    }

    cout << maxn << "\n";
    return 0;
}
/*
    15:20 ~ 15:53
*/