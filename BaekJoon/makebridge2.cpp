// 백준 17472 다리만들기 2
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int map[11][11];
int island[11][11];
int inum;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int dist[11][11];
vector<pair<int,pair<int,int> > > edge;
bool used[7];
int rel[10];

void print(int arr[][11]){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printarr(){
    cout << "rel\n";
    for(int i = 1  ; i <= inum ; i++) cout << rel[i] << ' ';
    cout << '\n';
}


void make_island(int y, int x, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    island[y][x] = c;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(map[ny][nx] == 1 && island[ny][nx] == 0){
                island[ny][nx] = c;
                q.push(make_pair(ny,nx));
            }
        }
    }
}

void find_dist(int cur, int dir, int y, int x){
    int ny = y;
    int nx = x;
    int len = 0;
    while(1){
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
        if(island[ny][nx] == cur) break;
        if(island[ny][nx] != 0 && island[ny][nx] != cur){
            if(len < 2) break;

            int next = island[ny][nx];
            if(dist[cur][next] == 0) dist[cur][next] = len;
            else dist[cur][next] = min(dist[cur][next], len);

            break;
        }
        
        len++;
        ny += dy[dir];
        nx += dx[dir];
    }
}

int f(int x){
    if(rel[x] == x) return x;
    else return f(rel[x]);
}

void u(int y, int x){
    y = f(y);
    x = f(x);

    if(y != x){
        if(y < x) rel[x] = y;
        else rel[y] = x;
    }
}

bool check(){
    int prev;
    for(int i = 1 ; i <= inum ; i++){
        if(i == 1) prev = f(i);
        else{
            if( prev != f(i) ) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 1 && island[i][j] == 0){
                make_island(i,j,++inum);
            }
        }
    }

    for(int i = 1 ; i <= inum ; i++) rel[i] = i;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(island[i][j] != 0){
                int cur = island[i][j];
                for(int k = 0 ; k < 4 ; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                        if(island[ny][nx] == 0){
                            find_dist(cur,k,ny,nx);
                        }
                    }
                }
            }
        }
    }

    for(int i = 1 ; i <= inum ; i++){
        for(int j = i+1 ; j <= inum ; j++){
            if(dist[i][j] == 0) continue;
            // cout << i << " --> " << j << " = " << dist[i][j] << '\n';
            edge.push_back( make_pair( dist[i][j], make_pair(i,j) ) );
        }
    }

    int bridge = 0;
    sort(edge.begin(), edge.end());

    for(int i = 0 ; i < edge.size() ; i++){
        int tdist = edge[i].first;
        int tc = edge[i].second.first;
        int tn = edge[i].second.second;

        if( f(tc) != f(tn) ){
            u(tc,tn);
            bridge += tdist;
        }
    }

    bool fin = check();

    if(fin) cout << bridge << '\n';
    else cout << "-1\n";
    return 0;
}