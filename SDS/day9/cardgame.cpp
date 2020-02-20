// 백준 11062 카드게임
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int card[1001];
int dp[1001][1001];

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int solve(bool cur, int s, int e) {
	int& ret = dp[s][e];
	if (ret != 0) return ret; // 이미 존재할 경우 return

	if (s >= e) {
		if (cur % 2 == 1) return ret = card[s];
		else return ret = 0;
	}

	if (cur) { // 내 차례 : 최대가 되는 쪽으로
		ret = max(solve(!cur, s+1, e) + card[s], solve(!cur,s,e-1) + card[e]);
	}
	else { // 상대 차례 : 최소가 되는 쪽으로
		ret = min(solve(!cur, s + 1, e), solve(!cur, s, e - 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> card[i];
		}

		cout << solve(true, 1, n) << "\n";
	}

	return 0;
}