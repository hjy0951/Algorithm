// 백준 16236 아기 상어
/*
    N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리
    아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수
    가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동
    아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
    아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
    크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
    
    아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.
        1. 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
        2. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
        3. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
            1) 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
            2) 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
    
    아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹고 그 칸은 빈 칸이 된다.
    아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
        예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.
    아기 상어가 몇 초 동안 물고기를 잡아먹을 수 있는지 구하는 프로그램
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct Shark{
    int y;
    int x;
    int size;
    int cnt;
};

int n;
int map[21][21];
int visit[21][21];
Shark bs;
queue<pair<int,int> > q;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int t;
int fin;

void print(int arr[][21]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\t";
        for(int j = 0 ; j < n ; j++){
            if(i == bs.y && j == bs.x) cout << "7 ";
            else cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n";
}

// bool cmp(pair<int,int> p1, pair<int,int> p2){
//     if(p1.first < p2.first) return p1 < p2;
//     else if(p1.first == p2.first){
//         if(p1.second < p2.second) return p1 < p2;
//         else return p1 > p2;
//     }
//     else return p1 > p2;
// }

void bfs(){
    vector<pair<int,int> > fish;
    int mintime = -1;
    q.push(make_pair(bs.y,bs.x));
    visit[bs.y][bs.x] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n && visit[ny][nx] == 0){
                if(map[ny][nx] == 0 || map[ny][nx] == bs.size){
                    if(mintime > 0 && visit[cy][cx]+1 > mintime) continue;

                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = visit[cy][cx] + 1;
                }
                else if(map[ny][nx] > 0 && map[ny][nx] < bs.size){
                    if(mintime < 0) mintime = visit[cy][cx] + 1;
                    else if(mintime > 0 && visit[cy][cx]+1 > mintime) continue;
                    
                    visit[ny][nx] = visit[cy][cx] + 1;
                    fish.push_back(make_pair(ny,nx));
                }
            }
        }
    }

    if(fish.size() == 0){
        fin = 1;
        return;
    }
    else{
        sort(fish.begin(), fish.end());
        int high = fish[0].first; // 가장 위
        vector<pair<int,int> > tv;

        for(int i = 0 ; i < fish.size() ; i++){
            int ty = fish[i].first;
            int tx = fish[i].second;

            if(ty > high) break;

            tv.push_back(make_pair(tx,ty));
        }
        sort(tv.begin(), tv.end());

        int ty = tv[0].second;
        int tx = tv[0].first;

        t += visit[ty][tx] - 1;
        map[ty][tx] = 0;
        bs.cnt++;
        bs.y = ty;
        bs.x = tx;

        if(bs.cnt == bs.size){
            bs.cnt = 0;
            bs.size++;
        }
    }
    // else{
    //     sort(fish.begin(), fish.end(), cmp);
    //     int ty = fish[0].first;
    //     int tx = fish[0].second;

    //     // cout << "target : " << ty << " , " << tx << "\n";
    //     // print(visit);

    //     t += visit[ty][tx] - 1;
    //     map[ty][tx] = 0;
    //     bs.cnt++;
    //     bs.y = ty;
    //     bs.x = tx;

    //     if(bs.cnt == bs.size){
    //         bs.cnt = 0;
    //         bs.size++;
    //     }
    // }

    memset(visit,0,sizeof(visit));
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];

            if(map[i][j] == 9){
                // 아기상어 초기화
                bs.y = i;
                bs.x = j;
                bs.size = 2;
                bs.cnt = 0;
                map[i][j] = 0;
            }
        }
    }

    while(fin == 0){
        bfs();
        if(fin == 1) break;
    }

    cout << t << "\n";

    return 0;
}
/*
    13:12 ~ 14:18
*/