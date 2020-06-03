// 백준 3678 카탄의 개척자
/*
    게임을 시작하려면, 먼저 게임판을 랜덤으로 만들어야 한다. 
    게임판은 육각형 타일로 이루어져 있으며, 각 타일은 자원을 하나씩 포함하고 있다. 
    자원은 총 다섯 가지 종류가 있으며, 점토, 재목, 양모, 곡물, 광석이다. 각 자원은 1부터 5까지 순서로 나타낼 수 있다.
    랜덤을 이용해서 게임판을 만들면, 같은 자원이 인접한 타일에 있는 경우가 있을 수도 있다. 
    이런 배치를 매우 싫어하는 사람이 많다. 따라서, 다음과 같은 과정으로 게임판을 만들려고 한다. 
    먼저, 게임판의 중앙에서 만들기를 시작하고, 나선 형태로 진행한다.

        1. 새로운 타일은 이미 채워진 인접한 타일에 들어있는 자원과 다른 자원이어야 한다.
        2. 가능한 자원이 여러 가지인 경우에는, 보드에 가장 적게 나타난 자원을 선택한다.
        3. 그러한 경우도 여러 가지라면, 번호가 작은 것을 선택한다.
    
    아래 그림은 어떻게 나선 형태로 진행하는지와, 어떤 자원을 선택하는지를 나타낸 그림이다. 
    n번째로 채우는 타일에 어떤 자원을 선택하는지 고르는 프로그램을 작성하시오. (n은 1부터 시작한다)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n;
int map[600][400]; // 가로는 공백이 있 기때문에 대충 60~70 * 4 | 세로는 가로의 2배 정도
int num[10001];
int res[6];
int dy[] = {-2,-1,1,2,1,-1}; // 12 10 8 6 4 2시 방향
int dx[] = {0,-1,-1,0,1,1};
/*
    12
  10  2
    x
  8   4
    6
*/

void print(){
    cout << '\n';
    for(int i = 286 ; i < 315 ; i++){
        for(int j = 186 ; j < 215 ; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int choice(int y, int x){
    bool check[6] ={0,};

    for(int i = 0 ; i < 6 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(map[ny][nx] != 0){
            check[map[ny][nx]] = true;
        }
    }

    int maxn = 10000;
    int idx = -1;
    for(int i = 1 ; i <= 5 ; i++){
        if(!check[i]){
            if(maxn > res[i]){
                maxn = res[i];
                idx = i;
            }
        }
    }
    return idx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sy = 299;
    int sx = 199;

    int cnt = 1;
    map[sy][sx] = 1;
    res[1]++;
    num[cnt++] = 1;
    for(int i = 1 ; i < 70 ; i++){
        // 2시방향 우선 이동
        sy += dy[5];
        sx += dx[5];
        map[sy][sx] = choice(sy,sx);
        res[map[sy][sx]]++;
        num[cnt++] = map[sy][sx];
        if(cnt == 10001) break;

        for(int j = 0 ; j < 6 ; j++){
            for(int k = 0 ; k < i ; k++){
                if(j == 0 && k == i-1) break;
                sy += dy[j];
                sx += dx[j];
                map[sy][sx] = choice(sy,sx);
                res[map[sy][sx]]++;
                num[cnt++] = map[sy][sx];
                if(cnt == 10001) break;
            }
            if(cnt == 10001) break;
        }
        if(cnt == 10001) break;
    }

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1) cout << "1\n";
        else cout << num[n] << '\n';
    }

    return 0;
}