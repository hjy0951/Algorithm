// 백준 2725 보이는 점의 개수
// (y,x)에서 y와 x의 서로소 여부를 판단하여 푸는 문제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[1001];
int t;

int gcd(int a, int b) { // 최대공약수 구하기
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int g = 0;
	while (b != 0) {
		g = a % b;
		a = b;
		b = g;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	num[1] = 1;
	for (int i = 2; i < 1001; i++) {
		int c = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) c++;
		}
		num[i] = num[i - 1] + c;
	}
	
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n;
		cin >> n;

		

		cout << num[n] * 2 + 1 << "\n";
	}
	return 0;
}