// 백준 17780 새로운 게임
/*
    새로운 게임은 크기가 N×N인 체스판에서 진행되고, 사용하는 말의 개수는 K개
    하나의 말 위에 다른 말을 올릴 수 있다.
    체스판의 각 칸은 흰색, 빨간색, 파란색 중 하나로 색칠되어있다.
    게임은 체스판 위에 말 K개를 놓고 시작
    말은 1번부터 K번까지 번호가 매겨져 있고, 이동 방향도 미리 정해져 있다. 이동 방향은 위, 아래, 왼쪽, 오른쪽 4가지 중 하나
    턴 한 번은 1번 말부터 K번 말까지 순서대로 이동시키는 것
    한 말이 이동할 때 위에 올려져 있는 말도 함께 이동하며, 가장 아래에 있는 말만 이동
    말의 이동 방향에 있는 칸에 따라서 말의 이동이 다르며 아래와 같다. 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.

    A번 말이 이동하려는 칸이
        1. 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
            1-1. A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
            1-2. 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
        2. 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
            2-1. A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
            2-2. A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
        3. 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
        4. 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.

    게임이 종료되는 턴의 번호를 출력한다. 그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.
    체스판의 크기와 말의 위치, 이동 방향이 모두 주어졌을 때, 게임이 종료되는 턴의 번호를 구해보자.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Knight{
    int y;
    int x;
    int d;
};

int n,k;
int map[13][13]; // 각 정수는 칸의 색을 의미한다. 0은 흰색, 1은 빨간색, 2는 파란색이다.
vector<int> game[13][13]; // 말들이 들어있는 판
int dy[] = {0,0,-1,1}; // 0부터 순서대로 →, ←, ↑, ↓
int dx[] = {1,-1,0,0};
Knight kn[11];
int finish;

void print(){
    cout << "game:\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(game[i][j].empty() == true) cout << "0 ";
            else cout << game[i][j][0]+1 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "size: \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << game[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void red(int cy, int cx){
    stack<int> stk;
    for(int i = 0 ; i < game[cy][cx].size() ; i++) stk.push(game[cy][cx][i]);
    game[cy][cx].clear();

    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        game[cy][cx].push_back(cur);
    }
}

void move(int cy, int cx, int ny, int nx){
    for(int i = 0 ; i < game[cy][cx].size() ; i++){
        game[ny][nx].push_back(game[cy][cx][i]);
        kn[ game[cy][cx][i] ].y = ny;
        kn[ game[cy][cx][i] ].x = nx;
    }
    game[cy][cx].clear();
}

void play(){
    for(int i = 0 ; i < k ; i++){
        int cy = kn[i].y;
        int cx = kn[i].x;
        int cd = kn[i].d;

        if(game[cy][cx].size() > 1 && game[cy][cx][0] != i) continue; // 가장 아래의 말만 이동

        int ny = cy + dy[cd];
        int nx = cx + dx[cd];

        if(ny >= 0 && ny < n && nx >= 0 && nx < n){
            // 1. 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
            //     1-1. A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
            //     1-2. 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
            // 2. 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
            //     2-1. A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
            //     2-2. A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
            if(map[ny][nx] != 2){ // 흰색 or 빨간색
                if(map[ny][nx] == 1) red(cy,cx);

                move(cy,cx,ny,nx);

                if(game[ny][nx].size() >= 4){ // 4개 이상 쌓이면 종료
                    finish = 1;
                    return;
                }
            }
            // 3. 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
            //    방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
            else{
                if(cd == 0) cd = 1;
                else if(cd == 1) cd = 0;
                else if(cd == 2) cd = 3;
                else cd = 2;
                kn[i].d = cd;

                int nny = cy + dy[cd];
                int nnx = cx + dx[cd];

                if(nny >= 0 && nny < n && nnx >= 0 && nnx < n){
                    if(map[nny][nnx] != 2){
                        if(map[nny][nnx] == 1) red(cy,cx);

                        move(cy,cx, nny,nnx);

                        if(game[nny][nnx].size() >= 4){
                            finish = 1;
                            return;
                        }
                    }
                }
            }
        }
        // 4. 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
        else{
            if(cd == 0) cd = 1;
            else if(cd == 1) cd = 0;
            else if(cd == 2) cd = 3;
            else cd = 2;
            kn[i].d = cd;

            int nny = cy + dy[cd];
            int nnx = cx + dx[cd];

            if(nny >= 0 && nny < n && nnx >= 0 && nnx < n){
                if(map[nny][nnx] < 2){
                    if(map[nny][nnx] == 1) red(cy,cx);

                    move(cy,cx, nny,nnx);

                    if(game[nny][nnx].size() >= 4){
                        finish = 1;
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0 ; i < k ; i++){
        cin >> kn[i].y >> kn[i].x >> kn[i].d;
        kn[i].y--;
        kn[i].x--;
        kn[i].d--;
        game[kn[i].y][kn[i].x].push_back(i);
    }

    int turn = 0;

    while(1){
        if(turn > 1000) {
            cout << "-1\n";
            return 0;
        }

        turn++;
        play();
        if(finish == 1) break;
    }

    cout << turn << "\n";

    return 0;
}