// 백준 1517 버블소트
// 문제는 버블소트지만 버블소트로 풀 경우, 시간초과가 발생하는 문제
// 머지소트에서 스왑이 되는 횟수와 버블소트에서 스왑이 되는 수가 같다는 점을 이용하여 푸는 문제
#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

int n;
vector<ll> arr;
ll cnt;

void merge(int s1, int e1, int s2, int e2) {
	int p = s1, q = s2;
	vector<ll> temp;

	while (p <= e1 && q <= e2) {
		if (arr[p] > arr[q]) {
			// 현재 원소가 앞으로 얼마나 당겨지는지를 카운트
			int tlen = temp.size() + s1;
			cnt += q - tlen;

			temp.push_back(arr[q]);
			q++;
		}
		else {
			temp.push_back(arr[p]);
			p++;
		}
	}

	while (q <= e2) {
		temp.push_back(arr[q]);
		q++;
	}
	while (p <= e1) {
		temp.push_back(arr[p]);
		p++;
	}
	
	for (int i = 0; i < temp.size(); i++) {
		arr[i+s1] = temp[i];
	}
}

void msort(int s, int e) {
	int mid;
	if (s < e) {
		mid = (s + e) / 2;
		msort(s,mid);
		msort(mid+1,e);
		merge(s,mid,mid+1,e);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	msort(0, arr.size()-1);

	//for (int i = 0; i < arr.size(); i++) {
	//	cout << arr[i] << " ";
	//}
	//cout << endl;
	cout << cnt << "\n";
	return 0;
}