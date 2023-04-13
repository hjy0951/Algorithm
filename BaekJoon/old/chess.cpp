// 백준 1986 체스
/*
    상대팀의 Queen, Knight, Pawn의 위치가 주어져 있을 때, 안전한 칸이 몇 칸인지 세는 프로그램을 작성
    Queen은 가로, 세로, 대각선으로 갈 수 있는 만큼 최대한 많이 이동을 할 수 있는데 만약 그 중간에 장애물이 있다면 이동을 할 수 없다. 
    그리고 Knight는 2*3 직사각형을 그렸을 때, 반대쪽 꼭짓점으로 이동을 할 수 있다.
    Knight는 중간에 장애물이 있더라도 이동을 할 수 있다. 
    그리고 Pawn은 상대팀의 말은 잡을 수 없다고 하자(즉, 장애물의 역할만 한다는 것이다).
*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n,m;
int map[1001][1001];
vector<pair<int,int> > q;
vector<pair<int,int> > k;
// 나이트 이동
int dy[] = {2,2,-1,1,-2,-2,1,-1};
int dx[] = {1,-1,2,2,1,-1,-2,-2}; 

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void knight(int y, int x){
    map[y][x] = -2;
    for(int i = 0 ; i < 8 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(map[ny][nx] == 0){
                map[ny][nx] = 2;
            }
        }
    }

    // queue<pair<int,int> > kq;
    // kq.push(make_pair(y,x));
    // map[y][x] = 2;

    // while(!kq.empty()){
    //     int cy = kq.front().first;
    //     int cx = kq.front().second;
    //     kq.pop();

    //     for(int i = 0 ; i < 8 ; i++){
    //         int ny = cy + dy[i];
    //         int nx = cx + dx[i];

    //         if(ny >= 0 && ny < n && nx >= 0 && nx < m){
    //             if(map[ny][nx] == 0){
    //                 kq.push(make_pair(ny,nx));
    //                 map[ny][nx] = 2;
    //             }
    //         }
    //     }
    // }
}

void queen(int y, int x){
    int cy = y;
    int cx = x;
    map[y][x] = 3;

    while(1){
        if(cx < 0) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cx--;
    }
    cx = x;
    while(1){
        if(cx >= m) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cx++;
    }
    cx = x;
    while(1){
        if(cy < 0) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy--;
    }
    cy = y;
    while(1){
        if(cy >= n) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy++;
    }
    cy = y;
    while(1){
        if(cy < 0 || cx < 0) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy--;
        cx--;
    }
    cy = y;
    cx = x;
    while(1){
        if(cy >= n || cx >= m) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy++;
        cx++;
    }
    cy = y;
    cx = x;
    while(1){
        if(cy >= n || cx < 0) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy++;
        cx--;
    }
    cy = y;
    cx = x;
    while(1){
        if(cy < 0 || cx >= m) break;
        if(map[cy][cx] == 1 || map[cy][cx] < 0) break;
        map[cy][cx] = 3;
        cy--;
        cx++;
    }
}

int main(){
    cin >> n >> m;
    int t;
    cin >> t;
    // queen
    for(int i = 0 ; i < t ; i++){
        int y,x;
        cin >> y >> x;
        q.push_back(make_pair(y-1,x-1));
    }
    cin >> t;
    // knight
    for(int i = 0 ; i < t ; i++){
        int y,x;
        cin >> y >> x;
        k.push_back(make_pair(y-1,x-1));
    }
    cin >> t;
    //pawn
    for(int i = 0 ; i < t ; i++){
        int y,x;
        cin >> y >> x;
        map[y-1][x-1] = 1;
    }

    // knight 이동
    for(int i = 0 ; i < k.size() ; i++){
        int ky = k[i].first;
        int kx = k[i].second;
        knight(ky,kx);
    }
    // queen 이동
    for(int i = 0 ; i < q.size() ; i++){
        int qy = q[i].first;
        int qx = q[i].second;
        queen(qy,qx);
    }

    print();

    // 안전 영역
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 0) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}