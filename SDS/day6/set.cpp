// 백준 1717 집합의 표현
// union-find로 해결
#include <iostream>
#include <utility>

using namespace std;

int n,m;
int num[1000001];

int find(int x) { // x의 root 리턴 
	if(num[x] == x) return x;
	else{
		int parent = find(num[x]);
		return parent;
	}
}

void uunion(int x, int y){ // 집합을 합침
	int xp = find(x);
	int yp = find(y);
	
	if(xp < yp) num[yp] = xp;
	else num[xp] = yp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	// �ʱ�ȭ 
	for(int i = 0 ; i <= n ; i++){
		num[i] = i;
	}
	
	for(int i = 0 ; i < m ; i++){
		int op,a,b;
		cin >> op >> a >> b;
		
		
		if(op == 0){ // 합집합
			if(a == b) continue;
			uunion(a,b);
		}
		else { // 두 원소가 같은 집합인지
			int ah = find(a);
			int bh = find(b);
			
			if(ah != bh) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}
/*
3 3
0 1 2
0 1 3
1 2 3
*/
