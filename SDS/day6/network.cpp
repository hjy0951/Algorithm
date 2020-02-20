// 백준 1922 네트워크 연결 | 크루스칼?
// union - find 를 활용하여 해결
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n,m;
vector<pair< pair<int,int> ,int> > v;
int totalcost;
int num[1001]; // cluster

bool cmp(pair< pair<int,int> ,int> x, pair< pair<int,int> ,int> y){
	return x.second < y.second;
} // cost로 오름차순 정렬

int find(int x){ // 해당 노드의 대표노드가 무엇인지 반환
	if(x == num[x]) return x;
	else{
		int parent = find(num[x]);
		return parent;
	}
}

void unionn(int y, int x){ // 대표 노드를 연결
	y = find(y);
	x = find(x);
	
	if(y > x) num[y] = x;
	else num[x] = y;
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i <= n ; i++) num[i] = i;
	
	for(int i = 0 ; i < m ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}
		v.push_back(make_pair( make_pair(a, b), c) );
	}
	sort(v.begin(),v.end(), cmp); // cost로 오름차순 정렬
	
	int cnt = 0;
	for(int i = 0 ; i < v.size() ; i++){
		pair< pair<int,int> ,int> cur = v[i];
		
		int ah = find(cur.first.first);
		int bh = find(cur.first.second);
		
		if(ah != bh){
//			cout << i << endl;
			unionn(ah, bh);
			totalcost += cur.second;
			cnt++;
		}
		if(cnt == n-1) break;
	}
	cout << totalcost << "\n";
	return 0;
}
