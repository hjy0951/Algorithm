// 백준 5568 카드놓기 
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> s;
string card[10];
int check[10];
int n;
int k;

void find(int cur, int cnt, string str){
	if(cnt == k){
//		cout << str << endl;
		s.insert(str);
		return;
	}
	else{
		string temp = str;
		for(int i = 0 ; i < n ; i++){
			if(check[i] == 1) continue; // 이미 사용한 카드
			check[i] = 1;
			find(i, cnt+1, temp + card[i]); // 카드 놓기
			check[i] = 0;
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> card[i];
	}
	
	for(int i = 0 ; i < n ; i++){
		check[i] = 1;
		find(i,1, card[i]);
		check[i] = 0;
	}
	
	cout << s.size() << "\n";
	return 0;
}
