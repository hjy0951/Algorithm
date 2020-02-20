// 백준 11049 행렬 곱셈 순서
#include <iostream>
#include <utility>
#include <deque>

using namespace std;

int n;
deque<pair<int, int> > dq;
int dp[501][501];
// long long int minn;

int solve(int y, int x) {
	if(x == y) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	int minn = 987987987;

	for (int k = y ; k < x; k++) {
		minn = min(minn, solve(y, k) + solve(k+1, x) + dq[y].first * dq[k].second * dq[x].second);
	}
	dp[y][x] = minn;
	return dp[y][x];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		dq.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	solve(0, n - 1);
	
	cout << dp[0][n-1] << "\n";

	/*
	덱 안에서 최소가 되는 쪽으로 곱셈을 해 나감
	 = greedy algorithm으로 최소값이 아닐 수도 있음

	for (int i = 0; i < n; i++) {
		long long int rowsum = 0;
		for (int j = i; j < n-1; j++) {
			rowsum += dq[j].first * dq[j].second * dq[j + 1].second;
		}
	}
	while (dq.size() >= 2) {
		int idx, cnt = 987987987;
		for (int i = 0; i < dq.size()-1; i++) {
			int cy = dq[i].first;
			int cx = dq[i].second;
			int nx = dq[i + 1].second;
			int temp = cy * cx * nx;

			if (cnt > temp) {
				cnt = temp;
				idx = i;
			}
		}

		for (int i = 0 ; i < dq.size() ; i++) {
			pair<int, int> cur = dq.front();
			dq.pop_front();

			if (i == idx) {
				pair<int, int> next = dq.front();
				dq.pop_front();
				dq.push_back(make_pair(cur.first, next.second));
			}
			else dq.push_back(cur);
		}

		minn += cnt;
	}
	cout << minn << "\n";
	*/
	return 0;
}

/*
8
1 100
100 1
1 100
100 1
1 100
100 1
1 100
100 1
*/