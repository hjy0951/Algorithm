// SWEA 등산로조성

/*
등산로를 만드는 규칙은 다음과 같다.

   ① 등산로는 가장 높은 봉우리에서 시작해야 한다.

   ② 등산로는 산으로 올라갈 수 있도록 반드시 높은 지형에서 낮은 지형으로 가로 또는 세로 방향으로 연결이 되어야 한다.
       즉, 높이가 같은 곳 혹은 낮은 지형이나, 대각선 방향의 연결은 불가능하다.

   ③ 긴 등산로를 만들기 위해 딱 한 곳을 정해서 최대 K 깊이만큼 지형을 깎는 공사를 할 수 있다.
*/

#include <iostream>
#include <cstring>

using namespace std;

int N,K; // 지도 크기 | 최대 공사 가능 깊이 (공사는 딱 한 번만 가능)
int map[10][10]; // 지도
int visit[10][10]; // 이미 조성된 길인지 확인
int maxh; // 가장 높은 지점
int maxn; // 가장 긴 등산로의 길이
int dy[] = {-1,1,0,0}; // 상하좌우 이동
int dx[] = {0,0,-1,1};

void maketrail(int y, int x, int curn, int ox){ // 현재 y,x | 등산로 현재 길이 | 공사 횟수
    if(maxn < curn) maxn = curn;

    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i]; // 다음 y,x
        int nx = x + dx[i];

        if(ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx] == 0){
            if(map[ny][nx] < map[y][x]){ // 현재 위치보다 다음 위치가 높이가 낮은 경우
                visit[ny][nx] = 1;
                maketrail(ny,nx, curn+1,ox);
                visit[ny][nx] = 0;
            }
            else { // 현재 위치보다 다음 위치가 높이가 높거나 같은 경우
                // 먼저, 공사 시행
                if(ox ==  0){
                    for(int j = 1 ; j <= K ; j++){
                        map[ny][nx] -= j;
                        K -= j;
                        if(map[ny][nx] < map[y][x]){ // 공사해서 높이가 낮아지면 이동
                            visit[ny][nx] = 1;
                            maketrail(ny,nx, curn+1,1); // ox를 1로 변경해주고 진행
                            visit[ny][nx] = 0;
                        }
                        K += j;
                        map[ny][nx] += j; // 공사 전으로 복구하여 다음 탐색에 영향 X
                    }
                }
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        maxh = 0;
        maxn = 0;
        memset(visit,0,sizeof(visit));

        // 지도 크기, 최대 공사 가능 깊이 입력
        cin >> N >> K;
        //지도 입력
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
                if(map[j][k] > maxh) maxh = map[j][k];
            }
        }

        // 탐색 및 등산로 조성
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                if(maxh == map[j][k]){ // 가장 높은 위치라면
                    visit[j][k] = 1;
                    maketrail(j,k,1,0); // 등산로 조성 시작
                    visit[j][k] = 0;
                }
            }
        }

        cout << "#" << i << " " << maxn << endl;
    }
    return 0;
}