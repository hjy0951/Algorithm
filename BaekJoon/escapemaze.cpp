// 백준 14923 미로 탈출
/*
    홍익이는 사악한 마법사의 꾐에 속아 N x M 미로 (Hx, Hy) 위치에 떨어졌다.
    다행히도 홍익이는 마법사가 만든 미로의 탈출 위치(Ex, Ey)를 알고 있다.
    하지만 미로에는 곳곳에 마법사가 설치한 벽이 있어 홍익이가 탈출하기 어렵게 하고 있다.
    홍익이는 마법사의 연구실에서 훔친 지팡이가 있어, 벽을 길로 만들 수 있다.
    그렇지만, 안타깝게도 마법의 지팡이는 단 한 번만 사용할 수 있다.
    이때, 홍익이를 도와 미로에서 탈출할 수 있는지 알아보고, 할 수 있다면 가장 빠른 경로의 거리 D는 얼마인지 알아보자.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
int map[1001][1001];
int visit[1001][1001][2];
int sy,sx;
int ey,ex;
int mindist;
int fin;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(){
    cout << '\n';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << visit[i][j][0] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << visit[i][j][1] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(){
    queue<pair<int,int> > q;
    queue<int> ox;
    q.push(make_pair(sy,sx));
    ox.push(0);
    visit[sy][sx][0] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int wall = ox.front();
        ox.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
                if(wall == 0){
                    if(visit[ny][nx][0] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][0] = visit[cy][cx][0] + 1;

                        if(ny == ey && nx == ex){
                            mindist = min(mindist, visit[ny][nx][0]);
                            fin = 1;
                            return;
                        }
                        else{
                            q.push(make_pair(ny,nx));
                            ox.push(0);
                        }
                    }
                    else if(visit[ny][nx][1] == 0 && map[ny][nx] == 1){
                        visit[ny][nx][1] = visit[cy][cx][0] + 1;
                        q.push(make_pair(ny,nx));
                        ox.push(1);
                    }
                }
                else if(wall == 1){
                    if(visit[ny][nx][1] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][1] = visit[cy][cx][1] + 1;
                        
                        if(ny == ey && nx == ex){
                            mindist = min(mindist, visit[ny][nx][1]);
                            fin = 1;
                        }
                        else{
                            q.push(make_pair(ny,nx));
                            ox.push(1);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    mindist = 987987987;

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> map[i][j];
        }
    }

    bfs();

    if(fin == 0) cout << "-1\n";
    else cout << mindist-1 << '\n';
    return 0;
}