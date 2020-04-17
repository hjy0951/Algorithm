// 백준 14503 로봇 청소기
/*
    로봇 청소기가 청소하는 영역의 개수를 구하는 프로그램

    로봇 청소기는 다음과 같이 작동한다.
        1. 현재 위치를 청소한다.
        2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
            a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
            b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
            c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
    로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
*/
#include <iostream>

using namespace std;

int n,m;
int r,c,d;
int map[51][51];
int visit[51][51];
int dy[] = {-1,0,1,0}; // 북 서 남 동
int dx[] = {0,-1,0,1};
int cnt;


void print(int y, int x){
    cout << "\n";
    cout << "dir : " << d << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == y && j == x) cout << "4 ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin >> n >> m;
    cin >> r >> c >> d; // d = 0 : 북쪽 | 1 : 동쪽 | 2 : 남쪽 | 3 : 서쪽
    if(d == 1) d = 3;
    else if(d == 3) d = 1;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    int cy = r;
    int cx = c;
    int bk = 0;
    while(1){
        // 1. 현재 위치를 청소
        if(visit[cy][cx] == 0){
            visit[cy][cx] = 1;
            cnt++;
        }

        int blk = 0;
        // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색
        for(int i = 1 ; i <= 4 ; i++){
            int nd = (d + i)%4;
            // int nd = (d+1)%4;
            int ny = cy + dy[nd];
            int nx = cx + dx[nd];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m){ // 범위 밖
                blk++;
                continue;
            }

            // a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
            if(map[ny][nx] == 0 && visit[ny][nx] == 0){ 
                cy = ny;
                cx = nx;
                d = nd;
                break;
            }
            // b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
            else if(map[ny][nx] == 1 || visit[ny][nx] != 0){
                blk++;
                continue;
            }
        }

        // 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        if(blk == 4){
            int ny = cy - dy[d];
            int nx = cx - dx[d];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
            // d. 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
            if(map[ny][nx] == 1) break;
            // c. 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            else{
                cy = ny;
                cx = nx;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
/*
    16:07 ~ 16:16
    16:26 ~ 17:00
*/
