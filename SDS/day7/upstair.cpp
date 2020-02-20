// 백준 2579 계단 오르기
/*
계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임.
계단마다 점수가 존재
	계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다.
	연속된 세 개의 계단을 모두 밟아서는 안 된다.
	마지막 도착 계단은 반드시 밟아야 한다.
점수의 최대값을 구하라
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int point[301];
int dp[301];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> point[i];
	}
	dp[0] = point[0];
	dp[1] = point[1] + point[0];
	dp[2] = max(point[0]+point[2], point[1] + point[2]);
	
	for (int i = 3; i < n; i++) {
		// 1. XOO
		int f = dp[i - 3] + point[i - 1] + point[i];
		// 2. OXO
		int s = dp[i - 2] + point[i];

		dp[i] = max(f, s);
	}

	cout << dp[n-1] << "\n";
	return 0;
}