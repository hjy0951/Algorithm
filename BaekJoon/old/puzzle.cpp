// 백준 1525 퍼즐
/*
    어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다. 
    물론 표 바깥으로 나가는 경우는 불가능하다. 
    우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다
    최소 이동 횟수를 구하는 프로그램
    첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력
*/
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Puzzle{
    string str;
    int zy;
    int zx;
    int cnt;
};

int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int map[3][3];
int mincnt;
set<string> s;
queue<Puzzle> q;
string ans = "123456780";

void print(){
    cout << '\n';
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void copy(int arr[][3], string t){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            arr[i][j] = t[3*i + j] - '0';
        }
    }
}

void bfs(){
    Puzzle tp;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            tp.str.push_back(map[i][j] + '0');

            if(map[i][j] == 0){
                tp.zy = i;
                tp.zx = j;
            }
        }
    }
    tp.cnt = 0;
    s.insert(tp.str);
    q.push(tp);

    while(!q.empty()){
        int cy = q.front().zy;
        int cx = q.front().zx;
        int cc = q.front().cnt;
        copy(map, q.front().str);

        // cout << q.front().str << '\n';
        if(ans.compare(q.front().str) == 0){
            mincnt = cc;
            return;
        }
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;
            
            int temp = map[ny][nx];
            map[ny][nx] = map[cy][cx];
            map[cy][cx] = temp;
            
            Puzzle np;
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    np.str.push_back('0'+ map[j][k]);
                }
            }
            np.zy = ny;
            np.zx = nx;
            np.cnt = cc + 1;
            if(s.insert(np.str).second == true){
                q.push(np);
            }

            temp = map[ny][nx];
            map[ny][nx] = map[cy][cx];
            map[cy][cx] = temp;
        }
    }
}

int main(){
    mincnt = 987987987;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> map[i][j];
        }
    }

    bfs();

    if(mincnt == 987987987) cout << "-1\n";
    else cout << mincnt << '\n';

    return 0;
}