// 백준 14501 퇴사
// 일반적인 DP 문제지만 아이디어 생각하기가 어려웠다..
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int t[20]; // 걸리는 시간
int p[20]; // 비용
int dp[20];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	int maxn = 0;
	for (int i = 1; i <= n + 1; i++) {
		dp[i] = max(maxn, dp[i]);

		if(i + t[i] <= n+1) // 상담을 마친 다음날 돈을 받는 것으로 생각
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);

		maxn = max(maxn, dp[i]);
	}

	cout << maxn << "\n";
	return 0;
}