// 백준 17144 미세먼지 안녕!
/*
    공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지
    1초 동안 아래 적힌 일이 순서대로 일어난다.
    1. 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
        (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
        인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
        확산되는 양은 Ar,c/5이고 소수점은 버린다.
        (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
    2. 공기청정기가 작동한다.
        공기청정기에서는 바람이 나온다.
        위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
        바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
        공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

    방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int r,c,t;
int map[51][51];
int dust[51][51];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int air[2];
queue<pair<int,int> > q;

void printmap(int arr[][51]){
    cout << "\n";
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void spread(){
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        dust[cy][cx] += map[cy][cx];
        q.pop();

        if(map[cy][cx] > 0){
            for(int i = 0 ; i < 4 ; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                    if( (ny == air[0] && nx == 0) || (ny == air[1] && nx == 0) ) continue;
                    
                    dust[ny][nx] += map[cy][cx]/5;
                    dust[cy][cx] -= map[cy][cx]/5;
                }
            }
        }
    }

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            map[i][j] = dust[i][j];
        }
    }
}

void work(){
    // 윗부분
    int temp1 = map[ air[0] ][c - 1];
    for(int i = c-1 ; i > 0 ; i--) map[ air[0] ][i] = map[ air[0] ][i - 1];
    int temp2 = map[0][c - 1];
    for(int i = 0 ; i < air[0] - 1 ; i++) map[i][c-1] = map[i+1][c-1];
    map[ air[0] - 1 ][c - 1] = temp1;
    temp1 = map[0][0];
    for(int i = 0 ; i < c-1 ; i++) map[0][i] = map[0][i+1];
    map[0][c-2] = temp2;
    for(int i = air[0] ; i > 1 ; i--) map[i][0] = map[i-1][0];
    map[1][0] = temp1;

    // 아랫부분
    temp1 = map[ air[1] ][c - 1];
    for(int i = c-1 ; i > 0 ; i--) map[ air[1] ][i] = map[ air[1] ][i - 1];
    temp2 = map[r - 1][c - 1];
    for(int i = r-1 ; i > air[1] + 1 ; i--) map[i][c - 1] = map[i - 1][c - 1];
    map[air[1] + 1][c - 1] = temp1;
    temp1 = map[r-1][0];
    for(int i = 0 ; i < c-1 ; i++) map[r - 1][i] = map[r - 1][i + 1];
    map[r - 1][c - 2] = temp2;
    for(int i = air[1] ; i < r-1 ; i++) map[i][0] = map[i+1][0];
    map[r-2][0] = temp1;


    map[ air[0] ][0] = 0; // 공기청정기에 들어가면 정화
    map[ air[1] ][0] = 0;
}

int main(){
    cin >> r >> c >> t;
    int a = 0;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> map[i][j];
            if(map[i][j] > 0) q.push(make_pair(i,j));
            else if(map[i][j] == -1){
                air[a++] = i;
                map[i][j] = 0;
            }
        }
    }

    while(t--){
        memset(dust,0,sizeof(dust));
        spread(); // 미세먼지 확산
        work(); // 공기청정기 작동
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(map[i][j] > 0) q.push(make_pair(i,j));
            }
        }
    }

    int rest = 0;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(map[i][j] > 0) rest += map[i][j];
        }
    }
    cout << rest << "\n";
    return 0;
}

/*
    14:30 ~ 15:50
    확산되고 이동한 뒤의 미세먼지의 위치를 큐에 넣어야하는데, 확산 후 먼지의 위치를 바로 큐에 넣어 오래 걸렸다.
*/