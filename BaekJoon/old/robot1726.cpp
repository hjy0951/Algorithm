// 백준 1726 로봇
/*
    명령 1. Go k: k는 1, 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k칸 만큼 움직인다.
    명령 2. Turn dir: dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.
    
    로봇의 현재 위치와 바라보는 방향이 주어졌을 때, 로봇을 원하는 위치로 이동시키고, 
    원하는 방향으로 바라보도록 하는데 최소 몇 번의 명령이 필요한지 구하는 프로그램

    = 기존에 풀던 방식으로 풀었더니 주어진 예시와 게시판의 예시까지 모두 맞았지만 틀렸다.
      벽 부수고 이동하기 시리즈 처럼 visit 배열을 3차원으로 하여 방향을 고려해주어야 하는 문제였다.
      12번인가 제출하고 풀리지 않아 결국 블로그를 참조하였다.
      다음에 다시 기존 방식으로 visit배열을 2차원으로 해서 다시 풀어봐야겠다.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
int map[101][101]; // 1~100
bool visit[101][101][5];
int sy,sx,sd;
int ey,ex,ed;
// 방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4
int dy[] = {0,0,0,1,-1};
int dx[] = {0,1,-1,0,0};
int ans;

void print(){
    cout << '\n';
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                cout << visit[j][k][i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

int cmp_dir(int d1, int d2){
    if(d1 == 1){
        if(d2 == 3 || d2 == 4) return 1;
        else if(d2 == 2) return 2;
        else return 0;
    }
    else if(d1 == 2){
        if(d2 == 3 || d2 == 4) return 1;
        else if(d2 == 1) return 2;
        else return 0;
    }
    else if(d1 == 3){
        if(d2 == 1 || d2 == 2) return 1;
        else if(d2 == 4) return 2;
        else return 0;
    }
    else {
        if(d2 == 1 || d2 == 2) return 1;
        else if(d2 == 3) return 2;
        else return 0;
    }
}

void bfs(){
    queue<pair<int,int> > q;
    queue<int> dir;
    queue<int> cnt;
    q.push(make_pair(sy,sx));
    dir.push(sd);
    cnt.push(0);
    visit[sy][sx][sd] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int cd = dir.front();
        dir.pop();
        int cc = cnt.front();
        cnt.pop();

        if(cy == ey && cx == ex && cd == ed){
            ans = cc;
            return;
        }

        for(int i = 1 ; i <= 3 ; i++){
            int ny = cy + dy[cd] * i;
            int nx = cx + dx[cd] * i;

            if(ny < 1 || ny > n || nx < 1 || nx > m) break;
            if(map[ny][nx] == 1) break;
            if(visit[ny][nx][cd]) continue;

            visit[ny][nx][cd] = true;
            q.push(make_pair(ny,nx));
            dir.push(cd);
            cnt.push(cc + 1);
        }

        for(int i = 1 ; i <= 4 ; i++){
            if(cd == i) continue;
            if(visit[cy][cx][i]) continue;

            visit[cy][cx][i] = true;
            q.push(make_pair(cy,cx));
            dir.push(i);
            cnt.push(cc + cmp_dir(i,cd));
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> map[i][j];
        }
    }
    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;

    if(sy == ey && sx == ex){
        if(sd == ed) cout << "0\n";
        else{
            cout << cmp_dir(sd,ed) << '\n';
        }
        return 0;
    }

    bfs();
    cout << ans << '\n';
    return 0;
}
/*

5 6
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
5 2 4
*/