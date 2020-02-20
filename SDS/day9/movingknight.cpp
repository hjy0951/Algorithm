// 백준 7562 나이트의 이동
// 기본적인 BFS 문제
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int gy, gx;
int dy[] = { 1,-1,1,-1,2,2,-2,-2 };
int dx[] = { 2,2,-2,-2,1,-1,1,-1 };
int minn;

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	int visit[300][300] = { 0, };
	q.push(make_pair(y, x));
	visit[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < n && visit[ny][nx] == 0) {
				if (ny == gy && nx == gx) {
					minn = min(minn, visit[cy][cx]);
					visit[ny][nx] = visit[cy][cx] + 1;
				}
				else {
					visit[ny][nx] = visit[cy][cx] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		minn = 987987987;
		cin >> n;
		int y, x;
		cin >> y >> x;
		cin >> gy >> gx;

		if (y == gy && x == gx) {
			minn = 0;
		}
		else bfs(y, x);
		cout << minn << "\n";
	}
	return 0;
}