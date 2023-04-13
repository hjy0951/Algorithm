// 백준 1012 유기농 배추
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n, m, k;
int map[50][50];
int visit[50][50];
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};

void print_map(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void print_visit(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int x){
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
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = 1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> k; // 가로 | 세로 | 배추 수

        int x, y;
        for(int i = 0 ; i < k ; i++){
            cin >> x >> y;
            map[y][x] = 1; // 배추 위치 표시
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(map[i][j] == 1 && visit[i][j] == 0){
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
        memset(visit,0,sizeof(visit));
        memset(map,0,sizeof(map));
    }
    return 0;
}