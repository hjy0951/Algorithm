// 백준 2003 수들의 합2 
#include <iostream>

using namespace std;

int n;
long long int m;
int arr[10000];
int cnt;
//  M이 되는 경우의 수

int main(){
	cnt = 0;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	
	long long int sum = 0;
	int s = 0;
	int e = 0;
	while(e <= n){
		// m보다 작은 경우
		if(sum < m){
			sum += arr[e];
			e++;
		}
		// m보다 큰 경우
		else if(sum > m){
			sum -= arr[s];
			s++;
		}
		// m과 같은 경우
		if(sum == m){
			cnt++;
			sum += arr[e];
			e++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
