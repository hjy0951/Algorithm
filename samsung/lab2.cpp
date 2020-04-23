// 백준 17141 연구소 2
/*
    0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
int map[51][51];
int visit[51][51];
int mintime;
vector<pair<int,int> > v;
vector<int> idx;
queue<pair<int,int> > q;
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};

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
    int temp = 1;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n && ((map[ny][nx] == 0 && visit[ny][nx] == 0) || (map[ny][nx] == 2 && visit[ny][nx] == 0)) ){
                visit[ny][nx] = visit[cy][cx] + 1;
                q.push(make_pair(ny,nx));
                temp = max(temp, visit[ny][nx]);
            }
        }
    }
    int zero = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            // if((map[i][j] == 0 && visit[i][j] == 0) || (map[i][j] == 2 && visit[i][j] == 0)){
            //     zero = 1;
            //     break;
            // }
            if(map[i][j] != 1 && visit[i][j] == 0){
                zero = 1;
                break;
            }
        }
        if(zero == 1) break;
    }
    if(zero == 0) mintime = min(mintime, temp);
}

int main(){
    mintime = 987987987;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) v.push_back(make_pair(i,j));
        }
    }

    for(int i = 0 ; i < m ; i++) idx.push_back(1);
    for(int i = 0 ; i < v.size()-m ; i++) idx.push_back(0);
    sort(idx.begin(), idx.end());

    do{
        for(int i = 0 ; i < idx.size() ; i++){
            if(idx[i] == 1){
                q.push(v[i]);
                visit[v[i].first][v[i].second] = 1;
            }
        }
        bfs();
        memset(visit,0,sizeof(visit));
    }while(next_permutation(idx.begin(), idx.end()));

    if(mintime == 987987987) cout << "-1\n";
    else cout << mintime-1 << "\n";
    return 0;
}
