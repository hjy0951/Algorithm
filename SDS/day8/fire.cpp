// 백준 4179 불!
// 일반적인 BFS 문제
// 3055번 탈출 문제와 유사함
// 불을 퍼트리고 불이 도착하는 시간보다 사람이 도착하는 시간이 더 작을 경우에만 전진
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int map[1000][1000];
int visit[1000][1000];
int f[1000][1000];
int n, m;
int sy, sx, fy, fx;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void fire() {
	queue<pair<int, int> > q;
	q.push(make_pair(fy, fx));
	f[fy][fx] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 1) {
				f[ny][nx] = f[cy][cx] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			scanf(" %1c", &a);

			if (a == '#' ) {
				map[i][j] = 0;
			}
			else if (a == 'F') {
				fy = i;
				fx = j;
				map[i][j] = 0;
			}
			else if (a == 'J') {
				sy = i;
				sx = j;
				map[i][j] = 1;
			}
			else {
				map[i][j] = 1;
			}
		}
	}

	fire();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}