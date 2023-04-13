// 백준 14442 벽 부숙고 이동하기 2
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n,m,k;
int map[1001][1001];
int visit[1001][1001][11];
int mindist;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(){
    cout << '\n';
    for(int i = 0 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int l = 0 ; l < m ; l++){
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
    q.push(make_pair(0,0));
    wall.push(0);
    for(int i = 0 ; i <= k ; i++) visit[0][0][i] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        int ck = wall.front();
        wall.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(visit[ny][nx][ck] == 0 && map[ny][nx] == 0){
                    visit[ny][nx][ck] = visit[cy][cx][ck] + 1;

                    if(ny == n-1 && nx == m-1){
                        mindist = min(mindist, visit[ny][nx][ck]);
                        return;
                    }
                    else{
                        q.push(make_pair(ny,nx));
                        wall.push(ck);
                    }
                }
                else if(visit[ny][nx][ck+1] == 0 && map[ny][nx] == 1 && ck < k){
                    visit[ny][nx][ck+1] = visit[cy][cx][ck] + 1;
                    q.push(make_pair(ny,nx));
                    wall.push(ck+1);
                }
            }
        }
    }
}

int main(){
    mindist = 987987987;

    cin >> n >> m >> k;
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

    if(mindist == 987987987) cout << "-1\n";
    else cout << mindist << '\n';
    return 0;
}