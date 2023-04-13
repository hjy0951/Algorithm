// SWEA 1907 모래성 쌓기
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int h,w; // 1 ≤ H, W ≤ 1,000
int map[1000][1000];
int cntmap[1000][1000];
char check[1000][1000];
int dy[] = {1,-1,0,0,1,1,-1,-1};
int dx[] = {0,0,1,-1,1,-1,1,-1};
queue<pair<int,int> > q;

void print(char arr[][1000]){
    cout << "\n";
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cout << arr[i][j]+0 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin >> h >> w;
    for(int i = 0 ; i < h ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < w ; j++){
            if(str[j] == '.') map[i][j] = 0;
            else map[i][j] = str[j] - '0';
        }
    }

    for(int i = 1 ; i < h-1 ; i++){
        for(int j = 1 ; j < w-1 ; j++){
            cntmap[i][j] = 0;

            if(map[i][j] != 0){
                for(int k = 0 ; k < 8 ; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(map[ny][nx] == 0) cntmap[i][j]++;
                }
                if(cntmap[i][j] >= map[i][j]){
                    q.push(make_pair(i,j));
                    check[i][j] = 1;
                }
            }
        }
    }

    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int l = q.size();
        // cout << "len : " << l << "\n";
        // print(check);
        // int x = 0;
        for(int i  = 0 ; i < l ; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int j = 0 ; j < 8 ; j++){
                int ny = y + dy[j];
                int nx = x + dx[j];

                if(check[ny][nx] == 1 || map[ny][nx] == 0) continue;

                cntmap[ny][nx]++;
                if(map[ny][nx] != 0 && map[ny][nx] <= cntmap[ny][nx]){
                    q.push(make_pair(ny,nx));
                    check[ny][nx] = 1;
                    // x++;
                }
            }
        }
    }

    cout << cnt << "\n";
    memset(check,0,sizeof(check));
    
    return 0;
}