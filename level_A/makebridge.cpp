// 백준 17472 다리 만들기 2
/*
    다리는 바다에만 건설할 수 있고, 다리의 길이는 다리가 격자에서 차지하는 칸의 수
    다리를 연결해서 모든 섬을 연결하려고 한다
    다리의 양 끝은 섬과 인접한 바다 위에 있어야 하고, 한 다리의 방향이 중간에 바뀌면 안됨
    또, 다리의 길이는 2 이상
    모든 섬을 연결하는 다리 길이의 최솟값

    조건
        1. 1 ≤ N, M ≤ 10
        2. 3 ≤ N×M ≤ 100
        3. 2 ≤ 섬의 개수 ≤ 6

    내가 생각한 방법
        1. 섬의 땅에 섬의 번호를 매김 (BFS) (시간 복잡도 : N*M)
        2. 각 섬에서 다른 섬으로 가로 혹은 세로로 갈 수 있는 거리를 구함 (시간 복잡도 : N * M * 섬의 개수)
        3. kruskal algorithm으로 MST를 만듦 (union-find 필요 = cycle check | 시간은 find 시간이 대부분일듯)
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int map[100][100];
int land[100][100]; // 섬의 땅에 번호를 매긴 배열
int cnt; // 섬의 개수
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
vector<pair<int, pair<int,int> > > v;
// < 섬 간 거리, <섬 a, 섬 b> > => sort 시 거리 기준으로 정렬 가능
int dist[7][7]; // 섬 간 거리 기록 2차원 배열
int ds[10]; // disjoint set
int mindist;

// 배열 확인용
void print_arr(int arr[][100]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void print_dist(){
    for(int i = 1 ; i < 7 ; i++){
        for(int j = 1 ; j < 7 ; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void find_land(int y, int x){ // 섬에 번호 매기기 = BFS
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    land[y][x] = cnt;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m && land[ny][nx] == 0 && map[ny][nx] == 1){
                q.push(make_pair(ny,nx));
                land[ny][nx] = cnt;
            }
        }
    }
}

void find_dist(int y, int x){ // kruskal을 이용하여 MST 만들기 전, 섬 간의 거리 cost를 구함
    int cur_island = land[y][x]; // 현재 섬

    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(land[ny][nx] == 0){ // 육지와 바다가 접해 있는 방향
                int ty = ny;
                int tx = nx;

                int temp_dist = 1;
                while(ty >=0 && ty < n && tx >= 0 && tx < m){
                    if(land[ty][tx] == cur_island) break; // 현재 섬의 육지에 도달하면 break;
                    if(land[ty][tx] != 0 && land[ty][tx] != cur_island){ // 다른 섬을 만날 경우
                        int island = land[ty][tx];
                        temp_dist--;
                        if(temp_dist >= 2){ // 다리 길이가 2 이상이여야 하므로
                            if(dist[cur_island][island] == 0){ // 처음 발견한 경우
                                dist[cur_island][island] = temp_dist;
                                dist[island][cur_island] = temp_dist;
                            }
                            else{
                                if(dist[cur_island][island] > temp_dist){ // 이미 발견되어 기록된 값보다 작을 때 update
                                    dist[cur_island][island] = temp_dist;
                                    dist[island][cur_island] = temp_dist;
                                }
                            }
                        }
                        break;
                    }
                    ty += dy[i];
                    tx += dx[i];
                    temp_dist++;
                }
            }
        }
    }
}

// union-find
int f(int x){ // find만 필요 - MST cycle 체크
    if(x == ds[x]) return x;
    else return f(ds[x]);
}
void u(int x, int y){
    x = f(x);
    y = f(y);

    if(x != y){
        if(x < y) ds[y] = x;
        else ds[x] = y;
    }
}/////////////////////////////

int main(){
    // union-find 초기화
    for(int i = 1 ; i < 10 ; i++){
        ds[i] = i;
    }

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 1 && land[i][j] == 0){
                cnt++;
                find_land(i,j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(land[i][j] != 0){
                find_dist(i,j);
            }
        }
    }

    for(int i = 1 ; i <= cnt ; i++){
        for(int j = i+1 ; j <= cnt ; j++){
            if(dist[i][j] != 0) v.push_back( make_pair( dist[i][j], make_pair(i,j) ) );
        }
    }

    sort(v.begin(),v.end()); // 거리 기준 오름차순 정렬

    for(int i = 0 ; i < v.size() ; i++){ // kruskal
        // cost가 작은 다리부터 확인
        int cd = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        int pa = f(a);
        int pb = f(b);

        if(pa == pb) continue; // 이미 같은 set = cycle이므로 continue;
        else{ // 그렇지 않을 경우, 다리 길이를 더하고 mst에 추가
            mindist += cd;
            ds[pb] = pa;
        }
    }

    int rep = f(1);
    int ox = 0;
    for(int i = 2 ; i <= cnt ; i++){
        int candi = f(i);

        // 모든 대표 노드가 하나로 같아야 함
        if(candi != rep){ // 모든 섬에 갈 수 없는 경우
           ox = 1;
           break; 
        }
    }
    if(ox == 0) cout << mindist << "\n";
    else cout << "-1\n"; 

    return 0;
}