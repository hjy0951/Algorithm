// 백준 9328 열쇠
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
char map[110][110];
bool visit[110][110];
bool key[30];
int cnt;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

void print(){
    cout << "map\n";
    for(int i = 0 ; i <= n+1 ; i++){
        for(int j = 0 ; j <= m+1 ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "visit\n";
    for(int i = 0 ; i <= n+1 ; i++){
        for(int j = 0 ; j <= m+1 ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

void bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0] = true;
    queue<pair<int,int> > door[30]; // 열지 못한 문을 열어둔 큐

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny <= n+1 && nx >= 0 && nx <= m+1){
                if(!visit[ny][nx]){
                    // 일반 길
                    if(map[ny][nx] == '.'){
                        visit[ny][nx] = true;
                        q.push(make_pair(ny,nx));
                    }
                    // 열쇠에 도착
                    else if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z'){
                        visit[ny][nx] = true;
                        q.push(make_pair(ny,nx));
                        // 열쇠 획득
                        key[map[ny][nx] - 'a'] = true;
                        // 이전에 열지 못한 문 확인
                        if(door[map[ny][nx] - 'a'].size() > 0){
                            while(!door[map[ny][nx] - 'a'].empty()){
                                int ty = door[map[ny][nx] - 'a'].front().first;
                                int tx = door[map[ny][nx] - 'a'].front().second;
                                door[map[ny][nx] - 'a'].pop();

                                visit[ty][tx] = true;
                                q.push(make_pair(ty,tx));
                            }
                        }
                    }
                    // 문에 도착
                    else if(map[ny][nx] >= 'A' && map[ny][nx] <= 'Z'){
                        // 열쇠가 있는 경우
                        if(key[map[ny][nx] - 'A']){
                            visit[ny][nx] = true;
                            q.push(make_pair(ny,nx));
                        }
                        // 없는 경우
                        else{
                            door[map[ny][nx] - 'A'].push(make_pair(ny,nx));
                        }
                    }
                    // 서류 도착
                    else if(map[ny][nx] == '$'){
                        visit[ny][nx] = true;
                        q.push(ny,nx);
                        cnt++;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        cnt = 0;

        cin >> n >> m;
        // 테두리를 만들어 '.'으로 채움
        for(int i = 0 ; i <= m+1 ; i++){
            map[0][i] = '.';
            map[n+1][i] = '.';
        }
        for(int i = 0 ; i <= n+1 ; i++){
            map[i][0] = '.';
            map[i][m+1] = '.';
        }
        // 내부 맵 입력
        for(int i = 1 ; i <= n ; i++){
            string str;
            cin >> str;
            for(int j = 1 ; j <= m ; j++){
                map[i][j] = str[j-1];
            }
        }

        // 현재 가진 키
        string tk;
        cin >> tk;
        if(tk[0] != '0'){
            for(int i = 0 ; i < tk.size() ; i++) key[tk[i] - 'a'] = true;
        }

        bfs();
        cout << cnt << '\n';
        print();
        
        memset(visit,0,sizeof(visit));
        memset(key,0,sizeof(key));
    }

    return 0;
}