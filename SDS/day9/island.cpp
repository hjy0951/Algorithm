// 백준 4963 섬의 개수
// 일반적인 BFS 문제
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int w, h, cnt;
int map[51][51];
int visit[51][51];
int dy[] = { 1,-1,0,0,1,-1,-1,1 };
int dx[] = { 0,0,-1,1,1,-1,1,-1 };

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < h && nx >= 0 && nx < w && visit[ny][nx] == 0 && map[ny][nx] == 1) {
				q.push(make_pair(ny, nx));
				visit[ny][nx] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(1) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));

		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}