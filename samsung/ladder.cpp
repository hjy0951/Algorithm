// 백준 15684 사다리 조작
/*
    N개의 세로선과 M개의 가로선
    인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H (모든 세로선이 같은 위치)
    단, 두 가로선이 연속하거나 서로 접하면 안 된다
    사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다
    i번 세로선의 결과가 i번이 나와야 한다
    그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램
*/
#include <iostream>
#include <cstring>

using namespace std;

// 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H
int n,m, h;
int ladder[31][11];
int ans;
int line;
int flag;

void print(){
    cout << "\n";
    for(int i = 0 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << ladder[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool start(){
    for(int i = 1 ; i <= n ; i++){
        int cy = 0;
        int cx = i;

        while(cy < h){
            cy++;
            if(ladder[cy][cx] != 0) cx = ladder[cy][cx];
        }
        if(cx != i) return false;
    }
    return true;
}

void bf(int cnt, int y, int x){
    if(cnt >= ans) return; // 지금 내가 찾은 결과보다 같거나 나쁜 경우 가지치기

    if(start()){ // 모든 i번째 세로선의 결과가 i인 경우
        ans = cnt;
        return;
    }

    if(cnt == 3) return; // 3개 보다 많은 사다리의 경우 가지치기

    for(int i = y ; i <= h ; i++){
        for(int j = x+1 ; j < n ; j++){
            if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
                ladder[i][j] = j+1;
                ladder[i][j+1] = j;

                bf(cnt+1, i, j);

                ladder[i][j] = 0;
                ladder[i][j+1] = 0;
            }
        }
        x = 0; 
    }
    
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    cin >> n >> m >> h;
    for(int i = 0 ; i < m ; i++){
        // b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
        int a, b;
        cin >> a >> b;
        ladder[a][b] = b+1;
        ladder[a][b+1] = b;
    }

    ans = 4;

    if(start() == true){
        cout << "0\n";
        return 0;
    }

    line = 0;
    flag = 0;

    bf(0,1,0);
    
    if(ans == 4) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}

/*
    16:02 ~ 16:46
    문제를 잘못 이해함.
    17:00 ~ 18:20
    문제를 잘 읽자. 추가 사다리가 3개까지인지 절대 몰랐음.
*/