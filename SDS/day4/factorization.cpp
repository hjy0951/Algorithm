// 백준 11653 소인수분해 
#include <iostream>
#include <vector>

using namespace std;

int n;
int check[10000001];
vector<int> v;

int main(){
	cin >> n;
	for(int i = 2 ; i <= n ; i++){ // n까지의 소수 추출
		if(check[i] == 1) continue;
		
		int cur = i;
		v.push_back(cur);
		check[i] = 1;
		
		while(cur <= n){
			if(check[cur] == 0) check[cur] = 1;
			cur += i;
		}
	}
	
//	for(int i = 0 ; i < v.size() ; i++){
//		cout << v[i] << " ";
//	}
//	cout << endl;
	
	int cnt = 0;
	int len = v.size();
	while(n > 0 && cnt < len){
		if(n % v[cnt] == 0){
			cout << v[cnt] << "\n";
			n = n/v[cnt];
		}
		else cnt++;
	}
	
	return 0;
}
