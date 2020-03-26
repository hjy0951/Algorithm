//운영 비용 = K * K + (K - 1) * (K - 1)
/*
 - K = 1 일 때, 운영 비용은 1 이다.

 - K = 2 일 때, 운영 비용은 5 이다.

 - K = 3 일 때, 운영 비용은 13 이다.

 - K = 4 일 때, 운영 비용은 25 이다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int N,M;
int visit[30][30];
int map[30][30];
int numhome;
int totalmoney;
int maxhome;
int dy[] = {1,-1,0,0}; // 상하좌우
int dx[] = {0,0,-1,1};

queue<pair<int,int> > q;

void diamond(int y, int x, int n, int limit){
    int check[30][30];
    memset(check,0,sizeof(check));
    int homecnt = 0;

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 4 ; j++){
            int ny = y + dy[j]*i;
            int nx = x + dx[j]*i;

            if(ny >= 0 && nx >= 0 && ny < N && nx < N){
                if(check[ny][nx] == 0){
                    check[ny][nx] = 1;
                    if(map[ny][nx] == 1) homecnt++;

                    if(j == 0 || j == 1){
                        for(int k = n-i-1 ; k > 0 ; k--){
                            int nx1 = nx-k;
                            int nx2 = nx+k;
                            if(nx1 >= 0 && nx1 < N){
                                if(check[ny][nx1] == 0){
                                    if(map[ny][nx1] == 1) homecnt++;
                                    check[ny][nx1] = 1;
                                }
                            }
                            if(nx2 >= 0 && nx2 < N){
                                if(check[ny][nx2] == 0){
                                    if(map[ny][nx2] == 1) homecnt++;
                                    check[ny][nx2] = 1;
                                }
                            }
                        }
                    }
                    else if(j == 2 || j == 3){
                        for(int k = n-i-1 ; k > 0 ; k--){
                            int ny1 = ny-k;
                            int ny2 = ny+k;
                            if(ny1 >= 0 && ny1 < N){
                                if(check[ny1][nx] == 0){
                                    if(map[ny1][nx] == 1) homecnt++;
                                    check[ny1][nx] = 1;
                                }
                            }
                            if(ny2 >= 0 && ny2 < N){
                                if(check[ny2][nx] == 0){
                                    if(map[ny2][nx] == 1) homecnt++;
                                    check[ny2][nx] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //
    // cout << endl;
    // cout << "homecnt : " << homecnt << endl;
    // for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < N ; j++){
    //         cout << check[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    //

    if(homecnt*M - limit >= 0){
        if(homecnt > maxhome){
            maxhome = homecnt;
        }
    }
}

void aroundview(int y, int x, int n, int limit){
    diamond(y,x, n, limit);
    visit[y][x] = 1;

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 4 ; j++){
            int ny = y + dy[j]*i;
            int nx = x + dx[j]*i;

            if(ny >= 0 && nx >= 0 && ny < N && nx < N){
                if(visit[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    diamond(ny,nx, n, limit);

                    if(j == 0 || j == 1){
                        for(int k = n-i-1 ; k > 0 ; k--){
                            int nx1 = nx-k;
                            int nx2 = nx+k;
                            if(nx1 >= 0 && nx1 < N){
                                if(visit[ny][nx1] == 0){
                                    diamond(ny,nx1, n, limit);
                                    visit[ny][nx1] = 1;
                                }
                            }
                            if(nx2 >= 0 && nx2 < N){
                                if(visit[ny][nx2] == 0){
                                    diamond(ny,nx2, n, limit);
                                    visit[ny][nx2] = 1;
                                }
                            }
                        }
                    }
                    else if(j == 2 || j == 3){
                        for(int k = n-i-1 ; k > 0 ; k--){
                            int ny1 = ny-k;
                            int ny2 = ny+k;
                            if(ny1 >= 0 && ny1 < N){
                                if(visit[ny1][nx] == 0){
                                    diamond(ny1,nx, n, limit);
                                    visit[ny1][nx] = 1;
                                }
                            }
                            if(ny2 >= 0 && ny2 < N){
                                if(visit[ny2][nx] == 0){
                                    diamond(ny2,nx, n, limit);
                                    visit[ny2][nx] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void cal(int size, int limit){
    int cnt = 0;
    while(cnt < q.size()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if(visit[cy][cx] == 1) continue;
        aroundview(cy,cx, size, limit);
        q.push(make_pair(cy,cx));
        cnt++;
    }

    while(!q.empty()){
        q.pop();
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(visit,0,sizeof(visit));
        memset(map,0,sizeof(map));
        numhome = 0;
        maxhome = 0;
        totalmoney = 0;

        cin >> N >> M;

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
                if(map[j][k] == 1){
                    numhome++;
                    q.push(make_pair(j,k));
                }
            }
        }

        totalmoney = numhome * M;
        int K = 0;
        int cost = 0;

        while(totalmoney - cost >= 0){
            K++;
            cost = K * K + (K - 1) * (K - 1);
            if(totalmoney - cost < 0) break;
            // cout << "K & cost : " << K << " " << cost << endl;
            cal(K,cost);
            memset(visit,0,sizeof(visit));

        }

        cout << "#" << i << " " << maxhome << endl;

        while(!q.empty()){
            q.pop();
        }
    }

    return 0;
}

/*
#1 5
#2 4
#3 24
#4 48
#5 3
#6 65
#7 22
#8 22
#9 78
#10 400
*/
/*
1
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0
*/