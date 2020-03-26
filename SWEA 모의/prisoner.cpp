#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int N,M,R,C,L;
int map[60][60];
int visit[60][60];

void find(int sy, int sx){
    queue<pair<int,int> > q;
    q.push(make_pair(sy, sx));
    visit[sy][sx] = 1;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        switch(map[cy][cx]){
            case 1:
                if(visit[cy+1][cx] == 0 && cy+1 >= 0 && cy+1 < N && cx >= 0 && cx < M){
                    if(map[cy+1][cx] == 1 || map[cy+1][cx] == 2 || map[cy+1][cx] == 4 || map[cy+1][cx] == 7){
                        visit[cy+1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy+1, cx));
                    }
                }
                if(visit[cy-1][cx] == 0 && cy-1 >= 0 && cy-1 < N && cx >= 0 && cx < M){
                    if(map[cy-1][cx] == 1 || map[cy-1][cx] == 2 || map[cy-1][cx] == 5 || map[cy-1][cx] == 6){
                        visit[cy-1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy-1, cx));
                    }
                }
                if(visit[cy][cx+1] == 0 && cy >= 0 && cy < N && cx+1 >= 0 && cx+1 < M){
                    if(map[cy][cx+1] == 1 || map[cy][cx+1] == 3 || map[cy][cx+1] == 6 || map[cy][cx+1] == 7){
                        visit[cy][cx+1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx+1));
                    }
                }
                if(visit[cy][cx-1] == 0 && cy >= 0 && cy < N && cx-1 >= 0 && cx-1 < M){
                    if(map[cy][cx-1] == 1 || map[cy][cx-1] == 3 ||map[cy][cx-1] == 4 ||map[cy][cx-1] == 5){
                        visit[cy][cx-1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx-1));
                    }
                }
                break;
            case 2:
                if(visit[cy+1][cx] == 0 && cy+1 >= 0 && cy+1 < N && cx >= 0 && cx < M){
                    if(map[cy+1][cx] == 1 || map[cy+1][cx] == 2 || map[cy+1][cx] == 4 || map[cy+1][cx] == 7){
                        visit[cy+1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy+1, cx));
                    }
                }
                if(visit[cy-1][cx] == 0 && cy-1 >= 0 && cy-1 < N && cx >= 0 && cx < M){
                    if(map[cy-1][cx] == 1 || map[cy-1][cx] == 2 || map[cy-1][cx] == 5 || map[cy-1][cx] == 6){
                        visit[cy-1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy-1, cx));
                    }
                }
                break;
            case 3:
                if(visit[cy][cx+1] == 0 && cy >= 0 && cy < N && cx+1 >= 0 && cx+1 < M){
                    if(map[cy][cx+1] == 1 || map[cy][cx+1] == 3 || map[cy][cx+1] == 6 || map[cy][cx+1] == 7){
                        visit[cy][cx+1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx+1));
                    }
                }
                if(visit[cy][cx-1] == 0 && cy >= 0 && cy < N && cx-1 >= 0 && cx-1 < M){
                    if(map[cy][cx-1] == 1 || map[cy][cx-1] == 3 ||map[cy][cx-1] == 4 ||map[cy][cx-1] == 5){
                        visit[cy][cx-1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx-1));
                    }
                }
                break;
            case 4:
                if(visit[cy][cx+1] == 0 && cy >= 0 && cy < N && cx+1 >= 0 && cx+1 < M){
                    if(map[cy][cx+1] == 1 || map[cy][cx+1] == 3 || map[cy][cx+1] == 6 || map[cy][cx+1] == 7){
                        visit[cy][cx+1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx+1));
                    }
                }
                if(visit[cy-1][cx] == 0 && cy-1 >= 0 && cy-1 < N && cx >= 0 && cx < M){
                    if(map[cy-1][cx] == 1 || map[cy-1][cx] == 2 || map[cy-1][cx] == 5 || map[cy-1][cx] == 6){
                        visit[cy-1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy-1, cx));
                    }
                }
                break;
            case 5:
                if(visit[cy][cx+1] == 0 && cy >= 0 && cy < N && cx+1 >= 0 && cx+1 < M){
                    if(map[cy][cx+1] == 1 || map[cy][cx+1] == 3 || map[cy][cx+1] == 6 || map[cy][cx+1] == 7){
                        visit[cy][cx+1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx+1));
                    }
                }
                if(visit[cy+1][cx] == 0 && cy+1 >= 0 && cy+1 < N && cx >= 0 && cx < M){
                    if(map[cy+1][cx] == 1 || map[cy+1][cx] == 2 || map[cy+1][cx] == 4 || map[cy+1][cx] == 7){
                        visit[cy+1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy+1, cx));
                    }
                }
                break;
            case 6:
                if(visit[cy+1][cx] == 0 && cy+1 >= 0 && cy+1 < N && cx >= 0 && cx < M){
                    if(map[cy+1][cx] == 1 || map[cy+1][cx] == 2 || map[cy+1][cx] == 4 || map[cy+1][cx] == 7){
                        visit[cy+1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy+1, cx));
                    }
                }
                if(visit[cy][cx-1] == 0 && cy >= 0 && cy < N && cx-1 >= 0 && cx-1 < M){
                    if(map[cy][cx-1] == 1 || map[cy][cx-1] == 3 ||map[cy][cx-1] == 4 ||map[cy][cx-1] == 5){
                        visit[cy][cx-1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx-1));
                    }
                }
                break;
            case 7:
                if(visit[cy][cx-1] == 0 && cy >= 0 && cy < N && cx-1 >= 0 && cx-1 < M){
                    if(map[cy][cx-1] == 1 || map[cy][cx-1] == 3 ||map[cy][cx-1] == 4 ||map[cy][cx-1] == 5){
                        visit[cy][cx-1] = visit[cy][cx] + 1;
                        q.push(make_pair(cy, cx-1));
                    }
                }
                if(visit[cy-1][cx] == 0 && cy-1 >= 0 && cy-1 < N && cx >= 0 && cx < M){
                    if(map[cy-1][cx] == 1 || map[cy-1][cx] == 2 || map[cy-1][cx] == 5 || map[cy-1][cx] == 6){
                        visit[cy-1][cx] = visit[cy][cx] + 1;
                        q.push(make_pair(cy-1, cx));
                    }
                }
                break;    
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(map, 0, sizeof(map));
        memset(visit,0,sizeof(visit));
        cin >> N >> M >> R >> C >> L;

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                cin >> map[j][k];
            }
        }

        find(R,C);

        int num = 0;
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                if(visit[j][k] <= L && visit[j][k] > 0) num++;
            }
        }
        // cout << endl;
        // cout << endl;
        // for(int j = 0 ; j < N ; j++){
        //     for(int k = 0 ; k < M ; k++){
        //         cout << visit[j][k] << " "; 
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        cout << "#" << i << " " << num << endl;
    }

    return 0;
}

/*
1
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0

1
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
*/

/*
#1 5
#2 15
#3 29
#4 67
#5 71
*/