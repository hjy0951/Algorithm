// 백준 9944 NxM 보드 완주하기
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n,m;
int map[31][31];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int mincnt;
int total;
vector<pair<int,int> > v;

void print(int arr[][31]){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void copy(int arr1[][31], int arr2[][31]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            arr2[i][j] = arr1[i][j];
        }
    }
}

int check(int arr[][31]){
    int ret = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 0 && arr[i][j] != 0) ret++;
        }
    }
    return ret;
}

bool canmove(int y, int x, int arr[][31]){
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(map[ny][nx] == 0 && arr[ny][nx] == 0) return true;
        }
    }
    return false;
}

void dfs(int y, int x, int visit[][31], int cnt){
    if(cnt > 1000000) return;
    if(canmove(y,x, visit) == false){
        if(check(visit) == v.size()) mincnt = min(mincnt, cnt);
        return;
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(map[ny][nx] == 0 && visit[ny][nx] == 0){
                    int temp[31][31] = {0,};
                    copy(visit,temp);
                    
                    while(1){
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
                        if(map[ny][nx] == 1) break;
                        if(temp[ny][nx] != 0) break;

                        temp[ny][nx] = 1;
                        ny += dy[i];
                        nx += dx[i];
                    }

                    ny -= dy[i];
                    nx -= dx[i];

                    dfs(ny,nx,temp,cnt+1);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0;

    while(cin >> n >> m){
        ++t;
        mincnt = 987987987;
        v.clear();

        for(int i = 0 ; i < n ; i++){
            string str;
            cin >> str;

            for(int j = 0 ; j < m ; j++){
                if(str[j] == '.'){
                    map[i][j] = 0;
                    v.push_back(make_pair(i,j));
                }
                else if(str[j] == '*') map[i][j] = 1;
            }
        }

        for(int i = 0 ; i < v.size() ; i++){
            int ny = v[i].first;
            int nx = v[i].second;

            int visit[31][31] = {0,};
            visit[ny][nx] = 1;
            dfs(ny,nx,visit,0);
        }
        
        cout << "Case " << t << ": ";
        if(mincnt != 987987987) cout << mincnt << "\n";
        else cout << "-1\n";
    }
    
    return 0;
}