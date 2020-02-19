// 백준 1339 단어 수학
/*
만약, ABC + AECB 라면
ABC  => A : alpha[0] += 100  | B : alpha[1] += 10  | C : alpha[2] += 1
AECB => A : alpha[0] += 1000 | E : alpha[4] += 100 | C : alpha[2] += 10 | B : alpha[1] += 1
따라서,
alpha[0] == 1100
alpha[1] == 11
alpha[2] == 11
alpha[4] == 100
이제 이를 정렬하여 큰 값부터 차례대로 9 8 7 ... 순서로 알파벳에 숫자를 할당하여 다 더해주면 최대값
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int alpha[27];
vector<pair<int, int> > v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int len = str.size();
		int std = 1;
		for (int j = len - 1; j >= 0; j--) {
			int cur = str[j] - 'A';
			alpha[cur] += std;
			std = std * 10;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] != 0) {
			v.push_back(make_pair(alpha[i], i));
		}
	}
	sort(v.begin(), v.end());
	
	int std = 9;
	int ans = 0;
	while (!v.empty()) {
		int cur = v.back().first;
		v.pop_back();

		ans += cur * std;
		std--;
	}
	cout << ans << "\n";
	return 0;
}