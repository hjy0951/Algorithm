// 백준 3190 뱀
/*
    사과를 먹으면 뱀 길이가 늘어난다.
    뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
    NxN 정사각 보드위에서 진행, 사과가 놓여있음
    보드의 상하좌우 끝에 벽
    게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.

    이동 규칙
        먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Snake{
    int s; // 크기
    int sy;
    int sx;
    int ey;
    int ex;
    int d; // 0 : 오 | 1 : 왼 | 2 : 위 | 3 : 아래
};

int n;
int k;
int l;
int map[101][101];
int dmap[101][101];
// 이동 경로
int t[101]; // 시간
char dir[101]; // 방향
int p;
Snake sn;
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};
int fin;

void printmap(){
    cout << "\n";
    cout << "tail : " << sn.ey << " , " << sn.ex << "\n";
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init(){
    memset(dmap,-1,sizeof(dmap));
    sn.s = 1;
    sn.sy = 0;
    sn.sx = 0;
    sn.ey = 0;
    sn.ex = 0;
    sn.d = 0;
    map[0][0] = 1;
    dmap[0][0] = 0;
}

void move(){
    int ny = sn.sy + dy[sn.d];
    int nx = sn.sx + dx[sn.d];

    if(ny < 0 || ny >= n || nx < 0 || nx >= n){ // 벽에 닿은 경우
        fin = 1;
        return;
    }

    if(map[ny][nx] == 2){ // 사과를 먹은 경우
        map[ny][nx] = 1;
        dmap[ny][nx] = sn.d;
        sn.sy = ny;
        sn.sx = nx;
        sn.s = sn.s + 1;
    }
    else if(map[ny][nx] == 1){ // 자기몸에 닿은 경우
        fin = 1;
    }
    else{ // 빈칸으로 이동하는 경우
        // 앞으로 한칸 전진
        map[ny][nx] = 1;
        dmap[ny][nx] = sn.d;
        sn.sy = ny;
        sn.sx = nx;

        // 꼬리도 한칸 전진
        int ty = sn.ey;
        int tx = sn.ex;
        sn.ey = ty + dy[ dmap[ty][tx] ];
        sn.ex = tx + dx[ dmap[ty][tx] ];

        map[ty][tx] = 0;
        dmap[ty][tx] = -1;
        // int ty = sn.ey + dy[dmap[sn.ey][sn.ex]];
        // int tx = sn.ex + dx[dmap[sn.ey][sn.ex]];

        // map[sn.ey][sn.ex] = 0;
        // dmap[sn.ey][sn.ex] = -1;
        // sn.ey = ty;
        // sn.ex = tx;
    }
    return;
}

int main(){
    cin >> n; // 보드 크기
    cin >> k; // 사과 수
    for(int i = 0 ; i < k ; i++){
        int a,b;
        cin >> a >> b;
        map[a-1][b-1] = 2;
    }

    cin >> l; // 이동 경로
    for(int i = 0 ; i < l ; i++){
        cin >> t[i] >> dir[i];
    }

    init();
    int sec = 0;
    while(1){
        if(sec == t[p]){
            char cur = dir[p];
            if(sn.d == 0){
                if(cur == 'D') sn.d = 3;
                else if(cur == 'L') sn.d = 2;
            }
            else if(sn.d == 1){
                if(cur == 'D') sn.d = 2;
                else if(cur == 'L') sn.d = 3;
            }
            else if(sn.d == 2){
                if(cur == 'D') sn.d = 0;
                else if(cur == 'L') sn.d = 1;
            }
            else if(sn.d == 3){
                if(cur == 'D') sn.d = 1;
                else if(cur == 'L') sn.d = 0;
            }
            dmap[sn.sy][sn.sx] = sn.d;
            p++;
        }
        sec++;
        move();
        if(fin == 1) break;
    }
    cout << sec << "\n";

    return 0;
}

/*
    13:40 ~ 14:42
*/