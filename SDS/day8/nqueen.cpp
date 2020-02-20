// 백준 9663 N-QUEEN
// 백트래킹 문제
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[20][20];
int r[20];
int c[20];
int cnt;

int check(int y, int x){
	//가로
	for (int i = 0; i < n; i++) {
		if (i == x) continue;
		if (map[y][i] == 1) {
			return -1;
		}
	}
	//세로
	for (int i = 0; i < n; i++) {
		if (i == y) continue;
		if (map[i][x] == 1) {
			return -1;
		}
	}
	//대각
	for (int i = 1; i < n; i++) {
		int ny = y + i;
		int nx = x + i;
		if (ny >= n || nx >= n || ny < 0 || nx < 0) break;

		if (map[ny][nx] == 1) return -1;
	}
	for (int i = 1; i < n; i++) {
		int ny = y - i;
		int nx = x - i;
		if (ny >= n || nx >= n || ny < 0 || nx < 0) break;

		if (map[ny][nx] == 1) return -1;
	}
	//역대각
	for (int i = 1; i < n; i++) {
		int ny = y + i;
		int nx = x - i;
		if (ny >= n || nx >= n || ny < 0 || nx < 0) break;

		if (map[ny][nx] == 1) return -1;
	}
	for (int i = 1; i < n; i++) {
		int ny = y - i;
		int nx = x + i;
		if (ny >= n || nx >= n || ny < 0 || nx < 0) break;

		if (map[ny][nx] == 1) return -1;
	}
	// 놓을 수 있음
	return 1;
}
void bt(int cur, int row) {
	if (row > n) return;
	if (cur == n) {
		cnt++;
		return;
	}
	else {
		int y = row + 1;
		for (int x = 0; x < n; x++) {
			if (r[x] == 1) continue;
			if (check(y, x) == 1) {
				map[y][x] = 1;
				r[x] = 1;
				bt(cur + 1, row + 1);
				r[x] = 0;
				map[y][x] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		map[0][i] = 1;
		r[i] = 1;
		bt(1,0);
		r[i] = 0;
		map[0][i] = 0;
	}

	cout << cnt << endl;
	return 0;
}