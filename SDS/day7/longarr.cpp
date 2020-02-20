// 백준 14003 가장 긴 증가하는 부분 수열 5
/*
Longest Increasing Subsequence라는 유명한 문제라고 함
이 알고리즘은 다음과 같은 리스트 L을 업데이트하며 동작합니다. 
벡터가 비어있거나 현재 위치의 원소가 벡터의 back보다 큰 경우
	push
그렇지 않을 경우
	lower_bound로 이분탐색하여 해당위치의 원소를 현재값으로 update
끝까지 탐색을 마친 후 벡터의 길이가 LIS의 길이
하지만 벡터에 남은 것을 그대로 출력할 경우 실제 LIS의 원소와는 다를 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define MAX 1000000000

int n;
vector<ll> num;
vector<ll> v;
vector<ll> print;
int p[1000001];
int cnt;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		num.push_back(a);
	}

	v.push_back(-MAX - 1);

	for (int i = 0; i < num.size(); i++) {
		if (v.back() < num[i]) {
			v.push_back(num[i]);
			cnt++;
			p[i] = cnt;
		}
		else if(v.back() > num[i]){
			int idx = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
			v[idx] = num[i];
			p[i] = idx;
		}
	}
	cout << v.size()-1 << endl;
	for (int i = n - 1; i >= 0 && cnt >= 0; i--) {
		if (p[i] == cnt) {
			print.push_back(num[i]);
			cnt--;
		}
	}
	for (int i = print.size()-1; i >= 0; i--) {
		cout << print[i] << " ";
	}
	cout << endl;
	
	return 0;
}