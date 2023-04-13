// 백준 2573 빙산
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n,m;
int map[300][300];
int visit[300][300];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int tic; // 시간
queue<pair<int,int> > iq; // 빙산을 넣어둘 큐

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print2(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int x){ // 빙산의 개수를 확인하기 위함
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
                if(visit[ny][nx] == 0 && map[ny][nx] != 0){
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = 1;
                }
            }
        }
    }
}

void melt(){ // 큐에 넣어둔 빙산을 하나하나 확인하면서 바다와 맞닿은 부분의 수만큼 녹임
    int sub[300][300] = {0,};
    int l = iq.size();
    for(int i = 0 ; i < l ; i++){
        int cy = iq.front().first;
        int cx = iq.front().second;
        iq.pop();

        if(map[cy][cx] == 0) continue;

        for(int j = 0 ; j < 4 ; j++){
            int ny = cy + dy[j];
            int nx = cx + dx[j];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(map[ny][nx] == 0) sub[cy][cx] +=1;
            }
        }
        iq.push(make_pair(cy,cx));
    }

    for(int i = 1 ; i < n-1 ; i++){
        for(int j = 1 ; j < m-1 ; j++){
            map[i][j] = map[i][j] - sub[i][j];
            if(map[i][j] < 0) map[i][j] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) iq.push(make_pair(i,j));
        }
    }

    int cnt = 0;
    while(1){
        cnt = 0;
        int l = iq.size();
        for(int i = 0 ; i < l ; i++){
            int y = iq.front().first;
            int x = iq.front().second;
            iq.pop();

            if(map[y][x] == 0){
                // iq.push(make_pair(ny,nx));
                continue;
            }
            else if(visit[y][x] == 0 && map[y][x] != 0){
                bfs(y,x);
                cnt++;
            }

            iq.push(make_pair(y,x));
        }
        
        if(cnt >= 2) break; // 두 부분으로 나뉘어지는 경우
        if(cnt == 0){ // 빙산이 두 부분으로 나뉘지 않고 한번에 다 녹을 경우 0을 출력
            cout << "0\n";
            return 0;
        }

        melt();
        
        tic++;
        memset(visit,0,sizeof(visit));
    }

    cout << tic << "\n";

    return 0;
}
