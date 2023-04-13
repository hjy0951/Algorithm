// 백준 2468 안전영역
/*
    많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사
    일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n;
int map[100][100];
int visit[100][100];
int maxcnt;
int cnt;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << visit[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int x, int h){
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

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(visit[ny][nx] == 0 && map[ny][nx] > h){
                    visit[ny][nx] = 1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

int main(){
    int maxh = 0;
    maxcnt = 1;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(maxh < map[i][j]) maxh = map[i][j];
        }
    }

    for(int i = 1 ; i <= maxh ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                if(visit[j][k] == 0 && map[j][k] > i){
                    bfs(j, k, i);
                    cnt++;
                }
            }
        }
        // cout << "h : " << i << "\n";
        // print();
        // cout << "cnt : " << cnt << "\n";
        memset(visit,0,sizeof(visit));
        if(maxcnt < cnt) maxcnt = cnt;
        cnt = 0;
    }
    
    cout << maxcnt << "\n";
    
    return 0;
}