// 백준 1938 통나무 옮기기
/*
    지형은 0과 1로 나타나 있다
    1은 아직 잘려지지 않은 나무를 나타내고 0은 아무 것도 없음
    길이 3인 통나무 BBB를 밀거나 회전시켜 EEE의 위치로 옮기는 작업
    * 명령 *
        U	통나무를 위로 한 칸 옮긴다.
        D	통나무를 아래로 한 칸 옮긴다.
        L	통나무를 왼쪽으로 한 칸 옮긴다.
        R	통나무를 오른쪽으로 한 칸 옮긴다.
        T	중심점을 중심으로 90도 회전시킨다.
    움직일 위치에 다른 나무, 즉 1이 없어야만 움직일 수 있다
    한 번에 한 칸씩만 움직인다
    회전의 경우에서는 반드시 중심점을 중심으로 90도 회전
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n;
int map[50][50];
int visit[2][50][50];
int s[3][2];
int e[3][2];
int dy[] = {0,0,-1,1,-1,1,1,-1};
int dx[] = {1,-1,0,0,-1,1,-1,1};
queue<pair<int,int> > q;
queue<int> dirq;

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout <<  visit[0][i][j]  << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout <<  visit[1][i][j]  << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool U(int y, int x, int d){
    if(d == 0){ // 세로
        if(y-2 < 0) return false;
        
        if(map[y-2][x] == 1) return false;
        else return true;
    }
    else if(d == 1){ // 가로
        if(y == 0) return false;
        
        if(map[y-1][x-1] == 1 || map[y-1][x] == 1 || map[y-1][x+1] == 1) return false;
        else  return true;
    }
    return true;
}

bool D(int y, int x, int d){
    if(d == 0){ // 세로
        if(y + 2 >= n) return false;
        
        if(map[y+2][x] == 1) return false;
        else return true;
    }
    else if(d == 1){ // 가로
        if(y == n-1) return false;
        
        if(map[y+1][x-1] == 1 || map[y+1][x] == 1 || map[y+1][x+1] == 1) return false;
        else return true;
    }
    return true;
}

bool L(int y, int x, int d){
    if(d == 0){ // 세로
        if(x == 0) return false;
        
        if(map[y-1][x-1] == 1 || map[y][x-1] == 1 || map[y+1][x-1] == 1) return false;
        else return true;
    }
    else if(d == 1){ // 가로
        if(x-2 < 0) return false;
        
        if(map[y][x-2] == 1) return false;
        else return true;        
    }
    return true;
}

bool R(int y, int x, int d){
    if(d == 0){ // 세로
        if(x == n-1) return false;
        
        if(map[y-1][x+1] == 1 || map[y][x+1] == 1 || map[y+1][x+1] == 1) return false;
        else return true;
    }
    else if(d == 1){ // 가로
        if(x + 2 >= n) return false;
        
        if(map[y][x+2] == 1) return false;
        else return true;
    }
    return true;
}

bool T(int y, int x){
    if(y ==  0 || x == 0 || y == n-1  || x == n-1) return false;

    for(int i = 0 ; i < 8 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(map[ny][nx] == 1) return false;
    }
    return true;
}

void bfs(){
   while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        int cd = dirq.front();
        q.pop();
        dirq.pop();

        bool rot = T(cy,cx);

        if(cd == 0){ // 세로
            if(U(cy,cx,cd) == true && (visit[0][cy-1][cx] == 0 || visit[cd][cy][cx] + 1 < visit[0][cy-1][cx])){
                visit[0][cy-1][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy-1,cx));
                dirq.push(0);
            }
            if(D(cy,cx,cd) == true && (visit[0][cy+1][cx] == 0 || visit[cd][cy][cx] + 1 < visit[0][cy+1][cx])){
                visit[0][cy+1][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy+1,cx));
                dirq.push(0);
            }
            if(L(cy,cx,cd) == true && (visit[0][cy][cx-1] == 0 || visit[cd][cy][cx] + 1 < visit[0][cy][cx-1])){
                visit[0][cy][cx-1] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx-1));
                dirq.push(0);
            }
            if(R(cy,cx,cd) == true && (visit[0][cy][cx+1] == 0 || visit[cd][cy][cx] + 1 < visit[0][cy][cx+1])){
                visit[0][cy][cx+1] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx+1));
                dirq.push(0);
            }

            if(rot == true && (visit[1][cy][cx] == 0 || visit[cd][cy][cx] + 1 < visit[1][cy][cx])){
                visit[1][cy][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx));
                dirq.push(1);
            }
        }
        else if(cd == 1){ // 가로
            if(U(cy,cx,cd) == true && (visit[1][cy-1][cx] == 0 || visit[cd][cy][cx] + 1 < visit[1][cy-1][cx])){
                visit[1][cy-1][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy-1,cx));
                dirq.push(1);
            }
            if(D(cy,cx,cd) == true && (visit[1][cy+1][cx] == 0 || visit[cd][cy][cx] + 1 < visit[1][cy+1][cx])){
                visit[1][cy+1][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy+1,cx));
                dirq.push(1);
            }
            if(L(cy,cx,cd) == true && (visit[1][cy][cx-1] == 0 || visit[cd][cy][cx] + 1 < visit[1][cy][cx-1])){
                visit[1][cy][cx-1] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx-1));
                dirq.push(1);
            }
            if(R(cy,cx,cd) == true && (visit[1][cy][cx+1] == 0 || visit[cd][cy][cx] + 1 < visit[1][cy][cx+1])){
                visit[1][cy][cx+1] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx+1));
                dirq.push(1);
            }

            if(rot == true && (visit[0][cy][cx] == 0 || visit[cd][cy][cx] + 1 < visit[0][cy][cx])){
                visit[0][cy][cx] = visit[cd][cy][cx] + 1;
                q.push(make_pair(cy,cx));
                dirq.push(0);
            }
        }
   }
}

int main(){
    cin >> n;
    int si = 0;
    int ei = 0;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < str.size() ; j++){
            if(str[j] == 'B'){
                s[si][0] = i;
                s[si++][1] = j;
                map[i][j] = 0;
            }
            else if(str[j] == 'E'){
                e[ei][0] = i;
                e[ei++][1] = j;
                map[i][j] = 0;
            }
            else{
                map[i][j] = str[j] - '0';
            }
        }
    }

    q.push(make_pair(s[1][0], s[1][1]));
    if(s[0][0] == s[2][0]){ // 가로로 시작
        visit[1][s[1][0]][s[1][1]] = 1;
        dirq.push(1);
    }
    else if(s[0][1] == s[2][1]){ // 세로로 시작
        visit[0][s[1][0]][s[1][1]] = 1;
        dirq.push(0);
    }

    bfs();

    if(e[0][0] == e[2][0]){ // 가로
        if(visit[1][ e[1][0] ][ e[1][1] ]) cout << visit[1][ e[1][0] ][ e[1][1] ] - 1 << "\n";
        else cout << "0\n";
    }
    else if(e[0][1] == e[2][1]){ // 세로
        if(visit[0][e[1][0]][e[1][1]]) cout << visit[0][ e[1][0] ][ e[1][1] ] - 1 << "\n";
        else cout << "0\n";
    }
    return 0;
}
/*
5
B0011
B0000
B0000
11000
EEE00
*/