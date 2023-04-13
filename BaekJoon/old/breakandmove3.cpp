// 백준 16933 벽 부수고 이동하기 3
/*
    최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다. 
    이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 
    이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.
    낮과 밤이 번갈아가면서 등장한다. 
    가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 
    이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
    만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 
    단, 벽은 낮에만 부술 수 있다.
    맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m,k;
int map[1001][1001];
int visit[1001][1001][11];
int mindist;
int day;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(){
    cout << '\n';
    for(int i = 0 ; i <= k ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int l = 1 ; l <= m ; l++){
                cout << visit[j][l][i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(){
    queue<pair<int,int> > q;
    queue<int> wall;
    queue<int> night;
    q.push(make_pair(1,1));
    wall.push(0);
    night.push(0); // 0 : 낮 | 1 : 밤
    for(int i = 0 ; i <= k ;i++) visit[1][1][i] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int ox = wall.front();
        wall.pop();
        int time = night.front();
        night.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
                if(time == 0){ // 낮 : 벽 부수기 가능
                    if(visit[ny][nx][ox] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][ox] = visit[cy][cx][ox] + 1;

                        if(ny == n && nx == m){
                            mindist = min(mindist, visit[ny][nx][ox]);
                            return;
                        }
                        
                        q.push(make_pair(ny,nx));
                        wall.push(ox);
                        night.push(1);
                    }
                    // 벽 부수기
                    else if(visit[ny][nx][ox+1] <= 0 && map[ny][nx] == 1 && ox < k){
                        if(visit[ny][nx][ox+1] < 0) visit[ny][nx][ox+1] = visit[cy][cx][ox] + 2;
                        else visit[ny][nx][ox+1] = visit[cy][cx][ox] + 1;

                        q.push(make_pair(ny,nx));
                        wall.push(ox+1);
                        night.push(1);
                    }
                }
                else{ // 밤 : 벽 못 부숨
                    if(visit[ny][nx][ox] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][ox] = visit[cy][cx][ox] + 1;

                        if(ny == n && nx == m){
                            mindist = min(mindist, visit[ny][nx][ox]);
                            return;
                        }
                        
                        q.push(make_pair(ny,nx));
                        wall.push(ox);
                        night.push(0);
                    }
                    // 벽을 부술 수 없으므로 1번 대기
                    else if(visit[ny][nx][ox+1] == 0 && map[ny][nx] == 1 && ox < k){
                        visit[ny][nx][ox+1] = -1;

                        q.push(make_pair(cy,cx));
                        wall.push(ox);
                        night.push(0);
                    }
                }
            }
        }
    }
}

int main(){
    mindist = 987987987;

    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < m ; j++){
            map[i][j+1] = str[j] - '0';
        }
    }    

    if(n == 1 && m == 1){
        cout << "0\n";
        return 0;
    }

    bfs();

    // print();

    if(mindist == 987987987) cout << "-1\n";
    else cout << mindist << '\n';

    return 0;
}