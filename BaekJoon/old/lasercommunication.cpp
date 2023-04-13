// 백준 6087 레이저 통신
/*
    'C'로 표시되어 있는 두 칸을 레이저로 통신하기 위해서 설치해야 하는 거울 개수의 최솟값을 구하는 프로그램을 작성하시오. 
    레이저로 통신한다는 것은 두 칸을 레이저로 연결할 수 있음을 의미한다.
    레이저는 C에서만 발사할 수 있고, 빈 칸에 거울('/', '\')을 설치해서 방향을 90도 회전시킬 수 있다. 
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
char map[101][101];
int visit[101][101];
vector<pair<int,int> > c;
queue<pair<int,int> > q;
queue<int> mirror;
queue<int> dir;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int minm;

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int inv_dir(int d){
    if(d == 0) return 1;
    else if(d == 1) return 0;
    else if(d == 2) return 3;
    else if(d == 3) return 2;
    else return -1;
}

void bfs(){
    q.push(c[0]);
    mirror.push(1);
    dir.push(-1);
    visit[c[0].first][c[0].second] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int cm = mirror.front();
        mirror.pop();
        int cd = dir.front();
        dir.pop();

        for(int i = 0 ; i < 4 ; i++){
            if(inv_dir(cd) == i) continue;
            
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nm = cm;

            if(cd >= 0 && cd != i) nm++;

            if(map[ny][nx] == '.' && (visit[ny][nx] == 0 || visit[ny][nx] >= nm)){
                if(ny == c[1].first && nx == c[1].second){
                    minm = min(minm, nm);
                }
                else{
                    q.push(make_pair(ny,nx));
                    mirror.push(nm);
                    dir.push(i);
                }
                visit[ny][nx] = nm;
            }
        }
        // print();
    }
}
int main(){
    minm = 987987987;

    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];
            if(str[j] == 'C'){
                c.push_back(make_pair(i,j));
                map[i][j] = '.';
            }
        }
    }

    bfs();
    cout << minm-1 << '\n';
    return 0;
}