// 백준 13901 로봇
/*
    1. 로봇은 사용자가 지정한 방향을 일직선으로 움직인다.
    2. 이동 중 벽이나 방문한 지역, 장애물을 만날 경우 로봇은 사용자가 지정한 다음 방향으로 움직인다.
    3. 사용자가 지정한 다음 방향이 없다면 맨 처음 방향으로 돌아가서 위의 과정을 반복한다.
    4. 로봇이 움직일 수 없을 경우 동작을 멈춘다. 
*/
#include <iostream>

using namespace std;

int r,c,k;
int map[1001][1001];
int visit[1001][1001];
int ry, rx;
// 1은 위 방향, 2은 아래 방향, 3은 왼쪽 방향, 4는 오른쪽 방향
int dy[] = {0,-1,1,0,0};
int dx[] = {0,0,0,-1,1};
int dir[4];
int cnt;

void print(int arr[][1001]){
    cout << '\n';
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void move(){
    int blk = 0;
    visit[ry][rx] = 1;
    while(1){
        int cy = ry;
        int cx = rx;

        int ny = ry + dy[dir[cnt%4]];
        int nx = rx + dx[dir[cnt%4]];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c){
            blk++;
            cnt++;
            continue;
        }

        if(visit[ny][nx] == 0 && map[ny][nx] == 0){
            blk = 0;
            ry = ny;
            rx = nx;
            visit[ry][rx] = visit[cy][cx] + 1;
        }
        else{
            cnt++;
            blk++;
        }

        if(blk == 4) break;
    }
}

int main(){
    cin >> r >> c;
    cin >> k;
    for(int i = 0 ; i < k ; i++){
        int br, bc;
        cin >> br >> bc;
        map[br][bc] = 1;
    }
    cin >> ry >> rx;
    for(int i = 0 ; i < 4 ; i++) cin >> dir[i];

    print(map);

    move();
    
    cout << ry << " " << rx << '\n';
    print(visit);

    return 0;
}