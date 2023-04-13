// 백준 1600 말이 되고픈 원숭이
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int w,h,k;
int map[201][201];
int visit[201][201][31];
int mindist;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int hy[] = {2, 2,1,-1,-2,-2, 1,-1};
int hx[] = {1,-1,2, 2, 1,-1,-2,-2};

void bfs(){
    queue<pair<int,int> > q;
    queue<int> hq;
    q.push(make_pair(0,0));
    hq.push(0);
    visit[0][0][0] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int ck = hq.front();
        hq.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < h && nx >= 0 && nx < w){
                if(visit[ny][nx][ck] == 0 && map[ny][nx] == 0){
                    visit[ny][nx][ck] = visit[cy][cx][ck] + 1;
                    if(ny == h-1 && nx == w-1){
                        mindist = min(mindist, visit[ny][nx][ck]);
                        return;
                    }
                    q.push(make_pair(ny,nx));
                    hq.push(ck);
                }
            }
        }

        if(ck < k){
            for(int i = 0 ; i < 8 ; i++){
                int ny = cy + hy[i];
                int nx = cx + hx[i];

                if(ny >= 0 && ny < h && nx >= 0 && nx < w){
                    if(visit[ny][nx][ck+1] == 0 && map[ny][nx] == 0){
                        visit[ny][nx][ck+1] = visit[cy][cx][ck] + 1;

                        if(ny == h-1 && nx == w-1){
                            mindist = min(mindist, visit[ny][nx][ck+1]);
                            return;
                        }

                        q.push(make_pair(ny,nx));
                        hq.push(ck+1);
                    }
                }
            }
        }
    }
}

int main(){
    mindist = 987987987;
    cin >> k;
    cin >> w >> h;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cin >> map[i][j];
        }
    }

    if(w == 1 && h == 1){
        cout << "0\n";
        return 0;
    }

    bfs();

    if(mindist == 987987987) cout << "-1\n";
    else cout << mindist - 1 << '\n';

    return 0;
}