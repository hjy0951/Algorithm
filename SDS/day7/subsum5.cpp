// 백준 11660 구간 합 구하기5
#include <iostream>

using namespace std;

int n, m;
int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	// 0,0 부터 각 지점까지의 구간 합을 미리 더해서 기록해놓음
	for (int i = 1; i <= n; i++) {
		int rowsum = 0;
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			rowsum += num;
			if (i == 1) {
				dp[i][j] = rowsum;
			}
			else {
				dp[i][j] = rowsum + dp[i - 1][j];
			}
		}
	}
/*
0,0
  1 2
  3 4
    y,x
= 4에 해당하는 구간의 합을 구하려면 (4,3,2,1) - (3,1) - (2,1) + (1)
*/
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1] << "\n";
	}

	
	return 0;
}