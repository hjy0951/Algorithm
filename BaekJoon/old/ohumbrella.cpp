// 백준 17244 아맞다우산
/*
    물건들을 최대한 빠르게 챙겨서 외출하는 이동 경로를 알고 싶었다.
    경재 씨는 한 걸음에 상하좌우에 인접한 칸으로만 움직일 수 있다.
    경재 씨를 위해 집을 위에서 바라본 모습과 챙겨야 할 물건들의 위치들을 알고 있을 때, 
    물건을 모두 챙겨서 외출하기까지 최소 몇 걸음이 필요한지 구하는 프로그램을 작성하자.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
char map[51][51];
int visit[51][51][33];
int sy,sx,ey,ex;
int item;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

void print(){
    cout << "map\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(){
    queue<pair<int,int> > q;
    queue<int> iq;
    q.push(make_pair(sy,sx));
    iq.push(0);
    visit[sy][sx][0] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int ci = iq.front();
        iq.pop();

        // cout << "pos : " << cy << " , " << cx << "\titem : " << ci << '\n';

        if(ci == (1<<item)-1 && cy == ey && cx == ex){
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                // 물건을 다 안챙겼는데 출구
                // if(ci < 31 && ny == ey && nx == ex) continue;
                // 일반 길
                if(visit[ny][nx][ci] == 0 && map[ny][nx] == '.'){
                    visit[ny][nx][ci] = visit[cy][cx][ci] + 1;
                    q.push(make_pair(ny,nx));
                    iq.push(ci);
                    
                }
                // 물건 도달
                else if(map[ny][nx] >= '0' && map[ny][nx] <= '5'){
                    int ni = ci | (1 << (map[ny][nx] - '0'));
                    // cout << "ni : " << ni << '\n';
                    if(visit[ny][nx][ni] == 0){
                        visit[ny][nx][ni] = visit[cy][cx][ci] + 1;
                        q.push(make_pair(ny,nx));
                        iq.push(ni);
                    }
                }
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'S'){
                sy = i;
                sx = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'X'){
                map[i][j] = item + '0';
                item++;
            }
            else if(map[i][j] == 'E'){
                ey = i;
                ex = j;
                map[i][j] = '.';
            }
        }
    }

    bfs();
    
    cout << visit[ey][ex][(1<<item)-1]-1 << '\n';
    return 0;
}