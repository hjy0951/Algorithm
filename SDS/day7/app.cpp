// 백준 7579 앱
/*
현재 N개의 앱, A1, ..., AN이 활성화 되어 있다고 가정
이들 앱 Ai는 각각 mi 바이트만큼의 메모리를 사용
앱 Ai를 비활성화한 후에 다시 실행하고자 할 경우
	추가적으로 들어가는 비용(시간 등)을 수치화 한 것을 ci
이러한 상황에서 사용자가 새로운 앱 B를 실행하고자
	추가로 M 바이트의 메모리가 필요
즉, 현재 활성화 되어 있는 앱 중 몇 개를 비활성화 하여
	M 바이트 이상의 메모리를 추가로 확보
비활성화 했을 경우의 비용 ci의 합을 최소화
필요한 메모리 M 바이트를 확보하는 방법을 찾아야 한다.
*/
// 비활성화 했을 경우의 비용 ci의 합을 최소화
// 필요한 메모리 M 바이트를 확보
#include <iostream>
#include <algorithm>

using namespace std;
// typedef long long int ll;

int n, m;
int app[100];
int cost[100];
int dp[101][10001]; // 메모리를 기준으로 함
int mincost;

int main() {
	mincost = 987987987;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> app[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	dp[0][ cost[0] ] = app[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			// 비활성화 (메모리확보)
			if(j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][ j-cost[i]] + app[i]);
			// 그대로 둠
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= m) mincost = min(mincost, j);
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 16; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	cout << mincost << endl;
	return 0;
}