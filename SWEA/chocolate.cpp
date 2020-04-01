// SWEA 9282 초콜릿과 건포도
/*
    DP를 이용한 문제 풀이.
    혼자 하기에 벅차, 4차원 배열을 이용한다는 힌트를 얻었다.
    건포도를 재귀함수가 돌아갈때마다 세면 22개중 21개의 테스트케이스가 맞는다.
    이를 해결하기 위해 0,0 부터 y,x까지의 구간합을 미리 구하고, 필요한 부분을 불러와 해당 구간의 합을 구하였다.
    초콜릿을 나눌때 최소의 건포도의 합이 나오는 것을 찾아나감.
    DP는 너무 어렵다..
*/
#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int presum[50][50];
int choco[50][50];
int dp[50][50][50][50];

int solve(int r, int c, int h, int w){
    if(h == 1 && w == 1) return 0;
    
    int& ret = dp[r][c][h][w];
    if(ret != -1) return ret;

    ret = 987987987;

    // 현재 범위의 건포도 합
    int sum;
    if(r == 0 && c != 0) sum = presum[r+h-1][c+w-1] - presum[r+h-1][c-1];
    else if(r != 0 && c == 0) sum = presum[r+h-1][c+w-1] - presum[r-1][c+w-1];
    else if(r == 0 && c == 0) sum = presum[r+h-1][c+w-1];
    else sum = presum[r+h-1][c+w-1] - presum[r+h-1][c-1] - presum[r-1][c+w-1] + presum[r-1][c-1];

    for(int i = 1 ; i < h ; i++){
        ret = min(ret, sum + solve(r,c,i,w) + solve(r+i,c,h-i,w));
    }

    for(int i = 1 ; i < w ; i++){
        ret = min(ret, sum + solve(r,c,h,i) + solve(r,c+i,h,w-i));
    }
    return ret;
}

int main(){
    int tc;
    cin >> tc;
    for(int x = 1 ; x <= tc ; x++){
        memset(dp,-1,sizeof(dp));
        cin >> n >> m; // 세로 가로
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> choco[i][j]; // 건포도 수
            }
        }

        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = 0 ; j < m ; j++){
                presum[i][j] = 0;
                if(i == 0){
                    sum += choco[i][j];
                    presum[i][j] = sum;
                }
                else{
                    sum += choco[i][j];
                    presum[i][j] = sum + presum[i-1][j];
                }
            }
        }

        int ans = solve(0,0,n,m);

        cout << "#" << x << " " << ans << "\n";
    }
    return 0;
}