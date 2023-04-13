// 백준 16985 Maaaaaaaaaze
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mindist;
int maze[5][5][5];
int map[5][5][5]; // zyx
bool used[5];
vector<int> m;
vector<int> op;
int dz[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dx[] = {0,0,0,0,1,-1};
bool zero;
bool one;

void print(int c){
    cout << '\n';
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout << map[c][i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void rotate(int cur){
    int temp[5][5];
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            temp[i][j] = maze[cur][i][j];
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            maze[cur][j][4-i] = temp[i][j];
        }
    }
    // if(c == 0){
    //     return;
    // }
    // else if(c == 1){
    //     for(int i = 0 ; i < 5 ; i++){
    //         for(int j = 0 ; j < 5 ; j++){
    //             arr[cur][j][4-i] = temp[i][j];
    //         }
    //     }
    // }
    // else if(c == 2){
    //     for(int i = 0 ; i < 5 ; i++){
    //         for(int j = 0 ; j < 5 ; j++){
    //             arr[cur][4-j][4-i] = temp[j][i];
    //         }
    //     }
    // }
    // else if(c == 3){
    //     for(int i = 0 ; i < 5 ; i++){
    //         for(int j = 0 ; j < 5 ; j++){
    //             arr[cur][4-j][i] = temp[i][j];
    //         }
    //     }
    // }
}

void copy(){
    for(int i = 0 ; i < 5 ; i++){
        int cur = m[i];
        for(int j = 0 ; j < 5 ; j++){
            for(int k = 0 ; k < 5 ; k++){
                maze[cur][j][k] = map[i][j][k];
            }
        }
    }
}

void bfs(){
    int visit[5][5][5] = {0,};
    queue<int> zq;
    queue<int> yq;
    queue<int> xq;
    zq.push(0);
    yq.push(0);
    xq.push(0);
    visit[0][0][0] = 1;

    while(!zq.empty()){
        int cz = zq.front();
        int cy = yq.front();
        int cx = xq.front();
        zq.pop();
        yq.pop();
        xq.pop();

        if(cz == 4 && cy == 4 && cx == 4){
            mindist = min(mindist,visit[cz][cy][cx]);
            return;
        }

        for(int i = 0 ; i < 6 ; i++){
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nz >= 0 && nz < 5 && ny >= 0 && ny < 5 && nx >= 0 && nx < 5){
                if(visit[nz][ny][nx] == 0 && maze[nz][ny][nx] == 1){
                    visit[nz][ny][nx] = visit[cz][cy][cx] + 1;
                    zq.push(nz);
                    yq.push(ny);
                    xq.push(nx);
                }
            }
        }
    }
}

void op_dfs(int cnt){
    if(cnt >= 5){
        copy();
        for(int i = 0 ; i < 5 ; i++){
            for(int j = 0 ; j < op[i] ; j++) rotate(i);
        }

        if(maze[0][0][0] == 1 && maze[4][4][4] == 1){
            bfs();
        }
        return;
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            op.push_back(i);
            op_dfs(cnt+1);
            op.pop_back();
        }
    }
}

void maze_dfs(int cnt){
    if(cnt == 5){
        op_dfs(0);
        return;
    }
    else{
        for(int i = 0 ; i < 5 ; i++){
            if(used[i]) continue;

            used[i] = true;
            m.push_back(i);
            maze_dfs(cnt+1);
            m.pop_back();
            used[i] = false;
        }
    }
}

int main(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            for(int k = 0 ; k < 5 ; k++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 0) zero = true;
                else if(map[i][j][k] == 1) one = true;
            }
        }
    }

    if(!zero){
        cout << "12\n";
        return 0;
    }
    if(!one){
        cout << "-1\n";
        return 0;
    }

    mindist = 987987987;

    maze_dfs(0);

    if(mindist == 987987987) cout << "-1\n";
    else cout << mindist-1 << '\n';
    
    return 0;
}