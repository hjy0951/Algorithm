// 백준 2458 키 순서
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[501]; // 정방향
vector<int> rg[501]; // 역방향 (화살표를 반대로)
int n,m;
int cnt;

int bfs(int c, vector<int> t[]){
	int res = 0;
	int visit[501] = {0,};
	queue<int> q;
	for(int i = 0 ; i < t[c].size() ; i++){
		q.push(t[c][i]);
		visit[t[c][i]] = 1;
		res++;
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i = 0 ; i < t[cur].size() ; i++){
			if(visit[t[cur][i]]== 0){
				q.push(t[cur][i]);
				res++;
				visit[t[cur][i]] = 1;
			}
		}
		
	}
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int a,b;
		cin >> a >> b;
		
		g[a].push_back(b);
		rg[b].push_back(a);
	}
	
	for(int i = 1 ; i <= n ; i++){
		int total = 0 ;
		// 정방향과 역방향 모두를 BFS 돌아서 모든 노드를 방문한다면 +1
		total += bfs(i,g);
		total += bfs(i,rg);

		if(total == n-1){
			cnt++;
		}
	}
	
	cout << cnt << "\n";
	return 0;
}

