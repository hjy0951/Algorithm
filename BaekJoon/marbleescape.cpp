// 백준 13460 구슬 탈출 2
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;
char map[11][11];
int ry,rx;
int by,bx;
int ey,ex;
int mincnt;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int inv_dir(int dir){
    if(dir == 0) return 1;
    else if(dir == 1) return 0;
    else if(dir == 2) return 3;
    else return 2;
}

void dfs(int y, int x, int cby, int cbx, int dir, int cnt){
    // cout << y << " , " << x << " , " << cby << " , " << cbx << " , " << dir << " , " << cnt << '\n';
    if(cnt > 9) return;
    
    int ny = y;
    int nx = x;
    int rcnt = 0;
    bool rfin = false;
    while(1){
        rcnt++;
        ny += dy[dir];
        nx += dx[dir];

        if(map[ny][nx] == '#'){
            ny -= dy[dir];
            nx -= dx[dir];
            rcnt--;
            break;
            
        }
        else if(map[ny][nx] == 'O'){
            rfin = true;
            break;
        }
    }

    int nby = cby;
    int nbx = cbx;
    int bcnt = 0;
    bool bfin = false;
    while(1){
        bcnt++;
        nby += dy[dir];
        nbx += dx[dir];

        if(map[nby][nbx] == '#'){
            nby -= dy[dir];
            nbx -= dx[dir];
            bcnt--;
            break;
            
        }
        else if(map[nby][nbx] == 'O'){
            bfin = true;
            break;
        }
    }

    if(bfin) return;
    else{
        if(rfin){
            mincnt = min(mincnt, cnt);
            return;
        }
    }

    if(ny == nby && nx == nbx){
        if(rcnt > bcnt){
            ny -= dy[dir];
            nx -= dx[dir];
        }
        else if(rcnt < bcnt){
            nby -= dy[dir];
            nbx -= dx[dir];
        }
    }

    for(int i = 0 ; i < 4 ; i++){
        if(i == dir) continue;
        if(i == inv_dir(dir)) continue;

        dfs(ny,nx,nby,nbx,i,cnt+1);
    }
}

int main(){
    mincnt = 987987987;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];

            if(map[i][j] == 'R'){
                ry = i;
                rx = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B'){
                by = i;
                bx = j;
                map[i][j] = '.';
            }
        }
    }

    for(int i = 0 ; i < 4 ; i++){
        int y = ry;
        int x = rx;
        int yy = by;
        int xx = bx;

        dfs(y,x,yy,xx,i,0);
    }

    if(mincnt == 987987987) cout << "-1\n";
    else cout << mincnt+1 << '\n';

    return 0;
}