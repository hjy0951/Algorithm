#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[10][10];
int N,K;
int maxtrail;
int dy[] = {0,1,-1,0};
int dx[] = {1,0,0,-1};
int visit[10][10];

void maketrail(int cy,int cx, int cur, int use){
    int cnt = 0;

    // for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < N ; j++){
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << endl;

    for(int i = 0 ; i < 4 ; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(visit[ny][nx] != 0 || ny < 0 || nx < 0 || ny >= N || nx >= N){
            cnt++;
            if(cnt == 4){
                if(cur > maxtrail) maxtrail = cur;
                return;
            }
            continue;
        }

        if( use == 1 && (map[cy][cx] <= map[ny][nx]) ){
            cnt++;
            if(cnt == 4){
                if(cur > maxtrail) maxtrail = cur;
                return;
            }
            continue;
        }

        if( use == 0 && (map[cy][cx] <= map[ny][nx]) ){
            for(int j = K ; j > 0 ; j--){
                use = 1;
                // visit[cy][cx] = 1;
                map[ny][nx] -= j;
                maketrail(cy,cx,cur,use);
                map[ny][nx] += j;
                // visit[cy][cx] = 0;
                use = 0;
            }
        }

        if(map[cy][cx] > map[ny][nx]){
            visit[ny][nx] = 1;
            maketrail(ny,nx,cur+1,use);
            visit[ny][nx] = 0;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int i = 1 ; i <= T ; i++){
        cin >> N >> K;

        maxtrail = 0;
        for(int j = 0 ; j < N ; j++){
            memset(map[j], 0, sizeof(map[j]));
        }
        
        int maxn = 0;
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
                if(maxn < map[j][k]) maxn = map[j][k];
            }
        }

         for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                if(maxn == map[j][k]){
                    visit[j][k] = 1;
                    maketrail(j,k,1,0);
                    visit[j][k] = 0;
                }
            }
        }
        cout << "#" << i << " " << maxtrail << endl;
        maxtrail = 0;
        memset(visit, 0, sizeof(visit));
    }
    return 0;
}
/*
1
5 1       
9 3 2 3 2 
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
*/
/*
#1 6
#2 3
#3 7
#4 4
#5 2
#6 12
#7 6
#8 7
#9 10
#10 19
*/

/*
3.
1
5 2
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
*/