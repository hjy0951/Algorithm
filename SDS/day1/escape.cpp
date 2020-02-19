#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int r, c;
char map[60][60];
int check[60][60]; // 방문한 곳 체크
int minn;
int finish; // 탈출 성공 여부
queue<pair<int, int> > q;
int sy, sx; // 시작 위치
//int gy, gx;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 }; // 하 상 좌 우

void print() {
	for (int i = 0 ; i < r ; i++) {
		for (int j = 0 ; j < c ; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}

void printv(int arr[][60]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}

void flood() { // bfs로 물을 퍼뜨림
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0 ; i < 4 ; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
				if (check[ny][nx] == 0 && (map[ny][nx] == '.')) {
					check[ny][nx] = check[cy][cx] + 1;
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
}

void find() { // 탈출구 찾기
	int visit[60][60] = { 0, };
	queue<pair<int, int> > fq;
	fq.push(make_pair(sy, sx));
	visit[sy][sx] = 1;

	while (!fq.empty()) {
		int cy = fq.front().first;
		int cx = fq.front().second;
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
				if (visit[ny][nx] == 0 && (map[ny][nx] == '.' || map[ny][nx] == 'D')) {
                    // 갈 수 있는 곳이 이미 방문한 곳이 아니고, 물이 들어오는 시간보다 빨리 도착한 경우, 또한 물이 들어오지 않는 곳일 경우, 전진
					if (visit[cy][cx] + 1 < check[ny][nx] || (map[ny][nx] == '.' && check[ny][nx] == 0)) {
						visit[ny][nx] = visit[cy][cx] + 1;
						fq.push(make_pair(ny, nx));
					}
					else if (map[ny][nx] == 'D') {
						finish = 1;
						visit[ny][nx] = visit[cy][cx] + 1;
						if (visit[ny][nx] < minn) {
							minn = visit[ny][nx];
						}
					}
				}
			}
		}
	}
}

int main() {
	finish = 0;
	memset(check, 0, sizeof(check));
	minn = 987987987;
	cin >> r >> c;

	for (int i = 0 ; i < r ; i++) {
		for (int j = 0 ; j < c ; j++) {
			cin >> map[i][j];

			if (map[i][j] == '*') {
				check[i][j] = 1;
				q.push(make_pair(i, j)); // 물이 여러 군데 있을 수 있으므로 q에 미리 넣음
			}
			else if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
//			else if (map[i][j] == 'D') {
//				gy = i;
//				gx = j;
//			}
		}
	}

	flood();
	find();

	if (finish == 0) cout << "KAKTUS" << endl;
	else cout << minn-1 << endl;

	return 0;
}
