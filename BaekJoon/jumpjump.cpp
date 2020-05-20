// 백준 11060 점프 점프
/*
    1×N 크기의 미로에 갇혀있다. 
    미로는 1×1 크기의 칸으로 이루어져 있고, 각 칸에는 정수가 하나 쓰여 있다. 
    i번째 칸에 쓰여 있는 수를 Ai라고 했을 때, 재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 한 번에 점프할 수 있다. 
    예를 들어, 3번째 칸에 쓰여 있는 수가 3이면, 재환이는 4, 5, 6번 칸 중 하나로 점프할 수 있다.
    지금 미로의 가장 왼쪽 끝에 있고, 가장 오른쪽 끝으로 가려고 한다. 이때, 최소 몇 번 점프를 해야 갈 수 있는지 구하는 프로그램을 작성하시오. 
    만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int maze[1001];
int dp[1001];

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++) cout << dp[i] << ' ';
    cout << '\n';
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> maze[i];

    if(maze[0] == 0 && n > 1){
        cout << "-1\n";
        return 0;
    }
    else if(n == 1){
        cout << "0\n";
        return 0;
    }

    int ox = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= maze[i] ; j++){
            if(i+j == n-1) ox = 1;

            if(i+j >= n) continue;

            if(dp[i+j] == 0) dp[i+j] = dp[i]+1;
            else{
                dp[i+j] = min(dp[i]+1, dp[i+j]);
            }
        }
        // print();
    }
    
    for(int i = 1 ; i < n ;i++){
        if(dp[i] == 0){
            ox = 0;
            break;
        }
    }

    if(ox == 1){
        if(dp[n-1] == 0 && n > 1) cout << "-1\n";
        else cout << dp[n-1] << '\n';
    }
    else cout << "-1\n";
    return 0;
}