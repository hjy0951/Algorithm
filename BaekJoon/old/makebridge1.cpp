// 백준 2146 다리 만들기 1
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int map[101][101];
int visit[101][101];
int island[101][101];
int minbridge;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int cnt;

void print(int arr[][101]){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void make_island(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    island[y][x] = ++cnt;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx>= 0 && nx < n){
                if(map[ny][nx] == 1 && island[ny][nx] == 0){
                    island[ny][nx] = cnt;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

void bfs(int y, int x, int cur){
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

            if(ny >= 0 && ny < n && nx>= 0 && nx < n){
                if(visit[ny][nx] == 0){
                    if(map[ny][nx] == 0){
                        visit[ny][nx] = visit[cy][cx] + 1;
                        q.push(make_pair(ny,nx));
                    }
                    else if(map[ny][nx] == 1 && island[ny][nx] != cur){
                        minbridge = min(minbridge, visit[cy][cx]);
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    minbridge = 987987987;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(island[i][j] == 0 && map[i][j] == 1){
                make_island(i,j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] == 1){
                for(int k = 0 ; k < 4 ; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if(map[ny][nx] == 1) continue;

                    bfs(ny,nx, island[i][j]);
                    memset(visit,0,sizeof(visit));
                }
            }
        }
    }

    cout << minbridge << '\n';
    return 0;
}