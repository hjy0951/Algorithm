// 백준 2583 영역 구하기
/*
    M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때,
    K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지,
    그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
int map[100][100];
int visit[100][100];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
vector<int> v;

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int x){
    queue<pair<int,int> > q;
    int cnt = 0;
    q.push(make_pair(y,x));
    visit[y][x] = 1;
    cnt++;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    q.push(make_pair(ny,nx));
                    cnt++;
                }
            }
        }
    }
    v.push_back(cnt);
    return;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0 ; i < k ; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = y1 ; j < y2 ; j++){
            for(int k = x1 ; k < x2 ; k++){
                map[j][k] = 1;
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visit[i][j] == 0 && map[i][j] == 0){
                bfs(i,j);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}