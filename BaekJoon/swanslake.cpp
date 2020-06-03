// 백준 3197 백조의 호수
/*
    두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.
    호수는 가로로 R, 세로로 C만큼의 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.
    호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 
    두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.
    백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.
    며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성한다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n,m;
char map[1501][1501];
bool visit[1501][1501];
vector<pair<int,int> > swan;
bool flag;
queue<pair<int,int> > q;
queue<pair<int,int> > ice;
queue<pair<int,int> > water;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

void bfs(){
    if(!ice.empty()){
        q = ice;
        while(!ice.empty()) ice.pop();
    }

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if(cy == swan[1].first && cx == swan[1].second){
            flag = true;
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(!visit[ny][nx]){
                    if(map[ny][nx] == '.'){
                        q.push(make_pair(ny,nx));
                        visit[ny][nx] = true;
                    }
                    else if(map[ny][nx] == 'X'){
                        ice.push(make_pair(ny,nx));
                        visit[ny][nx] = true;
                    }
                }
            }
        }
    }
}

void melting(){
    int len = water.size();

    for(int i = 0 ; i < len ; i++){
        int cy = water.front().first;
        int cx = water.front().second;
        water.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(map[ny][nx] == 'X'){
                    water.push(make_pair(ny,nx));
                    map[ny][nx] = '.';
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'L'){
                map[i][j] = '.';
                swan.push_back(make_pair(i,j));
                water.push(make_pair(i,j));
            }
            else if(map[i][j] == '.') water.push(make_pair(i,j));
        }
    }

    q.push(swan[0]);
    visit[swan[0].first][swan[0].second] = true;

    int day = 0;
    while(1){
        bfs();
        if(flag) break;
        melting();
        day++;
    }

    cout << day << '\n';
    return 0;
}