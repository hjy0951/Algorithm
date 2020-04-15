// 백준 14499 주사위 굴리기
/*
      1
    3 0 2
      4
      5
    크기가 N×M인 지도
    지도의 오른쪽은 동쪽, 위쪽은 북쪽
    지도의 좌표 : (r, c) r는 북쪽으로부터 떨어진 칸의 개수(행), c는 서쪽으로부터 떨어진 칸의 개수(열)
    주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태
    놓여져 있는 곳의 좌표는 (x, y)
    가장 처음에 주사위에는 모든 면에 0
    주사위를 굴렸을 때
        이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
        0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
    주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램
    주사위는 지도의 바깥으로 이동시킬 수 없다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시
    이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력
    동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
*/
#include <iostream>

using namespace std;

int n, m;
int y, x; // x,y
int k;
int map[21][21];
int dice[6];
int top,bot;
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};
/*
  1
3 0 2
  4
  5
*/
void tumble(int dir){
    switch(dir){
        int temp;
        case 0: // 동
            temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
            break;
        case 1: // 서
            temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
            break;
        case 2: // 북
            temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
            break;
        case 3: // 남
            temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
            break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> y >> x >> k;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    if(map[y][x] != 0){
        dice[5] = map[y][x];
        map[y][x] = 0;
    }

    for(int i = 0 ; i < k ; i++){
        int dir;
        cin >> dir;
        dir--;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        tumble(dir);
        if(map[ny][nx] == 0){
            map[ny][nx] = dice[5];
        }
        else{
            dice[5] = map[ny][nx];
            map[ny][nx] = 0;
        }
        y = ny;
        x = nx;
        cout << dice[0] << "\n";
    }

    return 0;
}
/*
    14:50 ~ 15:06
    15:16 ~ 15:28
*/