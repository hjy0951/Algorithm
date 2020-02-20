// 백준 1103 게임
#include <iostream>
#include <cstdio>
#include <cstring>
#define max(a,b) a > b ? a: b

using namespace std;

int n, m;
int map[50][50];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 }; // 우 하 좌 상
int visit[50][50];
int dp[50][50];

int play(int y, int x) {
	// 범위를 벗어나거나 구멍에 들어간 경우
	if (y < 0 || x < 0 || y >= n || x >= m) return 0;
	if (map[y][x] == 0) return 0;
	if (visit[y][x]) { // cycle
		// maxn = -1;
		printf("-1\n");
		exit(0);
	}

	int &ret = dp[y][x];
	// 시간차이가 발생한 이유는 캐시 hit에 의한것
	// 레퍼런스가 아닌 일반 변수를 통해 값을 복사했다면,
	// b를 접근할 경우와 a를 접근할 경우
	// 두 변수의 메모리 공간이 다르기 때문에 캐시 hit fail이 발생할 수 있음
	/*
		c++에서 int &a = b을 해석하면, a는 b 그 자체 (같은 주소)를 의미
		하지만 int a = b에서 a는 b와 같은 값을 가지는 다른 변수
		따라서 아래의 경우에는 메모리할당, b로부터 값 복사가 실행되지만,
		첫번째는 없기 때문에 속도 측면에서만 레퍼런스를 보면 더 빠르다
	*/
	if (ret != -1) return ret;

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * map[y][x];
		int nx = x + dx[i] * map[y][x];

		int temp = play(ny, nx) + 1;
		ret = max(ret, temp);
	}

	visit[y][x] = 0;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			scanf(" %1c", &a);

			if (a == 'H') map[i][j] = 0;
			else map[i][j] = a - '0';
		}
	}
	printf("%d\n", play(0, 0));

	return 0;
}