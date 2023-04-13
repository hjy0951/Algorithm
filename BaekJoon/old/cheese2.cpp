// 백준 2638 치즈
/*
    치즈에서 각 치즈 격자(작 은 정사각형 모양)의 4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다. 
    입력으로 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 구하는 프로그램
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int map[101][101];
bool out[101][101];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
queue<pair<int,int> > cheese;

// 치즈 바깥 부분 체크 : n^2
void outer(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    out[0][0] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(map[ny][nx] == 0 && out[ny][nx] == false){
                    out[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

// 치즈 녹이기
void melt(){
    int len = cheese.size();
    queue<pair<int,int> > mq;

    for(int i = 0 ; i < len ; i++){
        int cy = cheese.front().first;
        int cx = cheese.front().second;
        cheese.pop();

        int cnt = 0;
        for(int j = 0 ; j < 4 ; j++){
            int ny = cy + dy[j];
            int nx = cx + dx[j];

            if(map[ny][nx] == 0 && out[ny][nx] == true) cnt++;
        }
        // 외부와 2변 이상 접하는 경우
        if(cnt >= 2) mq.push(make_pair(cy,cx));
        else cheese.push(make_pair(cy,cx));
    }

    while(!mq.empty()){
        int cy = mq.front().first;
        int cx = mq.front().second;
        mq.pop();

        map[cy][cx] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) cheese.push(make_pair(i,j));
        }
    }

    int t = 0;
    while(cheese.size() > 0){
        t++;
        outer();
        melt();
        memset(out,0,sizeof(out));
    }
    cout << t << '\n';
    return 0;
}