#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int N,W,H;
int map[20][20];
int minbrick;
int dy[] = {1, 0, 0,-1};
int dx[] = {0, 1,-1, 0};

void copy_arr(int des[][20], int src[][20]){
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            des[i][j] = src[i][j];
        }
    }
}

void after_break(int arr[][20]){
    for(int i = 0 ; i < W ; i++){
        for(int j = H-1 ; j >= 0 ; j--){
            if(arr[j][i] == 0){
                for(int k = j-1 ; k >= 0 ; k--){
                    if(arr[k][i] != 0){
                        int temp = arr[k][i];
                        arr[k][i] = arr[j][i];
                        arr[j][i] = temp;

                        break;
                    }
                }
            }
        }
    }
}

void brick(int arr[][20],int h, int w){
    queue<int> nq;
    queue<pair<int,int> > q;
    q.push(make_pair(h,w));
    nq.push(arr[h][w]);

    int visit[20][20];
    memset(visit,0,sizeof(visit));
    visit[h][w] = 1;

    if(nq.front() == 1){
        arr[h][w] = 0;
        return;
    }

    while(!q.empty() && !nq.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        int cn = nq.front();
        nq.pop();

        if(cn == 1){
            visit[cy][cx] = 1;
        }
        else{
            for(int i = 0 ; i < 4 ; i++){
                int ny = cy;
                int nx = cx;
                visit[ny][nx] = 1;
                
                for(int j = 1 ; j < cn ; j++){
                    ny += dy[i];
                    nx += dx[i];
                    if(nx >= 0 && nx < W && ny >= 0 && ny < H && arr[ny][nx] > 0 && visit[ny][nx] == 0){
                        q.push(make_pair(ny,nx));
                        nq.push(arr[ny][nx]);
                        visit[ny][nx] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if(visit[i][j] == 1){
                arr[i][j] = 0;
            }
        }
    }

    // cout << endl;
    // for(int j = 0 ; j < H ; j++){
    //     for(int k = 0 ; k < W ; k++){
    //         cout <<  arr[j][k] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
}

void breaker(int ballcount, int pos, int arr[][20]){
    if(ballcount >= N){
        int cnt = 0;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                if(arr[i][j] != 0) cnt++;
            }
        }

        // cout << endl;
        // for(int j = 0 ; j < H ; j++){
        //     for(int k = 0 ; k < W ; k++){
        //         cout <<  arr[j][k] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if(cnt < minbrick) minbrick = cnt;
        return;
    }
    else{
        int next[20][20];
        memset(next,0,sizeof(next));

        copy_arr(next, arr);
        for(int i = 0 ; i < H ; i++){
            if(arr[i][pos] == 0) continue;
            else if(arr[i][pos] != 0){
                brick(next, i, pos);
                after_break(next);
                break;
            }
        }

        if(minbrick == 0) return;

        for(int i = 0 ; i < W ; i++){
            breaker(ballcount+1, i, next);
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        minbrick = 987987987;
        int testmap[20][20];
        memset(map,0,sizeof(map));
        memset(testmap,0,sizeof(testmap));

        cin >> N >> W >> H;
        for(int j = 0 ; j < H ; j++){
            for(int k = 0 ; k < W ; k++){
                cin >> map[j][k];
                testmap[j][k] = map[j][k];
            }
        }

        for(int j = 0 ; j < W ; j++){
            breaker(0, j, testmap);
            for(int i = 0 ; i < H; i++){
                for(int j = 0 ; j < W ; j++){
                    testmap[i][j] = map[i][j];
                }
            }
        }

        cout << "#" << i << " " << minbrick << endl;
    }
    return 0;
}
/*
#1 12
#2 27
#3 4
#4 8
#5 0
*/

/*
1
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
*/
/*
1
3 6 7
1 1 0 0 0 0
1 1 0 0 1 0
1 1 0 0 4 0
4 1 0 0 1 0
1 5 1 0 1 6
1 2 8 1 1 6
1 1 1 9 2 1

0 0 0 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
1 0 0 0 1 0
1 0 0 0 4 0
4 0 0 0 1 0
1 0 0 9 2 0
*/
/*
        cout << endl;
        for(int j = 0 ; j < H ; j++){
            for(int k = 0 ; k < W ; k++){
                cout <<  map[j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
*/