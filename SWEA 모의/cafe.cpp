#include <cstdio>
#include <iostream>

using namespace std;

int N;
int map[25][25];
int visit[25][25];
int check[101];
int dy[] = {1,1,-1,-1};
int dx[] = {1,-1,-1,1};
int maxn;
int sy;
int sx;

void find(int y, int x, int n, int dir){
    if(y < 0 || y >= N || x < 0 || x >= N || check[map[y][x]] != 0 || visit[y][x] != 0){
        return;
    }
    else if(y == sy && x == sx && n >= 4 && dir == 3){
        // cout << endl;
        // cout << "find!" << endl;
        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < N ; j++){
        //         if(i == sy && j == sx) cout << 's' << " ";
        //         else cout << visit[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if(maxn < n) maxn = n;
        return;
    }
    else{
        // cout << endl;
        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < N ; j++){
        //         if(i == sy && j == sx) cout << 's' << " ";
        //         else cout << visit[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if(n != 1){
            visit[y][x] = n;
            check[map[y][x]] = 1;
        }

        switch(dir){
            case 0:
                find(y+dy[0], x+dx[0], n+1, 0);
            case 1:
                find(y+dy[1], x+dx[1], n+1, 1);
            case 2:
                find(y+dy[2], x+dx[2], n+1, 2);
            case 3:
                find(y+dy[3], x+dx[3], n+1, 3);
                break;
        }
        visit[y][x] = 0;
        check[map[y][x]] = 0;
        
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i<= T ; i++){
        // memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        memset(check,0,sizeof(check));
        maxn = 0;

        cin >> N;
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
            }
        }

        for(int j = 0 ; j < N ; j++){
            for(int k = 1 ; k < N-1 ; k++){
                // visit[j][k] = 1;
                sy = j;
                sx = k;
                find(j,k,1,0);
                memset(visit,0,sizeof(visit));
                memset(check,0,sizeof(check));
            }
        }

        // if(maxn == 0) maxn = -1;

        cout << "#" << i << " " << maxn-1 << endl;
    }

    
    return 0;
}
/*
#1 6
#2 -1
#3 4
#4 4
#5 8
#6 6
#7 14
#8 12
#9 18
#10 30
*/
/*
1
4
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5

1
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
*/