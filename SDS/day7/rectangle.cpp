// 백준 1915 가장 큰 정사각형
// dp 2차원 배열에서 1씩 모두 뺀 후 0보다 큰 수들을 더하면
// 그릴 수 있는 사각형 수
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int map[1001][1001];
int dp[1001][1001];
int maxr;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) maxr = 1;
		}
	}
	if (maxr == 0) {
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;

			if (i == 0 || j == 0) dp[i][j] = map[i][j];
			else {
			// 좌, 상, 좌상을 확인하고 모두 0이 아니라면
			// 그중 최소값 +1에 해당하는 크기의 사각형을 그릴 수 있음
				int minn = 987987987;
				minn = min(minn, dp[i-1][j-1]);
				minn = min(minn, dp[i-1][j]);
				minn = min(minn, dp[i][j-1]);
				dp[i][j] = minn + 1;
			}

			maxr = max(maxr, dp[i][j]);
		}
	}
	
	printf("%d\n", maxr*maxr);
	return 0;
}