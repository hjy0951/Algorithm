// 백준 11659 구간 합 구하기4
#include <iostream>

using namespace std;

int n, m;
int arr[100000];
int dp[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 미리 0~n 까지의 구간합을 더해 기록
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		int s = a-1, e = b-1;
		if (s == e) {
			cout << arr[s] << "\n";
		}
		else {
			if (s == 0) {
				cout << dp[e] << "\n";
			}
			else {
				cout << dp[e] - dp[s - 1] << "\n";
			}
		}
	}
	return 0;
}