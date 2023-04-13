// 백준 2636 치즈
// 기존의 BFS 문제들과는 반대로 빈칸들을 탐색하여 치즈와 맞닿는 부분이 있으면 녹이는 방식으로 문제를 풀어야 했다. 
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n,m;
int map[100][100];
int visit[100][100];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};
int total;
int rm;
int tic;
int prevc;
queue<pair<int,int> > rmq;

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(){
    // 치즈 바깥쪽 빈칸을 bfs로 탐색
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(visit[ny][nx] == 0){
                    if(map[ny][nx] == 0){
                        q.push(make_pair(ny,nx));
                    }
                    else if(map[ny][nx] == 1){
                        rmq.push(make_pair(ny,nx));
                    }
                    visit[ny][nx] = 1;
                }
            }
        }
    }

    // 빈칸과 맞닿은 치즈들을 녹임
    while(!rmq.empty()){
        int ry = rmq.front().first;
        int rx = rmq.front().second;
        rmq.pop();

        map[ry][rx] = 0;
        rm++; // 녹인 치즈 개수
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) total++;
        }
    }
    
    while(rm != total){ // 치즈를 모두 녹이면 종료
        prevc = total - rm; // 전체 치즈 개수 - 녹인 치즈 수
        solve();
        // print();
        memset(visit,0,sizeof(visit));
        tic++;
    }
    
    cout << tic << "\n"; // 모든 치즈를 녹이는데 걸린 시간
    cout << prevc << "\n"; // 모든 치즈가 녹기 한 시간 전 남아있던 치즈
    
    return 0;
}

/*
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
*/