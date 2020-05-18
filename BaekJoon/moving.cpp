// 백준 11048 이동하기
/*
    N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다. 
    미로의 가장 왼쪽 윗 방은 (1, 1)이고, 가장 오른쪽 아랫 방은 (N, M)
    (r, c)에 있으면, (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다. 
    또, 미로 밖으로 나갈 수는 없다
    준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.
*/
#include <iostream>

using namespace std;

int n,m;
int map[1001][1001];
int dp[1001][1001];
int dy[] = {0,1,1};
int dx[] = {1,0,1};

void print(){
    cout << '\n';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> map[i][j];
        }
    }

    dp[1][1] = map[1][1];
    for(int i = 2 ; i <= m ; i++){
        dp[1][i] += map[1][i] + dp[1][i-1];
    }
    for(int i = 2 ; i <= n ; i++){
        dp[i][1] += map[i][1] + dp[i-1][1];
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 2 ; j <= m ; j++){
            int one = dp[i-1][j];
            int two = dp[i][j-1];
            int thr = dp[i-1][j-1];

            int maxn = max(one,two);
            maxn = max(maxn, thr);

            dp[i][j] = maxn + map[i][j];
        }
    }

    print();

    cout << dp[n][m]  << "\n";
    
    return 0;
}