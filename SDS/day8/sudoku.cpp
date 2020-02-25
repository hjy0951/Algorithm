// 백준 2580 스도쿠
// 백트래킹 문제
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int map[9][9];
vector<int> v[9]; // 각 행 별로 부족한 숫자를 담아둘 벡터
// => 이를 통해 다른 코드보다 속도를 조금이나마 줄일 수 있었던 것 같다.
vector<pair<int, int> > p;
int cnt;

void printm() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// 가로 검사  
bool check1(int r, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[r][i] == num)
			return false;
	}
	return true;
}

// 세로 검사  
bool check2(int c, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][c] == num)
			return false;
	}
	return true;
}

// 3x3 검사  
bool check3(int r, int c, int num) {
	r = r / 3;
	c = c / 3;
	for (int rr = r * 3; rr < (r * 3) + 3; rr++) {
		for (int cc = c * 3; cc < (c * 3) + 3; cc++) {
			if (map[rr][cc] == num)
				return false;
		}
	}
	return true;
}

void bt(int c) {
	if (c == cnt) {
		printm();
		exit(0);
	}
	else {
		int cy = p[c].first;
		int cx = p[c].second;

		for (int i = 0; i < v[cy].size(); i++) {
			int cur = v[cy][i];// 부족한 숫자가 들어있는 벡터에서 숫자를 넣어보면서 DFS

			if ((check1(cy, cur) && check2(cx, cur) && check3(cy, cx, cur)) == true) {
				map[cy][cx] = cur;
				bt(c+1);
				map[cy][cx] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		int num[10] = {0,};
		int t;
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			num[map[i][j]] = 1;
			if (map[i][j] == 0) {
				t = j;
			}
		}

		for (int j = 1; j < 10; j++) {
			if (num[j] == 0) {
				v[i].push_back(j);
				cnt++;
			}
		}
		if (v[i].size() == 1) {
			map[i][t] = v[i][0];
			v[i].pop_back();
			cnt--;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) p.push_back(make_pair(i, j));
		}
	}

	bt(0);

	return 0;
}
