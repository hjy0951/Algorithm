// 백준 1941 소문난 칠공주
/*
    1. 이름이 이름인 만큼, 7명의 여학생들로 구성되어야 한다.
    2. 강한 결속력을 위해, 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
    3. 화합과 번영을 위해, 반드시 ‘이다솜파’의 학생들로만 구성될 필요는 없다.
    4. 그러나 생존을 위해, ‘이다솜파’가 반드시 우위를 점해야 한다. 
    따라서 7명의 학생 중 ‘이다솜파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

char map[5][5];
int visit[5][5];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int n;
int ans;

void print(){
    cout << '\n';
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool bfs(){
    queue<pair<int,int> > q;
    int sy = -1;
    int sx = -1;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(visit[i][j] != 0){
                sy = i;
                sx = j;
                break;
            }
        }
        if(sy >= 0) break;
    }

    if(sy < 0) return false;

    q.push(make_pair(sy,sx));
    int cnt = 1;
    bool check[5][5] = {0,};
    check[sy][sx] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5){
                if(check[ny][nx] == false && visit[ny][nx] == 1){
                    check[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                    cnt++;
                }
            }
        }
    }

    if(cnt == 7) return true;
    else return false;
}

void bt(int cnt, int sn, int y, int x){
    if(cnt >= 6){
        if(sn >= 4){
            if(bfs() == true) ans++;
        }
        return;
    }
    else{
        for(int i = y ; i < 5 ; i++){
            for(int j = x+1 ; j < 5 ; j++){
                if(visit[i][j] == 0){
                    visit[i][j] = 1;

                    if(map[i][j] == 'S') bt(cnt+1, sn+1, i, j);
                    else bt(cnt+1, sn, i, j);

                    visit[i][j] = 0;
                }
            }
            x = -1;
        }
    }
}

int main(){
    for(int i = 0 ; i < 5 ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < 5 ; j++){
            map[i][j] = str[j];
        }
    }

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            visit[i][j] = 1;
            if(map[i][j] == 'S') bt(0, 1, i, j);
            else bt(0, 0, i, j);
            visit[i][j] = 0;
        }
    }

    cout << ans << '\n';
    return 0;
}

/*
SSSSS
SSSSS
SSSSS
SSSSS
SSSSS
*/