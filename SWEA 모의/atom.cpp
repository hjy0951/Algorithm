#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
#define POLAR 1000

struct Atom{
    int n;
    int x;
    int y;
    int nextx;
    int nexty;
    int dir;
    int e;
    int live;
    int moved;
};

int t;
int N;
int atnum;
Atom at[1100];
int map[2001][2001]; // (-) 0 ~ 999 | (0) 1000 | (+) 1001~2000
int total_e;
int dy[] = {1,-1,0,0}; // 상 하 좌 우
int dx[] = {0,0,-1,1};

int maxx;
int minx;
int maxy;
int miny;

queue<pair<int,int> > q;

int half_check(Atom a1, Atom a2, int d){ // 0.5 초 사이에 만나면 1 아니면 0
    if(d == 0){
        if(a1.dir == 0 && a2.dir == 1){
            return 1;
        }
    }
    else if(d == 1){
        if(a1.dir == 1 && a2.dir == 0){
            return 1;
        }
    }
    else if(d == 2){
        if(a1.dir == 2 && a2.dir == 3){
            return 1;
        }
    }
    else if(d == 3){
        if(a1.dir == 3 && a2.dir == 2){
            return 1;
        }
    }
    return 0;
}

void move(){
    while(atnum > 0){

        for(int i = 0 ; i < N ; i++){
            if(at[i].live == 0) continue;

            map[at[i].y][at[i].x] = at[i].n;
            
            int cy = at[i].y;
            int cx = at[i].x;

            for(int j = 0 ; j < 4 ; j++){
                int ty = cy + dy[j];
                int tx = cx + dx[j];

                if(ty >= 0 && ty <= 2000 && tx >= 0 && tx <= 2000){
                    if(map[ty][tx] > 0){
                        int ox = half_check(at[i], at[map[ty][tx] - 1], j); 
                        if(ox == 1){
                            at[map[ty][tx]-1].live = 0;
                            at[i].live = 0;

                            total_e += at[i].e;
                            total_e += at[map[ty][tx]-1].e;

                            atnum -= 2;

                            map[ty][tx] = 0;
                            map[cy][cx] = 0;
                        }
                    }
                }
            }

            if( (at[i].y >= maxy && at[i].dir == 0) || (at[i].y <= miny && at[i].dir == 1) ){
                at[i].live = 0;
                atnum--;
                map[at[i].y][at[i].x] = 0;
            }
            if( (at[i].x >= maxx && at[i].dir == 3) || (at[i].x <= minx && at[i].dir == 2) ){
                at[i].live = 0;
                atnum--;
                map[at[i].y][at[i].x] = 0;
            }
        }

        for(int i = 0 ; i < N ; i++){
            if(at[i].live == 0) continue;

            int ny = at[i].y;
            int nx = at[i].x;
            // cout << endl << "n & dir: " << at[i].n << " " << at[i].dir << endl; 
            switch(at[i].dir){            
                case 0: // 상
                    ny += 1;
                    break;
                case 1: // 하
                    ny -= 1;
                    break;
                case 2: // 좌
                    nx -= 1;
                    break;
                case 3: // 우
                    nx += 1;
                    break;
            }

            if(ny >= 0 && ny <= 2000 && nx >= 0 && nx <= 2000){
                at[i].nexty = ny;
                at[i].nextx = nx;
                at[i].moved = 1;
            }
            else{
                at[i].live = 0;
                atnum--;
                map[at[i].y][at[i].x] = 0;
            }
        }

        for(int i = 0 ; i < N ; i++){
            if(at[i].live == 0) continue;

            int cy = at[i].nexty;
            int cx = at[i].nextx;

            if(map[cy][cx] == 0 || (map[cy][cx] > 0 && at[map[cy][cx]-1].moved == 1) ){
                map[cy][cx] = at[i].n;
                if(map[at[i].y][at[i].x] == at[i].n) map[at[i].y][at[i].x] = 0;
                at[i].y = at[i].nexty;
                at[i].x = at[i].nextx;
            }
            else if(map[cy][cx] > 0 && at[map[cy][cx]-1].moved == 0){
                at[map[cy][cx] - 1].live = 0;
                at[i].live = 0;

                total_e += at[i].e;
                total_e += at[map[cy][cx] - 1].e;
                atnum -= 2;
                map[cy][cx] = -1; // 충돌이 일어난 곳
                q.push(make_pair(cy,cx));
                if(map[at[i].y][at[i].x] == at[i].n) map[at[i].y][at[i].x] = 0;
            }
            else if(map[cy][cx] == -1){ // 이미 충돌이 일어난 곳에 도달
                at[i].live = 0;
                total_e += at[i].e;
                atnum -= 1;
                if(map[at[i].y][at[i].x] == at[i].n) map[at[i].y][at[i].x] = 0;
            }

            at[i].moved = 0;
        }

        while(!q.empty()){
            int ty = q.front().first;
            int tx = q.front().second;
            q.pop();

            map[ty][tx] = 0;
        }

    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        maxx = -987987980;
        maxy = -987987980;
        minx = 987987987;
        miny = 987987987;
        t = i;

        cin >> N;
        for(int j = 0 ; j < N ; j++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;

            if(j==0){
                maxx = a;
                maxy = b;
                minx = a;
                miny = b;
            }
            else{
                if(a > maxx) maxx = a;
                if(a < minx) minx = a;
                if(b > maxy) maxy = b;
                if(b < miny) miny = b;
            }

            at[j].n = j+1;
            at[j].x = a + POLAR;
            at[j].y = b + POLAR;
            at[j].dir = c;
            at[j].e = d;
            at[j].live = 1;
            at[j].moved = 0;
        }
        maxx += POLAR;
        maxy += POLAR;
        minx += POLAR;
        miny += POLAR;
        // cout << maxx << " " << minx << endl;
        // cout << maxy << " " << miny << endl;
        // cout << endl;
        atnum = N;
        total_e = 0;


        move();

        cout << "#" << i << " " << total_e << endl;
        while(!q.empty()){
            int ty = q.front().first;
            int tx = q.front().second;
            q.pop();

            map[ty][tx] = 0;
        }
    }

    return 0;
}
/*
#1 24
#2 0
*/
/*
2
4
-1000 0 3 5
1000 0 2 3
0 1000 1 7
0 -1000 0 9
4
-1 1 3 3
0 1 1 1
0 0 2 2
-1 0 0 9
*/
/*
1
4
-1 1 3 3
0 1 1 1
0 0 2 2
-1 0 0 9
*/