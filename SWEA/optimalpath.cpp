// SWEA 1247 최적 경로
/*
    회사와 집의 위치, 그리고 각 고객의 위치는 이차원 정수 좌표 (x, y)로 주어지고 (0 ≤ x ≤ 100, 0 ≤ y ≤ 100)
    두 위치 (x1, y1)와 (x2, y2) 사이의 거리는 |x1-x2| + |y1-y2|으로 계산된다.
    N은 2≤N≤10
    회사의 좌표, 집의 좌표를 포함한 모든 N+2개의 좌표는 서로 다른 위치에 있으며 좌표의 값은 0이상 100 이하의 정수
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int minpath = 987987987;
int comy, comx, hy, hx;
int client[10][2];
int mat[10][10];
int visit[10];

void cal(){
    for(int i = 0 ; i < n ; i++){
        int a = client[i][0];
        int b = client[i][1];

        for(int j = i+1 ; j < n ; j++){
            int c = client[j][0];
            int d = client[j][1];

            mat[i][j] = abs(a - c) + abs(b - d);
            mat[j][i] = mat[i][j];
        }
    }
}

void dfs(int cur, int cnt, int dist){
    if(cnt == n){

        int last = abs(hy - client[cur][0]) + abs(hx - client[cur][1]);
        minpath = min(minpath, dist + last);
        return;
    }
    else{
        visit[cur] = 1;
        for(int i = 0 ; i < n ; i++){
            if(visit[i] == 1) continue;
            
            dfs(i, cnt+1, dist+mat[cur][i]);
        }
        visit[cur] = 0;
    }
}

int main(){
    int t;
    cin >> t;
    for(int k = 1 ; k <= t ; k++){
        minpath = 987987987;

        cin >> n;
        //회사의 좌표,집의 좌표, N명의 고객의 좌표
        cin >> comy >> comx;
        cin >> hy >> hx;
        for(int i = 0 ; i < n ; i++){
            cin >> client[i][0] >> client[i][1];
        }

        cal();

        for(int i  = 0 ; i < n ; i++){
            visit[i] = 1;
            dfs(i, 1, abs(comy - client[i][0]) + abs(comx - client[i][1]));
            visit[i] = 0;
        }

        cout << "#" << k << " " << minpath << "\n";
    }

    return 0;
}