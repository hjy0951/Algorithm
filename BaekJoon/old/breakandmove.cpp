// 백준 2206 벽 부수고 이동하기
/*
    맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳
    (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동
    시작하는 칸과 끝나는 칸도 포함
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n,m;
int map[1000][1000];
int visit[1000][1000][2];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int mindist;

void print_arr(int arr[][1000]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(){
    queue<pair<int,int> > q;
    queue<int> wall;

    q.push(make_pair(0,0));
    wall.push(0);

    visit[0][0][0] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        int ox = wall.front();
        wall.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(ox == 0){
                    // 벽을 안뚫고 이동 가능.
                    if(visit[ny][nx][0] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][0] = visit[cy][cx][0] + 1;

                        if(ny == n-1 && nx == m-1){
                            mindist = min(mindist, visit[ny][nx][0]);
                            return;
                        }
                        else{
                            q.push(make_pair(ny,nx));
                            wall.push(0);
                        }
                    }
                    // 벽을 뚫고 이동.
                    else if(visit[ny][nx][1] == 0 && map[ny][nx] == 1){
                        visit[ny][nx][1] = visit[cy][cx][0] + 1;
                        q.push(make_pair(ny,nx));
                        wall.push(1);
                    }
                }
                else{
                    if(visit[ny][nx][1] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][1] = visit[cy][cx][1] + 1;

                        if(ny == n-1 && nx == m-1){
                            mindist = min(mindist, visit[ny][nx][1]);
                            return;
                        }
                        else{
                            q.push(make_pair(ny,nx));
                            wall.push(1);
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
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j] - '0';
        }
    }

    if(n == 1 && m == 1){
        cout << "1\n";
        return 0;
    }

    bfs();

    if(mindist == 987987987) cout << "-1\n"; // 벽을 뚫더라도 도착점에 도달할 수 없음
    else cout << mindist << "\n";

    return 0;
}