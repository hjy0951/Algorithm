// 백준 14476 최대공약수 하나 빼기
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000000];
int check[1000000];
vector<int> v1; // 앞에서부터 최대공약수를 구함
vector<int> v2; // 뒤에서부터 최대공약수를 구함
int maxn;
int m;

int gcd(int a, int b){ // 최대공약수 구하기
	if(a < b){ // 항상 a > b
		int temp = a;
		a = b;
		b = temp;
	}
	
	int g;
	while(b != 0){
		g = a%b;
		a = b;
		b = g;
	}
	return a;
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	
	v1.push_back(arr[0]);
	v2.push_back(arr[n-1]);
	for(int i = 1 ; i < n - 1 ; i++){
		v1.push_back(gcd(v1.back(), arr[i]));
		v2.push_back(gcd(v2.back(), arr[n-i-1]));
	}
	int len = v1.size();
	
	for(int i = 1 ; i < len-1 ; i++){
		int x = gcd(v1[i-1],v2[len - 1 - i]);
		if(x > maxn){
			maxn = x;
			m = arr[i];
		}
	}
	
	if(v1[v1.size()-1] > v2[v2.size()-1]){
		if(maxn < v1[v1.size()-1]){
			maxn = v1[v1.size()-1];
			m = arr[n-1];
		}
	}
	else{
		if(maxn < v2[v2.size()-1]){
			maxn = v2[v2.size()-1];
			m = arr[0];
		}
	}
	
	if(m%maxn) cout << maxn << " " << m << endl;
	else cout << "-1" << endl;
	return 0;
}
