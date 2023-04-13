// 백준 1400 화물차
/*
    도로망에서 차들은 동, 서, 남, 북의 방향으로만 이동할 수 있고, 지도의 각 문자는 다음과 같은 의미를 가진다.

        1. 'A'는 출발지 창고를 나타내고, 지도에서 유일하다.
        2. 'B'는 배송지 창고를 나타내고, 지도에서 유일하다.
        3. '.'은 차가 들어갈 수 없는 곳을 나타낸다.
        4. '#'은 각 도로 셀을 나타낸다. '#'은 기껏해야 두 개의 다른 도로 셀, 또는 교차로, 창고와 인접하다.
        5. 숫자 [0-9]는 신호등에 의해 제어되는 교차로를 나타낸다. 교차로는 적어도 세 개의 도로 셀과 인접하다. 
        교차로들은 0부터 9까지의 번호로 표시된다. 
        만일 번호 k를 가진 교차로가 있으면, 반드시 0부터 k까지 번호를 가진 교차로가 존재한다. 

    교차로의 신호등에 대한 설명은 아래에 나온다.
    차량의 이동은 다음과 같은 방식으로 분석된다.

        1. 화물차가 인접한 도로 셀, 또는 교차로, 창고로 이동하는 데 걸리는 시간을 단위 시간이라고 가정한다. 
           차량이 어떤 위치에서 멈춰 서 있는 시간도 단위 시간으로 측정된다.
        2. 화물차가 진입하려는 방향으로 파란불이 켜져 있을 때만 교차로로 들어갈 수 있다. 
           그러나 교차로에 들어간 차량은 언제든지 임의의 방향으로 나갈 수 있다.
        3. 교차로의 신호등은 동서 방향과 남북 방향, 두 개의 신호가 주기적으로 켜진다. 
           교차로의 신호는 초기에 동서 방향 또는 남북 방향이 될 수 있다. 
           교차로의 신호 주기를 나타내는 값 "a b"는 동서 방향의 신호가 a 시간 켜지고, 남북 방향의 신호가 b 시간 켜짐을 의미한다. 
           예를 들어, 초기에 남북 방향의 신호가 켜지고 주기 값이 "2 3"이면, 차량이 1-3 시간에 남북 방향의 신호가 켜지고, 
           4-5 시간은 동서 방향, 6-8 시간은 다시 남북 방향의 신호가 켜진다.

    출발지 창고에서 배송지 창고까지 최단 경로를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
char map[30][30];
bool visit[30][30];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int ccnt; // 교차로 개수
int cross[10][3]; // 교차로 정보  0: 초기 방향 | 1: 동서 시간 | 2: 남북 시간
int mindist;
int sy,sx,ey,ex;

void bfs(){
    queue<pair<int,int> > q;
    queue<int> dq;
    q.push(make_pair(sy,sx));
    dq.push(0);
    visit[sy][sx] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second; // 현위치
        q.pop();
        int cd = dq.front(); // 출발 이후 지금까지의 거리
        dq.pop();

        if(cy == ey && cx == ex){ // 창고 도착
            mindist = min(mindist, cd);
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 범위 밖
            if(map[ny][nx] == '.') continue; // 갈 수 없는 길
            if(visit[ny][nx]) continue; // 이미 방문

            if(map[ny][nx] == '#'){ // 일반 길 이용
                visit[ny][nx] = true;
                q.push(make_pair(ny,nx));
                dq.push(cd+1);
            }
            // 교차로 도착
            else if(map[ny][nx] >= '0' && map[ny][nx] <= '9'){
                int cur = map[ny][nx] - '0';  // 현재 교차로 번호
                int ew = cross[cur][1]; // 동서 시간
                int sn = cross[cur][2]; // 남북 시간
                int temp = cd % (ew + sn);

                if(cross[cur][0] == 0){
                    if(i <= 1){
                        if(temp >= 0 && temp < ew){
                            visit[ny][nx] = true;
                            q.push(make_pair(ny,nx));
                            dq.push(cd+1);
                        }
                        else{
                            q.push(make_pair(cy,cx));
                            dq.push(cd+1);
                        }
                    }
                    else{
                        if(temp >= ew && temp < sn + ew){
                            visit[ny][nx] = true;
                            q.push(make_pair(ny,nx));
                            dq.push(cd+1);
                        }
                        else{
                            q.push(make_pair(cy,cx));
                            dq.push(cd+1);
                        }
                    }
                }
                else{
                    if(i <= 1){
                        if(temp >= sn && temp < sn + ew){
                            visit[ny][nx] = true;
                            q.push(make_pair(ny,nx));
                            dq.push(cd+1);
                        }
                        else{
                            q.push(make_pair(cy,cx));
                            dq.push(cd+1);
                        }
                    }
                    else{
                        if(temp >= 0 && temp < sn){
                            visit[ny][nx] = true;
                            q.push(make_pair(ny,nx));
                            dq.push(cd+1);
                        }
                        else {
                            q.push(make_pair(cy,cx));
                            dq.push(cd+1);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        mindist = 987987987;
        ccnt = 0;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        for(int i = 0 ; i < n ; i++){
            string str;
            cin >> str;
            for(int j = 0 ; j < m ; j++){
                map[i][j] = str[j];

                if(map[i][j] >= '0' && map[i][j] <= '9') ccnt++;
                else if(map[i][j] == 'A'){
                    sy = i;
                    sx = j;
                    map[i][j] = '#';
                }
                else if(map[i][j] == 'B'){
                    ey = i;
                    ex = j;
                    map[i][j] = '#';
                }
            }
        }

        for(int i = 0 ; i < ccnt ; i++){
            int x,a,b;
            char d;
            cin >> x >> d >> a >> b;

            if(d == '-'){ // 동서 먼저
                cross[x][0] = 0;
            }
            else{ // 남북 먼저
                cross[x][0] = 1;
            }
            cross[x][1] = a;
            cross[x][2] = b;
        }
        bfs();

        if(mindist == 987987987) cout << "impossible\n";
        else cout << mindist << '\n';
        memset(visit,0,sizeof(visit));
    }
    return 0;
}