// 백준 7452 합이 0인 네 정수
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int cnt;
long long int a[4000];
long long int b[4000];
long long int c[4000];
long long int d[4000];
long long int arr1[16000000]; 
long long int arr2[16000000];
// 4000^4 => 완탐 X 
/*
a b / c d로 나눔
*/
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		// a b c d
		cin >> a[i] >> b[i] >> c[i]>> d[i];
	}
	
	// a와 b에서 하나를 뽑아 더하는 모든 경우를 저장
	int p = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			arr1[p++] = a[i] + b[j];
		}
	}
	// c와 d에서 하나를 뽑아 더하는 모든 경우를 저장
	p = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			arr2[p++] = c[i] + d[j];
		}
	}
	
	// c,d를 더한 배열을 정렬
	sort(arr2,arr2+p);
	
	for(int i = 0 ; i < p ; i++){
		// 더해서 0이 되는 값을 a+b 배열에서 찾음
		long long int idx = binary_search(arr2,arr2+p, (-1)*arr1[i]);
		if(idx){
			long long int cur = (-1)*arr1[i];
			// 개수를 찾아야 하기 때문에 lower,upper bound를 찾음
			long long int s = lower_bound(arr2,arr2+p, cur) - arr2;
			long long int e = upper_bound(arr2,arr2+p, cur) - arr2;
			// 만약 lower bound로 나온 값과 cur을 더했을 떄 0 이면 +1
			s += (cur != arr2[s]);
			// 만약 e가 마지막이거나 cur와 더했을 때 0이 아니면 -1
			e -= (e == p || cur != arr2[e]);
			if(s == e) cnt++; // s와 e가 같으면 1
			else cnt += e - s + 1; // 아니면 index값 차이
		}
	}
	cout << cnt << endl;
	return 0;
}
