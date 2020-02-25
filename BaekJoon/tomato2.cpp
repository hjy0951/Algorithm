// 백준 7569 토마토2
/*
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다
창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수
*/
#include <iostream>
#include <queue>

using namespace std;

int dz[] = {1,-1,0,0,0,0}; // 위 아래
int dy[] = {0,0,1,-1,0,0}; // 좌 우
int dx[] = {0,0,0,0,1,-1}; // 앞 뒤

queue<int> zq;
queue<int> yq;
queue<int> xq;

int m,n,h;
int day;
int visit[110][110][110];
int map[110][110][110];
// 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

void print(){
    cout << "\n";
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                cout << visit[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(){  // bfs를 돌면서 토마토를 퍼뜨림
    while(!zq.empty()){
        int cz = zq.front();
        int cy = yq.front();
        int cx = xq.front();
        zq.pop();
        yq.pop();
        xq.pop();

        for(int i = 0 ; i < 6 ; i++){
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nz >= 1 && nz <= h && ny >= 1 && ny <= n && nx >= 1 && nx <= m && map[nz][ny][nx] == 0){
                if(visit[nz][ny][nx] == 0){
                    visit[nz][ny][nx] = visit[cz][cy][cx] + 1;
                    zq.push(nz);
                    yq.push(ny);
                    xq.push(nx);
                }
            }
        }
    }
}

int check(){ // 익지않은 토마토가 있는지 확인
    int ox = 1;
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                if(day < visit[i][j][k]) day = visit[i][j][k];
                if(visit[i][j][k] == 0 && map[i][j][k] == 0 && ox == 1) ox = 0;
            }
        }
    }
    if(ox == 1) return 1;
    else return 0;
}

int main(){
    cin >> m >> n >> h;

    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    zq.push(i);
                    yq.push(j);
                    xq.push(k);

                    visit[i][j][k] = 1;
                }
            }
        }
    }

    bfs();
    int ox = check();
    // print();

    if(ox == 1) cout << day-1 << "\n";
    else cout  << "-1\n";

    return 0;
}