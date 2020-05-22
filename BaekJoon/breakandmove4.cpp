// 백준 16946 벽 부수고 이동하기 4
/*
    맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
    한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 
    두 칸이 변을 공유할 때, 인접하다고 한다.

    각각의 벽에 대해서 다음을 구해보려고 한다.

    벽을 부수고 이동할 수 있는 곳으로 변경한다.
    그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
int map[1001][1001];
int visit[1001][1001];
int cnt;
int num[1000001];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(int arr[][1001]){
    cout << '\n';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = cnt;
    num[cnt]++;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
                if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                    num[cnt]++;
                    visit[ny][nx] = cnt;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++) map[i][j+1] = str[j] - '0';
    }

    if(n == 1 && m == 1){
        if(map[1][1] == 0){
            cout << "0\n";
        }
        else cout << "1\n";

        return 0;
    }

    // print(map);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(map[i][j] == 0 && visit[i][j] == 0){
                cnt++;
                bfs(i,j);
            }
        }
    }

    string ret[1001];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(map[i][j] == 1){
                long long temp = 1;
                vector<int> check;

                for(int k = 0 ; k < 4 ; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
                        if(map[ny][nx] == 0 && visit[ny][nx] > 0){
                            check.push_back(visit[ny][nx]);
                        }
                    }
                }

                if(check.size() == 0){
                    ret[i].push_back('1');
                }
                else if(check.size() == 1){
                    temp += num[check[0]];
                    ret[i].push_back(temp%10 + '0');
                }
                else{
                    sort(check.begin(), check.end());
                    int prev = check[0];

                    for(int i = 1 ; i < check.size() ; i++){
                        int cur = check[i];
                        if(cur != prev) temp += num[cur];
                        prev = cur;
                    }
                    temp += num[check[0]];

                    ret[i].push_back(temp%10 + '0');
                }
            }
            else ret[i].push_back('0');
        }
    }

    // cout << '\n';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << ret[i][j];
        }
        cout << '\n';
    }

    return 0;
}