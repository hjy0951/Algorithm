// 백준 1890 점프
#include <iostream>

#define ll long long
using namespace std;

int n;
int map[101][101];
long long dp[101][101];

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int cur = map[i][j];
            if(cur == 0) continue;
            
            if(i + cur < n){
                dp[i + cur][j] += dp[i][j];
            }
            
            if(j + cur < n){
                dp[i][j + cur] = dp[i][j];
            }
        }
    }

    cout << dp[n-1][n-1] << '\n';
    return 0;
}