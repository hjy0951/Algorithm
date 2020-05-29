// 백준 11559 Puyo Puyo
/*
    1. 필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.
    2. 뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.
    3. 뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.
    4. 아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.
    5. 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

    상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

char map[13][7];
queue<pair<int,int> > dead; // 터질 뿌요들이 들어갈 큐
bool visit[13][7];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(){
    cout << '\n';
    for(int i = 0 ; i < 12 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
void printv(){
    cout << '\n';
    for(int i = 0 ; i < 12 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(visit[i][j] == true) cout << '1';
            else cout << '0';
        }
        cout << '\n';
    }
    cout << '\n';
}

// bfs로 4개 이상의 뿌요들이 연속한지 확인
void bfs(int y, int x){
    queue<pair<int,int> > q;
    queue<pair<int,int> > dq;
    q.push(make_pair(y,x));
    dq.push(make_pair(y,x));

    visit[y][x] = true;
    char color = map[y][x];

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < 12 && nx >= 0 && nx < 6){
                if(visit[ny][nx] == false && map[ny][nx] == color){
                    dq.push(make_pair(ny,nx));
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = true;
                }
            }
        }
    }

    if(dq.size() >= 4){
        while(!dq.empty()){
            int yy = dq.front().first;
            int xx = dq.front().second;
            dq.pop();
            dead.push(make_pair(yy,xx));
        }
    }
}

void arrange(){
    for(int i = 0 ; i < 6 ; i++){
        int pos = 11;
        for(int j = 11 ; j >= 0 ; j--){
            if(map[j][i] != '.'){
                map[pos][i] = map[j][i];
                if(pos != j) map[j][i] = '.';
                pos--;
            }
        }
    }
}

int main(){
    for(int i = 0 ; i < 12 ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < 6 ; j++) map[i][j] = str[j];
    }

    int chain = 0; // 연쇄 수
    while(1){
        for(int i = 0 ; i < 6 ; i++){
            for(int j = 11 ; j >= 0 ; j--){
                if(map[j][i] == '.') break;

                if(visit[j][i] == false){
                    bfs(j,i);
                }
            }
        }

        if(dead.empty()) break;
        else{
            while(!dead.empty()){
                int cy = dead.front().first;
                int cx = dead.front().second;
                dead.pop();

                map[cy][cx] = '.';
            }
            arrange(); // 뿌요들을 정돈해줌
        }

        chain++;
        memset(visit,0,sizeof(visit));
    }
    cout << chain << '\n';
    return 0;
}