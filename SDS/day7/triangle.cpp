// 백준 1932 정수 삼각형
// 양 끝을 제외하고 가운데는 왼쪽 위, 오른쪽 위에서 내려오는 두가지 방법 존재
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tri[501][501];
int dp[501][501];
int maxn;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// 왼쪽 끝
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			// 오른쪽 끝
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			// 가운덷
			else {
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tri[i][j];
			}
			maxn = max(dp[i][j], maxn);
		}
	}
	cout << maxn << "\n";
	return 0;
}