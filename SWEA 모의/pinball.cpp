#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

// struct Ball{
//     int x;
//     int y;
//     int dir;
//     int point;
// };
struct Hole{
    int x1;
    int y1;

    int x2;
    int y2;
};

int N;
Hole h[11]; // 웜홀 정보
// Ball ball;
int maxpoint; // 최대 점수 기록
int sy,sx;
int dy[] = {-1,0,0,1}; // 상우좌하
int dx[] = {0,1,-1,0};
queue<pair<int,int> > q; // 공의 시작 위치들을 담을 큐
int map[110][110]; // 6~10 : 웜홀 | -1 : 블랙홀
//핀볼은 블록이나 웜홀 또는 블랙홀을 만나지 않는 한 현재 방향을 유지하면서 계속 직진
//블록의 수평면이나 수직면을 만날 경우 방향을 바꿔 반대 방향으로 돌아오고, 경사면을 만날 경우에는 직각으로 진행 방향이 꺾이게 된다.
//핀볼은 벽을 만날 경우에도 반대 방향
//웜홀에 빠지면 동일한 숫자를 가진 다른 반대편 웜홀로 빠져 나오게 되며 진행방향은 그대로 유지
//핀볼이 출발 위치로 돌아오거나 블랙홀 만나면 종료
//웜홀을 통과하는 것은 점수에 포함되지 않는다
//점수는 벽이나 블록에 부딪힌 횟수가 된다

// 1 : 좌하 수직 2시방향 대각 | 2 : 좌상 수직 5시 대각 | 3 : 상우 수직 8시 대각 | 4 : 우하 수직 11시 대각 | 5 : 상하좌우 수직 |

int crash(int block, int dir){
    int ndir = dir;
    switch(block){ // 상우좌하
        case 1: //
            if(ndir == 0) ndir = 3;
            else if(ndir == 1) ndir = 2;
            else if(ndir == 2) ndir = 0;
            else if(ndir == 3) ndir = 1;
            break;

        case 2: // 
            if(ndir == 0) ndir = 1;
            else if(ndir == 1) ndir = 2;
            else if(ndir == 2) ndir = 3;
            else if(ndir == 3) ndir = 0;
            break;

        case 3: //
            if(ndir == 0) ndir = 2;
            else if(ndir == 1) ndir = 3;
            else if(ndir == 2) ndir = 1;
            else if(ndir == 3) ndir = 0;
            break;

        case 4: //
            if(ndir == 0) ndir = 3;
            else if(ndir == 1) ndir = 0;
            else if(ndir == 2) ndir = 1;
            else if(ndir == 3) ndir = 2;
            break;

        case 5:
            if(ndir == 0) ndir = 3;
            else if(ndir == 3) ndir = 0;
            else if(ndir == 1) ndir = 2;
            else if(ndir == 2) ndir = 1;
            break;
        
    }
    return ndir;
}

void start_game(int y, int x, int dir){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    int ndir = dir;
    int point = 0;
    

    while(1){ // 블랙홀을 만나거나 제자리로 돌아올 경우 끝
        // cout << "(" << ny << ", " << nx << ")" << endl;
        if((ny == sy && nx == sx) || map[ny][nx] == -1) break;
        int inhole = 0; // 웜홀에 들어갔는지

        if(ny >= 0 && ny < N && nx >= 0 && nx < N){
            if(map[ny][nx] > 0 && map[ny][nx] < 6){ // 블럭을 만난 경우, 포인트 올리고 방향 전환
                point++;
                ndir = crash(map[ny][nx], ndir);
            }
            else if(map[ny][nx] >= 6 && map[ny][nx] <= 10){ // 웜홀을 만난 경우, 반대 웜홀로
                inhole = 1; // 웜홀 진입
                int holenum = map[ny][nx];

                // 반대방향으로 나옴
                if(h[holenum].x1 == nx && h[holenum].y1 == ny){
                    ny = h[holenum].y2 + dy[ndir];
                    nx = h[holenum].x2 + dx[ndir];
                }
                else if(h[holenum].x2 == nx && h[holenum].y2 == ny){
                    ny = h[holenum].y1 + dy[ndir];
                    nx = h[holenum].x1 + dx[ndir];
                }
                //
            }
        }
        else if(ny < 0 || ny >= N || nx < 0 || nx >= N){ // 맵 밖으로 나가는 경우, 포인트 올리고 방향 반대
            point++;

            if(ndir == 0) ndir = 3;
            else if(ndir == 3) ndir = 0;
            else if(ndir == 1) ndir = 2;
            else if(ndir == 2) ndir = 1;

            // ny = ny + dy[ndir];
            // nx = nx + dx[ndir];
        }

        if(inhole == 0){ // 웜홀에 들어간게 아니라면 진입
            ny = ny + dy[ndir];
            nx = nx + dx[ndir];
        }
    }

    if(maxpoint < point) maxpoint = point;
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        cin >> N;
        maxpoint = 0;

        // 웜홀 초기화
        for(int j = 6 ; j <= 10 ; j++){
            h[j].x1 = -1;
            h[j].y1 = -1;
            h[j].x2 = -1;
            h[j].y2 = -1;
        }

        // 입력받고 웜홀이면 hole 구조체에 입출구 정보 넣어줌
        // 0 이면 핀볼을 놓을 수 있는 위치이므로 큐에 넣음
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];

                if(map[j][k] == 0) q.push(make_pair(j,k));
                
                if(map[j][k] >= 6 && map[j][k] <= 10){
                    if(h[map[j][k]].x1 == -1 && h[map[j][k]].y1 == -1){
                        h[map[j][k]].y1 = j;
                        h[map[j][k]].x1 = k;
                    }
                    else if(h[map[j][k]].x1 != -1 && h[map[j][k]].y1 != -1){
                        h[map[j][k]].y2 = j;
                        h[map[j][k]].x2 = k;
                    }
                }
            }
        }

        // cout << endl;
        // cout << "map : " << endl;
        // for(int j = 0 ; j < N ; j++){
        //     for(int k = 0 ; k < N ; k++){
        //         cout << map[j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << "hole : " << endl;;
        // for(int j = 6 ; j <= 10 ; j++){
        //     if(h[j].x1 != -1){
        //         cout << "hole " << j << ": " << endl << h[j].y1 << " " << h[j].x1 << endl << h[j].y2 << " " << h[j].x2 << endl;
        //         cout << endl;
        //     }
        // }
        // cout << endl;

        // 큐에서 위치를 하나씩 빼면서 공을 놓고 게임 시작
        while(!q.empty()){
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            sy = cy;
            sx = cx; // 시작 위치 기억 (도달하면 끝나기 때문)

            for(int j = 0 ; j < 4 ; j++){
                start_game(cy,cx, j);
            }
        }

        cout << "#" << i << " " << maxpoint << endl;
    }

    return 0;
}
/*
1
10
0 1 0 3 0 0 0 0 7 0 
0 0 0 0 -1 0 5 0 0 0 
0 4 0 0 0 3 0 0 2 2 
1 0 0 0 1 0 0 3 0 0 
0 0 3 0 0 0 0 0 6 0 
3 0 0 0 2 0 0 1 0 0 
0 0 0 0 0 1 0 0 4 0 
0 5 0 4 1 0 7 0 0 5 
0 0 0 0 0 1 0 0 0 0 
2 0 6 0 0 4 0 0 0 4 
*/
/*
#1 9
#2 0
#3 7
#4 5
#5 19
*/