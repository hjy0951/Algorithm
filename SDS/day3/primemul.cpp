// 백준 2014 소수의 곱
#include <iostream> 
#include <queue>

using namespace std;

int k,n;
int arr[100];

// max heap 이용
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main(){
	cin >> k >> n;
	for(int i = 0 ; i < k ; i++){
		cin >> arr[i];
		pq.push(arr[i]);
	}
	
	long long int c; // int로 하면 안됨
	while(--n){ // n번 반복되도록
		c = pq.top();
		pq.pop();
		for(int i = 0 ; i < k ; i++){
			pq.push(c*arr[i]);
			if(!(c%arr[i])) break;
			// 큐에서 뽑은 값이 입력받은 값으로 나누어 떨어지면 break
		}
	}
	
	cout << pq.top() << endl;
	return 0;
}
