// 백준 15663 N과 M (9) 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//N개의 자연수 중에서 M개를 고른 수열

int n,m;
vector<int> v;
vector<int> ans;
int num[10001];

void find(int cur, int cnt){
	if(cnt >= m){
		for(int i = 0 ; i < ans.size() ; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	else{
		set<int> st;
		for(int i = 0 ; i < v.size() ; i++){
			st.insert(v[i]);
		}
		set<int>::iterator it;
		// set에서 중복되지 않게 하나씩 확인하며 체크
		for(it = st.begin() ; it != st.end() ;it++){
			if(num[*it] > 0){
				num[*it]--;
				ans.push_back(*it);
				find(*it, cnt+1);
				ans.pop_back();
				num[*it]++;
			}
		}
	}	
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		int a;
		cin >> a;
		v.push_back(a);
		num[a]++;
	}
	// 숫자 정렬
	sort(v.begin(),v.end());
	
	if(m == 1){
		int visit[10001] = {0,};
		for(int i = 0 ; i < v.size() ; i++){
			if(visit[v[i]] == 0){
				cout << v[i] << endl;
				visit[v[i]] = 1;
			}
		}
	}
	else{
		set<int> s;
		for(int i = 0 ; i < v.size() ; i++){
			s.insert(v[i]);
		}
		set<int>::iterator it;
		for(it = s.begin() ; it != s.end() ;it++){
			num[*it]--;
			ans.push_back(*it);
			find(*it, 1);
			ans.pop_back();
			num[*it]++;
		}
	}
	
	
	return 0;
}
