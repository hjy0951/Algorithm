// 백준 2234 성곽
/*
    이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.
        1. 이 성에 있는 방의 개수
        2. 가장 넓은 방의 넓이
        3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.

    성은 m×n(1 ≤ m, n ≤ 50)개의 정사각형 칸으로 이루어진다. 
    성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.
*/
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n,m;
string map[51][51];
int visit[51][51];
bool check[51][51];
int bin[] = {8,4,2,1};
int num;
int area[3000];
// 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0}; // 서북동남
vector<int> g[3000];

void printmap(){
    cout << '\n';
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print(){
    cout << '\n';
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i = 1 ; i <= num ; i++){
        cout << area[i] << ' ';
    }
    cout << '\n';
}

string binary(int x){
    string str;
    for(int i = 0 ; i < 4 ; i++){
        if(x < bin[i]) str.push_back('0');
        else{
            x -= bin[i];
            str.push_back('1');
        }
    }
    return str;
}

void bfs(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = num;
    area[num]++;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < m && nx >= 0 && nx < n){
                // 서 북 동 남
                if(i == 0 && map[cy][cx][3] == '0' && visit[ny][nx] == 0){
                    visit[ny][nx] = num;
                    area[num]++;
                    q.push(make_pair(ny,nx));
                }
                else if(i == 1 && map[cy][cx][2] == '0' && visit[ny][nx] == 0){
                    visit[ny][nx] = num;
                    area[num]++;
                    q.push(make_pair(ny,nx));
                }
                else if(i == 2 && map[cy][cx][1] == '0' && visit[ny][nx] == 0){
                    visit[ny][nx] = num;
                    area[num]++;
                    q.push(make_pair(ny,nx));
                }
                else if(i == 3 && map[cy][cx][0] == '0' && visit[ny][nx] == 0){
                    visit[ny][nx] = num;
                    area[num]++;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

void make_graph(int y, int x){
    set<int> s;
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    check[y][x] = true;
    int cur = visit[y][x];

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < m && nx >= 0&& nx < n){
                if(check[ny][nx] == false && visit[ny][nx] == cur){
                    q.push(make_pair(ny,nx));
                    check[ny][nx] = true;
                }
                else if(visit[ny][nx] != cur){
                    if(s.insert(visit[ny][nx]).second == true){
                        g[cur].push_back(visit[ny][nx]);
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            int x;
            cin >> x;
            map[i][j] = binary(x);
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == 0){
                ++num;
                bfs(i,j);
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(check[i][j] == false){
                make_graph(i,j);
            }
        }
    }

    int maxarea = 0;
    for(int i = 1 ; i <= num ; i++){
        for(int j = 0 ; j < g[i].size() ; j++){
            int cur = g[i][j];
            if(i == cur) continue;

            maxarea = max(maxarea, area[i] + area[cur]);
        }
    }

    vector<int> temp;
    for(int i = 1 ; i <= num ; i++){
        temp.push_back(area[i]);
    }
    sort(temp.begin(), temp.end());

    cout << num << '\n';
    cout << temp[temp.size()-1] << '\n';
    cout << maxarea << '\n';
    return 0;
}