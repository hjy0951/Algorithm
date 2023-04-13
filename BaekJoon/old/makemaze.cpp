// 백준 2665 미로 만들기
/*
    시작방에서 출발하여 길을 찾아서 끝방으로 가는 것이 목적인데, 
    검은 방 몇 개를 흰 방으로 바꾸어야 하는데 되도록 적은 수의 방의 색을 바꾸고 싶다.

    = visit 배열에 일반적인 bfs와 다르게 현재 위치까지 몇 개의 방을 변경했는지 최소값을 업데이트하며 진행되는 bfs
*/
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int map[50][50];
int visit[50][50]; // 현재 위치까지 몇 개의 방을 변경하였는지.
int n;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0] = 0;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(map[ny][nx] == 1 && visit[ny][nx] > visit[cy][cx]){
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = visit[cy][cx];
                }
                else if(map[ny][nx] == 0 && visit[ny][nx] > visit[cy][cx] + 1){
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = visit[cy][cx] + 1;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < str.size() ; j++){
            map[i][j] = str[j] - '0';
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            visit[i][j] = 3000;
        }
    }

    // cout << "\n";
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    bfs();
    cout << visit[n-1][n-1] << "\n";
    return 0;
}