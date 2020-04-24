// 백준 15683 감시
/*
    CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다.
    사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 없다.
    CCTV가 감시할 수 없는 영역은 사각지대라고 한다.
    CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며, 감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
int map[10][10];
int dmap[10][10];
vector<pair<int,int> > cctv;
int minn;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void watch(int num, int y, int x, int arr[][10]){
    int d = dmap[y][x] - 1;
    int ny = y;
    int nx = x;
    arr[ny][nx] = 1;

    if(num == 1){
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
    }
    else if(num == 2){
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
        d = (d+2) % 4;
        ny = y;
        nx = x;
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
    }
    else if(num == 3){
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
        d = (d+1) % 4;
        ny = y;
        nx = x;
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
    }
    else if(num == 4){
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
        d = (d+1) % 4;
        ny = y;
        nx = x;
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
        d = (d+1) % 4;
        ny = y;
        nx = x;
        while(1){
            ny = ny + dy[d];
            nx = nx + dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

            arr[ny][nx] = 1;
        }
    }
    else if(num == 5){
        for(int i = 0 ; i < 4 ; i++){
            ny = y;
            nx = x;
            while(1){
                ny = ny + dy[i];
                nx = nx + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) break;

                arr[ny][nx] = 1;
            }
        }
    }    
}

void f(int cur){
    if(cur >= cctv.size()){
        int test[10][10] = {0,};
        for(int i = 0 ; i < cctv.size() ; i++){
            int cy = cctv[i].first;
            int cx = cctv[i].second;
            watch(map[cy][cx],cy,cx,test);
        }
        int zero = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(test[i][j] == 0 && map[i][j] == 0) zero++;
            }
        }
        minn = min(minn,zero);
        return;
    }
    else{
        for(int i = 1 ; i <= 4 ; i++){
            int cy = cctv[cur].first;
            int cx = cctv[cur].second;
            dmap[cy][cx] = i;
            f(cur+1);
        }
    }
}

int main(){
    minn = 987987987;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6){
                cctv.push_back(make_pair(i,j));
            }
        }
    }

    f(0);
    cout << minn << "\n";

    return 0;
}
/*
    14:00 ~ 14:28
*/