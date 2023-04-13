// 백준 6593 상범빌딩
#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int l,r,c;
int map[30][30][30];
int visit[30][30][30];
int sz, sy, sx;
int ez, ey, ex;
int dz[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dx[] = {0,0,0,0,1,-1};

void bfs(){
    queue<int> zq;
    queue<int> yq;
    queue<int> xq;

    zq.push(sz);
    yq.push(sy);
    xq.push(sx);

    visit[sz][sy][sx] = 1;

    while(!zq.empty()){
        int cz = zq.front();
        int cy = yq.front();
        int cx = xq.front();
        zq.pop();
        yq.pop();
        xq.pop();

        for(int i = 0 ; i < 6 ; i++){
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nz >= 0 && nz < l && ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(visit[nz][ny][nx] == 0 && map[nz][ny][nx] == 1){
                    visit[nz][ny][nx] = visit[cz][cy][cx] + 1;
                    zq.push(nz);
                    yq.push(ny);
                    xq.push(nx);
                    
                }
            }
        }
    }
}

int main(){
    l = -1, r = -1, c = -1;
    while(1){
        // cin >> l >> r >> c;
        scanf(" %d %d %d", &l, &r, &c);
        if(l == 0 && r == 0 && c == 0) return 0;

        for(int i = 0 ; i < l ; i++){
            for(int j = 0 ; j < r ; j++){
                for(int k = 0 ; k < c ; k++){
                    char a;
                    scanf(" %1c", &a);

                    if(a == 'S'){
                        map[i][j][k] = 1;
                        sz = i;
                        sy = j;
                        sx = k;
                    }
                    else if(a == 'E'){
                        map[i][j][k] = 1;
                        ez = i;
                        ey = j;
                        ex = k;
                    }
                    else if(a == '#'){
                        map[i][j][k] = 0;
                    }
                    else{
                        map[i][j][k] = 1;
                    }
                }
                // string str;
                // cin >> str;
                // for(int k = 0 ; k < str.size() ; k++){
                //     if(str[k] == 'S'){
                //         map[i][j][k] = 1;
                //         sz = i;
                //         sy = j;
                //         sx = k;
                //     }
                //     else if(str[k] == 'E'){
                //         map[i][j][k] = 1;
                //         ez = i;
                //         ey = j;
                //         ex = k;
                //     }
                //     else if(str[k] == '#'){
                //         map[i][j][k] = 0;
                //     }
                //     else{
                //         map[i][j][k] = 1;
                //     }
                // }
            }
        }

        bfs();

        if(visit[ez][ey][ex] != 0) printf("Escaped in %d minute(s).\n", visit[ez][ey][ex]-1);
            // cout << "Escaped in " << visit[ez][ey][ex]-1 << " minute(s).\n";
        else printf("Trapped!\n");
            // cout << "Trapped!\n";

        memset(visit,0,sizeof(visit));
    }
    
    return 0;
}

/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

*/