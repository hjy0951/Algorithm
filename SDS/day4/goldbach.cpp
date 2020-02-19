// 백준 6588 골드바흐의 추측
// = 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int check[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i = 2 ; i <= 1000000 ; i++){ // 소수 구하기
		if(check[i] == 1) continue;
		
		int cur = i;
		v.push_back(cur);
		
		cur += i;
		while(cur <= 1000000){
			if(check[cur] == 0) check[cur] = 1;
			cur += i;
		}
	}
	
//	for(int i = 0 ; i < v.size() ; i++){
//		cout << v[i] << " ";
//	}
//	cout << endl;
	
	int len = v.size();
	
	while(1){
		int n;
		cin >> n;
		
		if(n == 0) break;
		
		int a = -1;
		int b = -1;
		for(int i = 0 ; i < len ; i++){
			int cur = v[i]; // 현재 소수
			int g = n - cur; // 검증하려는 짝수
			
			// g에서 뺀 값이 0이 나오는 값을 찾음
			int idx = lower_bound(v.begin(), v.end(), g) - v.begin();
			if(v[idx] == g){ // 값이 맞다면 break;
				a = cur;
				b = g;
				break;
			}
		}
		if(b > 0) cout << n << " = " << a << " + " << b << "\n";
		else cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}
