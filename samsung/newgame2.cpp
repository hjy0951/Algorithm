// 백준 17837 새로운 게임 2
/*
    새로운 게임은 크기가 N×N인 체스판에서 진행되고, 사용하는 말의 개수는 K개이다. 
    말은 원판모양이고, 하나의 말 위에 다른 말을 올릴 수 있다. 
    체스판의 각 칸은 흰색, 빨간색, 파란색 중 하나로 색칠되어있다.
    게임은 체스판 위에 말 K개를 놓고 시작한다. 
    말은 1번부터 K번까지 번호가 매겨져 있고, 이동 방향도 미리 정해져 있다. 이동 방향은 위, 아래, 왼쪽, 오른쪽 4가지 중 하나
    한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다. 
    말의 이동 방향에 있는 칸에 따라서 말의 이동이 다르며 아래와 같다. 
    턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.

    A번 말이 이동하려는 칸이
        1. 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
            1-1. A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
            1-2. 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
        2. 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
            2-1. A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
            2-2. A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
        3. 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
        4. 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Knight{
    int y;
    int x;
    int d;
};

int n,k;
int map[13][13];
Knight kn[11];
int finish;
vector<int> game[13][13];
int dy[] = {0,0,0,-1,1}; // 0부터 순서대로 →, ←, ↑, ↓
int dx[] = {0,1,-1,0,0};

void print(){
    cout << "game:\n";
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(game[i][j].empty() == true) cout << "0 ";
            else cout << game[i][j][0] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "dir: \n";
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(game[i][j].empty() == true) cout << "0 ";
            else cout << kn[game[i][j][0]].d << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void red(int cy, int cx, int ny, int nx, int cur){
    int s = 0;
    for(int i = 0 ; i < game[cy][cx].size() ; i++){
        if(game[cy][cx][i] == cur){
            s = i;
            break;
        }
    }

    stack<int> stk;
    for(int i = s ; i < game[cy][cx].size() ; i++) stk.push(game[cy][cx][i]);
    while(1){
        if(game[cy][cx][game[cy][cx].size()-1] == cur) break;
        game[cy][cx].pop_back();
    }
    game[cy][cx].pop_back();

    while(!stk.empty()){
        int c = stk.top();
        stk.pop();
        game[ny][nx].push_back(c);
        kn[c].y = ny;
        kn[c].x = nx;
    }
}

void move(int cy, int cx, int ny, int nx, int cur){
    int s = 0;
    for(int i = 0 ; i < game[cy][cx].size() ; i++){
        if(game[cy][cx][i] == cur){
            s = i;
            break;
        }
    }

    for(int i = s ; i < game[cy][cx].size() ; i++){
        game[ny][nx].push_back(game[cy][cx][i]);
        kn[ game[cy][cx][i] ].y = ny;
        kn[ game[cy][cx][i] ].x = nx;
    }

    while(1){
        if(game[cy][cx][game[cy][cx].size()-1] == cur) break;
        game[cy][cx].pop_back();
    }
    game[cy][cx].pop_back();
}

void play(){
    for(int i = 1 ; i <= k ; i++){
        int cy = kn[i].y;
        int cx = kn[i].x;
        int cd = kn[i].d;

        int ny = cy + dy[cd];
        int nx = cx + dx[cd];

        if(ny >= 1 && ny <= n && nx >= 1 && nx <= n){
            if(map[ny][nx] < 2){
                if(map[ny][nx] == 1) red(cy,cx,ny,nx,i);
                else move(cy,cx,ny,nx,i);

                if(game[ny][nx].size() >= 4){
                    finish = 1;
                    return;
                }
            }
            else{
                if(cd == 1) cd = 2;
                else if(cd == 2) cd = 1;
                else if(cd == 3) cd = 4;
                else cd = 3;
                kn[i].d = cd;

                int nny = cy + dy[cd];
                int nnx = cx + dx[cd];

                if(nny >= 1 && nny <= n && nnx >= 1 && nnx <= n){
                    if(map[nny][nnx] < 2){
                        if(map[nny][nnx] == 1) red(cy,cx,nny,nnx,i);
                        else if(map[nny][nnx] == 0) move(cy,cx, nny,nnx,i);

                        if(game[nny][nnx].size() >= 4){
                            finish = 1;
                            return;
                        }
                    }
                }
            }
        }
        else{
            if(cd == 1) cd = 2;
            else if(cd == 2) cd = 1;
            else if(cd == 3) cd = 4;
            else cd = 3;
            kn[i].d = cd;

            int nny = cy + dy[cd];
            int nnx = cx + dx[cd];

            if(nny >= 1 && nny <= n && nnx >= 1 && nnx <= n){
                if(map[nny][nnx] != 2){
                    if(map[nny][nnx] == 1) red(cy,cx,nny,nnx,i);
                    else if(map[nny][nnx] == 0) move(cy,cx,nny,nnx,i);

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
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1 ; i <= k ; i++){
        cin >> kn[i].y >> kn[i].x >> kn[i].d;
        game[ kn[i].y ][ kn[i].x ].push_back(i);
    }

    int turn = 0;
    while(1){
        if(turn > 1000){
            cout << "-1\n";
            return 0;
        }

        turn++;

        play();

        if(finish == 1) break;
    }

    cout << turn << '\n';
    return 0;
}