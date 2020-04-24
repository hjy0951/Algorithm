// 백준 17142 연구소 3
/*
    바이러스는 활성 상태와 비활성 상태가 있다
    가장 처음에 모든 바이러스는 비활성 상태이고, 활성 상태인 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제
    연구소의 바이러스 M개를 활성 상태로 변경하려고 한다
    활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다
    연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
int mintime;
int wall,vn;
int map[51][51];
int test[51][51];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
vector<int> idx;
vector<pair<int,int> > virus;
queue<pair<int,int> > q;

void print(int arr[][51]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(){
    int maxn = 0;
    int fin = 0;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(test[ny][nx] == 0 && map[ny][nx] == 0){ // 일반적인 확산
                    q.push(make_pair(ny,nx));
                    test[ny][nx] = test[cy][cx] + 1;
                    maxn = max(maxn, test[ny][nx]);
                    vn++;
                }
                else if(test[ny][nx] == 0 && map[ny][nx] == 2){ // 비활성 바이러스를 만났을 때
                    q.push(make_pair(ny,nx));
                    test[ny][nx] = test[cy][cx] + 1;
                    maxn = max(maxn, test[ny][nx]);                    
                }
            }

            if(wall + vn == n*n) {
                fin = 1;
                break;
            }
        }
        if(fin == 1) break;
    }
    
    int zero = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(test[i][j] == 0 && map[i][j] == 0){
                zero = 1;
                break;
            }
        }
        if(zero == 1) break;
    }

    if(zero == 0) mintime = min(mintime, maxn);

    memset(test,0,sizeof(test));
}

int main(){
    mintime = 987987987;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back(make_pair(i,j));
            else if(map[i][j] == 1) wall++;
        }
    }

    if(wall + virus.size() == n*n){
        cout << "0\n";
        return 0;
    }

    for(int i = 0 ; i < m ; i++) idx.push_back(1);
    for(int i = 0 ; i < virus.size() - m ; i++) idx.push_back(0);
    sort(idx.begin(), idx.end());

    do{
        for(int i = 0 ; i < idx.size() ; i++){
            if(idx[i] == 1){
                q.push(virus[i]);
                test[virus[i].first][virus[i].second] = 1;
            }
        }
        vn = virus.size();
        bfs();
        while(!q.empty()) q.pop();       
    }while(next_permutation(idx.begin(), idx.end()));

    if(mintime != 987987987) cout << mintime-1 << "\n";
    else cout << "-1\n";

    return 0;
}
/*
    14:35 ~ 15:05
*/