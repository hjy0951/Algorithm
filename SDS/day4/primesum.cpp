// 백준 1644 소수의 연속합
#include <iostream> 
#include <vector> 

using namespace std;

long long int n;
vector<int> prime;
int check[4000001];
int cnt;

int main(){
	cnt = 0;
	
	cin >> n;
	
	if(n == 1){
		cout << 0 << "\n";
		return 0;
	}
	else if(n == 2 || n == 3){
		cout << 1 << "\n";
		return 0;
	}
	
	// n보다 작은 소수들을 prime q에 넣음
	for(int i = 2 ; i <= n ; i++){
		if(check[i] == 0){
			int cur = i;
			prime.push_back(cur);
			check[i] = 1;
			
			cur += i;
			while(cur <= n){
				if(check[cur] == 0) check[cur] = 1;
				cur += i;
			}
		}
	}
	
	// 큐 안에서 투 포인터를 이용하여 수가 만들어지는 합 구간을 찾음
	int s = 0, e = 0;
	int len = prime.size();
	long long int sum = 0;
	
	while(e <= len){
		if(sum < n){
			sum += prime[e];
			e++;
		}
		else if(sum > n){
			sum -= prime[s];
			s++;
		}
		
		if(sum == n){
			cnt++;
			sum += prime[e];
			e++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
