// 백준 15664 N과 M(10)
// 9와 같은 방식으로 풀림
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
vector<int> v;
vector<int> ans;
int num[10001];
set<int> s;

void find(set<int>::iterator idx, int cnt){
	if(cnt == m){
		for(int i = 0 ; i < ans.size() ; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else{
		set<int>::iterator it;
		for(it = idx ; it != s.end() ; it++){
			if(num[*it] > 0){
				num[*it]--;
				ans.push_back(*it);
				find(it, cnt+1);
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
	
	sort(v.begin(), v.end());
	
	if(m == 1){
		int visit[10001] = {0,};
		for(int i = 0 ; i < v.size() ; i++){
			if(visit[v[i]] == 0){
				cout << v[i] << endl;
				visit[v[i]] = 1;
			}
		}
		return 0;
	}
	
	for(int i = 0 ; i < v.size() ; i++){
		s.insert(v[i]);
	}
	
	set<int>::iterator it;
	for(it = s.begin() ; it != s.end() ; it++){
		num[*it]--;
		ans.push_back(*it);
		find(it, 1);
		ans.pop_back();
		num[*it]++;
	}
	
	return 0;
}
