// 백준 1799 비숍
/*
    체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때
    서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int map[10][10]; // 0 : 놓을 수 없는 칸 | 1 : 놓을 수 있는 칸 | 2 : 비숍이 있는 칸
int visit[10][10];
vector<int> yv;
vector<int> xv;
vector<int> yv2;
vector<int> xv2;
int dy[] = {1,1,-1,-1};
int dx[] = {1,-1,1,-1};
int maxcnt, maxcnt2;

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool check(int y, int x){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 1 ; j < n ; j++){
            int ny = y + dy[i]*j;
            int nx = x + dx[i]*j;

            if(ny < 0 || ny >= n || nx < 0 || nx >= n){
                break;
            }
            else{
                if(map[ny][nx] == 2) return false;
            }
        }
    }
    return true;
}


void bt1(int cur, int cnt){
    if(cur >= yv.size()){
        maxcnt = max(maxcnt, cnt);
        return;
    }
    else{
        int cy = yv[cur];
        int cx = xv[cur];

        if(check(cy,cx) == true){
            bt1(cur+1,cnt);
            map[cy][cx] = 2;
            bt1(cur+1,cnt+1);
            map[cy][cx] = 1;
        }
        else{
            bt1(cur+1,cnt);
        }
    }
}
void bt2(int cur, int cnt){
    if(cur >= yv2.size()){
        maxcnt2 = max(maxcnt2, cnt);
        return;
    }
    else{
        int cy = yv2[cur];
        int cx = xv2[cur];

        if(check(cy,cx) == true ){
            bt2(cur+1,cnt);
            map[cy][cx] = 2;
            bt2(cur+1,cnt+1);
            map[cy][cx] = 1;
        }
        else{
            bt2(cur+1,cnt);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)){
                    yv.push_back(i);
                    xv.push_back(j);
                }
                else{
                    yv2.push_back(i);
                    xv2.push_back(j);
                }
            }
        }
    }

    bt1(0,0);
    bt2(0,0);

    cout << maxcnt + maxcnt2 << "\n";
    return 0;
}
/*
5
1 1 0 1 1
0 1 0 0 0
1 0 1 0 1
1 0 0 0 0
1 0 1 1 1
*/